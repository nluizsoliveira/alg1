from project.modules.record_file_and_indexers.primary_index import PrimaryIndex
from project.modules.record_file_and_indexers.secondary_index import SecondaryIndex
from project.modules.record_file_and_indexers.record_file import RecordFile
from project.modules.utils.casters import cast_numerical_elems_to_int

class Orchestrator:
    def __init__(self, folder, debug, debug_path=None):
        self.records_file = RecordFile(folder + 'records_file')
        self.primary_index = PrimaryIndex(folder + 'primary_index')
        self.secondary_index = SecondaryIndex(folder + 'secondary_index')
        self.debug = debug
        self.debug_path = debug_path

    def call(self, operation, *args):
        OPERATIONS = {
            'ADD': self.add,
            'SEARCH': self.search,
            'REMOVE': self.remove,
            'EXIT': self.exit,
        }

        if operation != 'EXIT':
            self.log('----------------------------------------------------------')
        
        OPERATIONS[operation](*args)
    
    def log(self, string):
        if not self.debug: 
            print(string)
        else:
            dump_file = open(self.debug_path, 'a')
            dump_file.write(string + '\n')

    def add(self, id_, title, author):
        ERROR_MSG = 'Erro ao inserir registro, chave primária duplicada'
        SUCCESS_MSG = 'Registro inserido'
        id_ = int(id_)
        if self.primary_index.search(id_):
            self.log(ERROR_MSG)
        else:
            self.append_to_all_files(id_, title, author)
            self.log(SUCCESS_MSG)

    def append_to_all_files(self, id_, title, author):
        compressed_record = self.records_file.append_record((id_, title, author))
        self.primary_index.append(id_, *compressed_record)
        self.secondary_index.append(author, id_)
    
    def search(self, id_, title, author):
        if id_:
            self.search_by_id(id_)
        elif author: 
            self.search_by_author(author)
    
    def search_by_id(self, id_):
        if self.primary_index.search(id_):
            compressed_record = self.primary_index.search(id_)
            record = self.records_file.read_at_position(compressed_record)
            self.print_found_record(*record)
        else:
            self.log('Não encontrado')
    
    def search_by_author(self, author):
        ids = self.secondary_index.search(author)
        if ids:
            for id in ids:
                self.search_by_id(id)
        else:
            self.log('Não encontrado')
    
    def print_found_record(self, id_, title, author, is_active):
        self.log(f'{id_} - {title} - {author}')

    # Logically removing on indexes
    def remove(self, id_, title, author):
        if id_: 
            self.remove_by_id(id_)
        elif author:
            self.remove_by_author(author)
        else:
            self.log('Erro ao remover')
    
    def remove_by_id(self, id_):
        compressed_removed_RAM_record = self.primary_index.remove(id_)
        if compressed_removed_RAM_record:
            removed_record = self.records_file.delete_record(*compressed_removed_RAM_record)
            author = removed_record[2]
            self.secondary_index.remove_value(key=author, value=id_)
            self.log('Registro removido')
        else:
            self.log('Erro ao remover')
    
    def remove_by_author(self, author):
        removed_ids = self.secondary_index.remove_key(author)
        if removed_ids:
            for id_ in removed_ids:
                self.log('Registro removido')
                self.primary_index.remove(id_)
        else:
            self.log('Erro ao remover')

    def exit(self, *args):
        self.primary_index.update_file()



    
