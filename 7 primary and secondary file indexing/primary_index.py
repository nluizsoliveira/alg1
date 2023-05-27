from file import File

# id, start_position, pack_format
class PrimaryIndex():
    SEP_1 = ','
    SEP_2 = '\n'

    def __init__(self, path): # IMPROVE: Bufferize. Only write when exit. 
        self.path = path
        self.file = None
    
    def append(self, id_, pack_format, record_file_start_position):
        if not self.file: # WRONG: or last one was a delete
            self.file = File(self.path)
        index_line = self.get_index_line(id_, pack_format, record_file_start_position)
        self.file.append_record(index_line)

    def get_index_line(self, id_, pack_format, start_position):
        return f'{id_}{self.SEP_1}{pack_format}{self.SEP_1}{start_position}{self.SEP_2}'