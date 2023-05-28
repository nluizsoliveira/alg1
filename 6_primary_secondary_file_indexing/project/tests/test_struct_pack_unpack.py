from struct import pack, unpack, calcsize

integer = 42
char    = b'c'
string  = bytes('string', encoding='utf-8')
pack_format = 'ic6s'

binary_stream = pack(pack_format, integer, char, string)

file_wb = open("file", "wb")
file_wb.write(binary_stream)
file_wb.close()

file_rb = open("file", "rb")
binary_content = file_rb.read(calcsize(pack_format))

integer, byte_char, byte_string = unpack(pack_format, binary_content)

print(integer)
print(str(byte_char, encoding='utf-8'))
print(str(byte_string, encoding='utf-8'))

