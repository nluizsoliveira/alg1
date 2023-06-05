from os.path import exists, getsize
from project.modules.binary_handlers.encoder_decoder import RecordEncoder, RecordDecoder

encode = RecordEncoder.encode
decode = RecordDecoder.decode

class File():
    def __init__(self, path):
        self.path = path
        self.size = self.get_file_size()
    
    def append_record(self,fields):
        IS_ACTIVE = 1
        file = open(self.path, 'ab')
        appending_position = file.tell()

        stream_size, binary_stream, pack_format = encode(*fields, IS_ACTIVE)
        file.write(binary_stream)
        file.close()

        self.size = self.get_file_size()
        return appending_position, stream_size, pack_format
    
    def read_at_position(self, position, stream_size, pack_format):
        file = open(self.path, 'rb')
        file.seek(position)
        encoded_stream = file.read(stream_size)
        fields = decode(pack_format, encoded_stream)
        file.close()

        return fields
    
    def delete_record(self, position, stream_size, pack_format):
        IS_NOT_ACTIVE = 0

        flag_size, binary_flag, flag_format = encode(IS_NOT_ACTIVE)
        edit_position = position + stream_size - flag_size

        file = open(self.path, 'r+b')
        file.seek(edit_position)
        file.write(binary_flag)
        file.close()

    def read_entire_file(self):
        file = open(self.path, 'rb')
        buffer = file.read()
        file.close()
        return buffer
    
    def get_file_size(self):
        return getsize(self.path) if exists(self.path) else None
