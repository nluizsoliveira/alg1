from os.path import exists, getsize
from project.modules.binary_handlers.file import File
from project.modules.binary_handlers.encoder_decoder import RecordEncoder, RecordDecoder

encode = RecordEncoder.encode
decode = RecordDecoder.decode
def __init__(self, path):
        self.path = path
        self.size = self.get_file_size()

class RecordFile(File):
    ACTIVE_FIELD = 1
    UNACTIVE_FIELD = 0

    def __init__(self, path):
        File.__init__(self, path)

    def append_record(self,fields):
        file = open(self.path, 'ab')
        appending_position = file.tell()

        stream_size, binary_stream, pack_format = encode(*fields, self.ACTIVE_FIELD)
        file.write(binary_stream)
        file.close()

        self.size = self.get_file_size()
        return appending_position, stream_size, pack_format
    
    def delete_record(self, position, stream_size, pack_format):
        IS_NOT_ACTIVE = 0

        flag_size, binary_flag, flag_format = encode(IS_NOT_ACTIVE)
        edit_position = position + stream_size - flag_size

        file = open(self.path, 'r+b')
        file.seek(edit_position)
        file.write(binary_flag)
        file.close()
    
    def read_at_position(self, encoded_record):
        id_, position, stream_size, pack_format = encoded_record
        file = open(self.path, 'rb')
        file.seek(position)
        encoded_stream = file.read(stream_size)
        fields = decode(pack_format, encoded_stream)
        file.close()

        return fields
