from struct import pack, unpack, calcsize

file_wb = open("file", "wb")

# da para inferir o tipo 
# casta antes e pega o tipo
class StructElement():
    def __init__(self, type_, content):
        self.type_ = type_
        self.content = content 
        self.pack_format = self.get_pack_format()
        
    def get_pack_format(self):
        match self.type_:
            case 'int':
                return 'i'
            case 'char':
                return 'c'
            case 'str':
                return f'{len(self.content)}s'
                
class Struct():
    def __init__(self):
        self.contents = []
        self.pack_format = ''

    def push(self, element):
        self.contents.append(element.content)
        self.pack_format += element.pack_format
    
    def pack(self):
        return pack(self.pack_format, *self.contents)
        
# 12,username,password|
struct_contents = [
    ['int' , 12],
    ['char', b','],
    ['str' , bytes('username', encoding='utf-8')],
    ['char', b','],
    ['str' , bytes('password', encoding='utf-8')],
    ['char', b'|'],
]

struct = Struct()
for content in struct_contents:
    element = StructElement(*content)
    struct.push(element)

binary_stream = struct.pack() # works ?
print(struct.pack_format)
file_wb.write(binary_stream) # works ?

# file_rb = open("file", "rb")
# binary_stream_size = calcsize(struct.pack_format)
# binary_content = file_rb.read(binary_stream_size) #contains b''
# contents = unpack(struct.pack_format, binary_content)

print(contents)