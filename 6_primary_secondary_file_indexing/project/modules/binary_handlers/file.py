from os.path import exists, getsize
from project.modules.binary_handlers.encoder_decoder import RecordEncoder, RecordDecoder

encode = RecordEncoder.encode
decode = RecordDecoder.decode

class File():
    def __init__(self, path):
        self.path = path
        self.size = self.get_file_size()
    
    def append_record(self,fields):
        file = open(self.path, 'ab')
        appending_position = file.tell()

        stream_size, binary_stream, pack_format = encode(*fields)
        file.write(binary_stream)
        file.close()

        self.size = self.get_file_size()
        return stream_size, pack_format, appending_position
    
    def read_at_position(self, position, stream_size, pack_format):
        file = open(self.path, 'rb')
        file.seek(position)
        encoded_stream = file.read(stream_size)
        fields = decode(pack_format, encoded_stream)
        file.close()

        return fields

    def read_entire_file(self):
        file = open(self.path, 'rb')
        buffer = file.read()
        file.close()
        return buffer
    
    def get_file_size(self):
        return getsize(self.path) if exists(self.path) else None
