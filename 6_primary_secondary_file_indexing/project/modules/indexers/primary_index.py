from project.modules.binary_handlers.file import File

class PrimaryIndex():
    SEP_1 = ','
    SEP_2 = '\n'

    def __init__(self, path):  
        self.path = path
        self.file = File(self.path)
        self.RAM_index = self.get_RAM_index()
    
    # Doubt: Should appending/deleting be bufferized? performance x reliability to unexpected interrupts 
    def append(self, id_, stream_size, pack_format, position):
        is_duplicate = self.search(id_)
        if is_duplicate:
            return -1
        index_line = self.get_index_line(id_, stream_size, pack_format, position)
        id_, position, stream_size = self.cast_args_to_int((id_, position, stream_size))
        self.file.append_record(index_line)
        self.RAM_index.update({id_: (stream_size, pack_format, position)})
        return 1

    def get_index_line(self, id_, stream_size, pack_format, start_position):
        return f'{id_}{self.SEP_1}{stream_size}{self.SEP_1}{pack_format}{self.SEP_1}{start_position}{self.SEP_2}'

    def search(self, id_):
        id_ = int(id_)
        compressed_values = self.RAM_index.get(id_)
        if compressed_values: 
            stream_size, pack_format, position = compressed_values
            stream_size, position = self.cast_args_to_int((stream_size, position))
            return id_, stream_size, pack_format, position
        return None
    
    @staticmethod
    def cast_args_to_int(args):
        return (int(arg) for arg in args)
        
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
            int(id_): (stream_size, pack_format, start_position) 
            for id_, stream_size, pack_format, start_position in index_list
        }

        return RAM_index
    