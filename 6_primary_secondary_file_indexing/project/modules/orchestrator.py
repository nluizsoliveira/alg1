from project.modules.record_file_and_indexers.primary_index import PrimaryIndex
from project.modules.record_file_and_indexers.record_file import RecordFile
from project.modules.utils.casters import cast_numerical_elems_to_int

class Orchestrator:
    def __init__(self, folder, debug, debug_path=None):
        self.records_file = RecordFile(folder + 'records_file')
        self.primary_index = PrimaryIndex(folder + 'primary_index')
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

    def add(self, id_, *args):
        ERROR_MSG = 'Erro ao inserir registro, chave primária duplicada'
        SUCCESS_MSG = 'Registro inserido'
        id_, *args = cast_numerical_elems_to_int((id_, *args))
        compressed_record = self.primary_index.search(id_)
        if compressed_record:
            self.log(ERROR_MSG)
        else:
            self.append_to_all_files(id_, *args)
            self.log(SUCCESS_MSG)

    def append_to_all_files(self, id_, *args):
        compressed_record = self.records_file.append_record((id_, *args))
        self.primary_index.append(id_, *compressed_record)
    
    def search(self, id_, title, author):
        if id_:
            self.search_by_id(id_)
        elif author: 
            self.log("TODO: Search for author")
    
    def search_by_id(self, id_):
        if self.primary_index.search(id_):
            compressed_record = self.primary_index.search(id_)
            record = self.records_file.read_at_position(compressed_record)
            self.print_found_record(*record)
        else:
            self.log('Não encontrado')
    
    def print_found_record(self, id_, title, author, is_active):
        self.log(f'{id_} - {title} - {author}')

    # Logically removing on indexes
    def remove(self, id_, *args):
        if id_: 
            removed_RAM_record = self.primary_index.remove(id_)
            if removed_RAM_record:
                self.records_file.delete_record(*removed_RAM_record)
                self.log('Registro removido')
            else:
                self.log('Erro ao remover')
        
        else:
            self.log('Erro ao remover')
    
    def exit(self, *args):
        self.primary_index.update_file()



    
