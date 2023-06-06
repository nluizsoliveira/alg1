from os.path import exists, getsize
from project.modules.binary_handlers.encoder_decoder import RecordEncoder, RecordDecoder
from project.modules.utils.casters import cast_numerical_elems_to_int
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
        return appending_position, stream_size, pack_format
    
    def read_at_position(self, encoded_record):
        print("tentou ler esse record comprimido", encoded_record)
        id_, position, stream_size, pack_format = cast_numerical_elems_to_int(encoded_record)
        print("decomprimiu: ", cast_numerical_elems_to_int(encoded_record))
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
