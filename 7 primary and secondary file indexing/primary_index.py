from file import File

# id, start_position, pack_format
class PrimaryIndex():
    SEP_1 = ','
    SEP_2 = '\n'

    def __init__(self, path): # IMPROVE: Bufferize. Only write when exit. 
        self.path = path
        self.file = File(self.path)
        self.RAM_index = None
    
    def append(self, id_, pack_format, record_file_start_position):
        index_line = self.get_index_line(id_, pack_format, record_file_start_position)
        self.file.append_record(index_line)

    def get_index_line(self, id_, pack_format, start_position):
        return f'{id_}{self.SEP_1}{pack_format}{self.SEP_1}{start_position}{self.SEP_2}'

    def search(self, id_):
        if not self.RAM_index: 
            self.RAM_index = self.get_RAM_index()
        print(self.RAM_index)
    
    def get_RAM_index(self): 
        buffer = self.file.read_entire_file()
        str_buffer = str(buffer, encoding='utf-8')
        index_lines = str_buffer.split()
        index_list = [line.split(',') for line in index_lines]
        RAM_index = {id_: (pack_format, start_position) for id_, pack_format, start_position in index_list}

        return RAM_index
        