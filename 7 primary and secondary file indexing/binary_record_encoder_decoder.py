from struct import pack, unpack, calcsize

class FieldEncoder():
    @staticmethod
    def get_bytes(type_, field):
        if type_ == int:
            return field
        elif type_ == str:
            return bytes(field, encoding='utf-8')

    @staticmethod
    def get_pack_format(type_, field):
        if type_ == int:
            return 'i'
        elif type_ == str and len(field) == 1:
            return 'c'
        elif type_ == str:
            return f'{len(field)}s'
    
    @staticmethod
    def encode(field):
        type_ = type(field)
        bytes = FieldEncoder.get_bytes(type_, field)
        pack_format = FieldEncoder.get_pack_format(type_,field)

        return bytes, pack_format

class FieldDecoder():
    @staticmethod
    def decode(field):
        type_ = type(field)
        if type_ == int:
            return field
        elif type_ == bytes:
            return str(field, encoding='utf-8')

class RecordEncoder():
    @staticmethod
    def encode(*fields):
            total_pack_format, total_bytes = RecordEncoder.aglutinate_fields(fields)

            stream_size = calcsize(total_pack_format)
            binary_stream = pack(total_pack_format, *total_bytes)
            
            return stream_size, binary_stream, total_pack_format
    
    @staticmethod
    def aglutinate_fields(fields):
        total_pack_format = ''
        total_bytes = []

        for field in fields:
            bytes, pack_format = FieldEncoder.encode(field)
            total_bytes.append(bytes)
            total_pack_format += pack_format
        
        return total_pack_format, total_bytes

class RecordDecoder():
    @staticmethod
    def decode(pack_format, binary_stream):
        binary_fields = unpack(pack_format, binary_stream)
        decoded_records = [FieldDecoder.decode(field) for field in binary_fields]
        return decoded_records
