from struct import pack, unpack, calcsize

class FieldEncodePreparer():
    @staticmethod
    def get_encodable_field(type_, field):
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
    def prepare_encode(field):
        type_ = type(field)
        encodable_field = FieldEncodePreparer.get_encodable_field(type_, field)
        pack_format = FieldEncodePreparer.get_pack_format(type_,field)

        return encodable_field, pack_format

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
            all_packs_format, all_encodable_fields = RecordEncoder.prepare_all_encodes(fields)

            stream_size = calcsize(all_packs_format)
            binary_stream = pack(all_packs_format, *all_encodable_fields)
            
            return stream_size, binary_stream, all_packs_format
    
    @staticmethod
    def prepare_all_encodes(fields):
        all_packs_format = ''
        all_encodable_fields = []

        for field in fields:
            encodable_field, pack_format = FieldEncodePreparer.prepare_encode(field)
            all_encodable_fields.append(encodable_field)
            all_packs_format += pack_format
        
        return all_packs_format, all_encodable_fields

class RecordDecoder():
    @staticmethod
    def decode(pack_format, binary_stream):
        binary_fields = unpack(pack_format, binary_stream)
        decoded_records = [FieldDecoder.decode(field) for field in binary_fields]
        return decoded_records
