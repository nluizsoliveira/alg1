from project.modules.binary_handlers.file import File
from project.modules.indexers.primary_index import PrimaryIndex

class Orchestrator:
    def __init__(self, outputs_folder):
        self.records_file = File(outputs_folder + 'records_file')
        self.primary_index = PrimaryIndex(outputs_folder + 'primary_index')
        
    
    def call(self, operation, *args):
        OPERATIONS = {
            'ADD': self.add,
            'SEARCH': self.search,
            'REMOVE': self.remove,
            'EXIT': self.exit,
        }

        OPERATIONS[operation](*args)
        
        if operation != 'EXIT':
            print('-------------------')

    def add(self, id_, *args):
        ERROR_MSG = 'Erro ao inserir registro, chave primária duplicada'
        SUCCESS_MSG = 'Registro inserido'

        compressed_record = self.primary_index.search(id_)
        if compressed_record:
            print(ERROR_MSG)
        else:
            self.append_to_all_files(id_, *args)
            print(SUCCESS_MSG)

    def append_to_all_files(self, id_, *args):
        compressed_record = self.records_file.append_record((id_, *args))
        self.primary_index.append(id_, *compressed_record)
    
    def search(self, id_, title, author):
        if id_:
            self.search_by_id(id_)
        elif author: 
            print("TODO: Search for author")
    
    def search_by_id(self, id_):
        compressed_record = self.primary_index.search(id_)
        if compressed_record:
            id_, stream_size, pack_format, position = compressed_record
            record = self.records_file.read_at_position(position, stream_size, pack_format)
            self.print_found_record(*record)
        else:
            print('Não encontrado')
    
    @staticmethod
    def print_found_record(id_, title, author):
        print(f'{id_} - {title} - {author}')

    def remove(self, *args):
        print(f"TODO: remove {args}")
    
    def exit(self, *args):
        print(f"TODO: exit {args}")



    
