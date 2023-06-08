from project.modules.record_file_and_indexers.primary_index import PrimaryIndex
from project.modules.record_file_and_indexers.secondary_index import SecondaryIndex
from project.modules.record_file_and_indexers.record_file import RecordFile
from project.modules.utils.casters import cast_numerical_elems_to_int

class Orchestrator:
    def __init__(self, folder):
        self.records_file = RecordFile(folder + 'records_file')
        self.primary_index = PrimaryIndex(folder + 'primary_index')
        self.secondary_index = SecondaryIndex(folder + 'secondary_index')

    def call(self, operation, *args):
        OPERATIONS = {
            'ADD': self.add,
            'SEARCH': self.search,
            'REMOVE': self.remove,
            'EXIT': self.exit,
        }

        if operation != 'EXIT':
            print('----------------------------------------------------------')
        
        OPERATIONS[operation](*args)

    def add(self, id_, title, author):
        ERROR_MSG = 'Erro ao inserir registro, chave primária duplicada'
        SUCCESS_MSG = 'Registro inserido'
        id_ = int(id_)
        if self.primary_index.search(id_):
            print(ERROR_MSG)
        else:
            self.append_to_all_files(id_, title, author)
            print(SUCCESS_MSG)

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
            print('Não encontrado')
    
    def search_by_author(self, author):
        ids = self.secondary_index.search(author)
        if ids:
            for id in ids:
                self.search_by_id(id)
        else:
            print('Não encontrado')
    
    def print_found_record(self, id_, title, author, is_active):
        print(f'{id_} - {title} - {author}')

    # Logically removing on indexes
    def remove(self, id_, title, author):
        if id_: 
            self.remove_by_id(id_)
        elif author:
            self.remove_by_author(author)
        else:
            print('Erro ao remover')
    
    def remove_by_id(self, id_):
        compressed_removed_RAM_record = self.primary_index.remove(id_)
        if compressed_removed_RAM_record:
            removed_record = self.records_file.delete_record(*compressed_removed_RAM_record)
            author = removed_record[2]
            self.secondary_index.remove_value(key=author, value=id_)
            self.records_file.delete_record(*compressed_removed_RAM_record)
            print('Registro removido')
        else:
            print('Erro ao remover')
    
    def remove_by_author(self, author):
        removed_ids = self.secondary_index.remove_key(author)
        if removed_ids:
            for id_ in removed_ids:
                print('Registro removido')
                self.primary_index.remove(id_)
        else:
            print('Erro ao remover')

    def exit(self, *args):
        self.primary_index.update_file()
        self.secondary_index.update_file()



    
