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
    def get_binary_field(field):
        type_ = type(field)
        bytes = FieldEncoder.get_bytes(type_, field)
        pack_format = FieldEncoder.get_pack_format(type_,field)

        return bytes, pack_format

class RecordEncoder():
    @staticmethod
    def get_binary_record(*fields):
            total_pack_format, total_bytes = RecordEncoder.aglutinate_fields(fields)

            stream_size = calcsize(total_pack_format)
            binary_stream = pack(total_pack_format, *total_bytes)
            
            return stream_size, binary_stream, total_pack_format
    
    @staticmethod
    def aglutinate_fields(fields):
        total_pack_format = ''
        total_bytes = []

        for field in fields:
            bytes, pack_format = FieldEncoder.get_binary_field(field)
            total_bytes.append(bytes)
            total_pack_format += pack_format
        
        return total_pack_format, total_bytes


stream_size, binary_stream, pack_format = RecordEncoder.get_binary_record('c', 42, 'string')

file_wb = open("file", "wb")
file_wb.write(binary_stream)
file_wb.close()


file_rb = open("file", "rb")
binary_recovered_content = file_rb.read(stream_size)
decoded = unpack(pack_format, binary_recovered_content)

print(decoded)
file_rb.close()


teste= '''
integer, byte_char, byte_string = unpack(pack_format, binary_field)

print(integer)
print(str(byte_char, encoding='utf-8'))
print(str(byte_string, encoding='utf-8'))
'''