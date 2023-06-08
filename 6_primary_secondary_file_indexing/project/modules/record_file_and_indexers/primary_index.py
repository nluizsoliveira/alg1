from project.modules.binary_handlers.file import File

# Implementation Details: Read README.md
class PrimaryIndex():
    SEP_1 = ','
    SEP_2 = '\n'

    def __init__(self, path):  
        self.path = path
        self.file = File(self.path)
        self.RAM_index = self.get_RAM_index()

    def append(self, id_, position, stream_size, pack_format):
        is_duplicate = self.search(id_)
        if is_duplicate:
            return None
        index_line = self.get_index_line(id_, position, stream_size, pack_format)
        id_, position, stream_size = self.cast_args_to_int((id_, position, stream_size))

        appended_entry = {id_: (position, stream_size, pack_format)}
        self.RAM_index.update(appended_entry)
        
        return appended_entry # warning. This is not a shallow copy. See https://onlinegdb.com/CDpj0Zz0O 

    def get_index_line(self, id_, start_position, stream_size, pack_format):
        return f'{id_}{self.SEP_1}{start_position}{self.SEP_1}{stream_size}{self.SEP_1}{pack_format}{self.SEP_2}'

    def search(self, id_):
        id_ = int(id_)
        compressed_record = self.RAM_index.get(id_)
        if compressed_record: 
            position, stream_size, pack_format = compressed_record
            position, stream_size = self.cast_args_to_int((position, stream_size))
            return id_, position, stream_size, pack_format
        return None
    
    @staticmethod
    def cast_args_to_int(args):
        return (int(arg) for arg in args)
        
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
            int(id_): (start_position, stream_size, pack_format)
            for id_, start_position, stream_size, pack_format
            in index_list
        }

        return RAM_index
    
    def remove(self, id_):
        compressed_record = self.search(id_)
        if compressed_record:
            self.RAM_index.pop(id_)
            return compressed_record
        return None

    # TO IMPROVE: make a method in File() that automatically overrides from buffer
    # and updates size. This should not be index responsibility but file itself.
    def update_file(self):
        buffer = ""
        active_records =  len(self.RAM_index)
        file = open(self.path, 'w')
        for id_, compressed_record in self.RAM_index.items():
            position, stream_size, pack_format = compressed_record
            line = self.get_index_line(id_, position, stream_size, pack_format)
            buffer += line
        file.write(buffer)
        file.close()

        self.file.size = active_records

                
