from file import File

# id, start_position, pack_format
class PrimaryIndex():
    SEP_1 = ','
    SEP_2 = '\n'

    def __init__(self, path):  
        self.path = path
        self.file = File(self.path)
        self.RAM_index = None
    
    # Doubt: Should appending/deleting be bufferized? performance x reliability to unexpected interrupts 
    def append(self, id_, pack_format, record_file_start_position):
        record = self.search(id_)
        if record:
            print('Erro ao inserir registro, chave primária duplicada')
        else:
            index_line = self.get_index_line(id_, pack_format, record_file_start_position)
            self.file.append_record(index_line)
            self.RAM_index.update({id_: (pack_format, record_file_start_position)})

    def get_index_line(self, id_, pack_format, start_position):
        return f'{id_}{self.SEP_1}{pack_format}{self.SEP_1}{start_position}{self.SEP_2}'

    def search(self, id_):
        if not self.RAM_index:
            self.RAM_index = self.get_RAM_index()
        values = self.RAM_index.get(id_)
        if values: 
            return id_, *values
        return None
        
    # I'm using a dict/hashtable which has O(1) lookup, no sorting needed
    def get_RAM_index(self):
        if self.file.size: 
            return self.read_RAM_index_from_file()
        else:
            return {}

    def read_RAM_index_from_file(self):
        buffer = self.file.read_entire_file()
        str_buffer = str(buffer, encoding='utf-8')
        index_lines = str_buffer.split()
        index_list = [line.split(',') for line in index_lines]

        RAM_index = {
            int(id_): (pack_format, start_position) 
            for id_, pack_format, start_position in index_list
        }

        return RAM_index
    

situacoes = '''
1. vai adicionar:
    (a) procura(chave)
    1.1 v existe(chave)
        não adiciona ao final
    1.2 ! existe(chave)
        adiciona ao final
        adiciona chave ao RAM_INDEX

a. procura(chave)
    a.0 verifica se existe RAM_INDEX
    a.1 v existe RAM_INDEX 
        procura(RAM_INDEX)
    a.2 ? não existe RAM_INDEX
        a.1.0: verificar se records_file existe.
        a.2.2: ? records_file nem existe ainda.
            1. Criar um {}. 
            2. Retorn None
        a.2.1: ? records_file está cheio. 
            1. Ler records_file
            2. criar RAM_INDEX(records_file)
            3. procura(RAM_INDEX). 
'''