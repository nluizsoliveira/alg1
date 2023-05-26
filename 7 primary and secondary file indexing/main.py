import re
import io
import struct

# índice primário 
#   id: chave
# índice secundário
#   autor: chave
#   acoplamento fraco

# 3 arquivos: 
#   1. arquivo de fato
#   2. índice primário
#   3. índice secundário 

file_wb = open("file", "wb")


def add(id_, title, author):
    
    bytes_stream = struct.pack(
        'i', int(id_)
    )

    file_wb.write(bytes_stream)
    file_rb = open("file", "rb")
    
    treco = file_rb.read()
    
    resultado = struct.unpack('i', treco)
    print(resultado)
    # treco = struct.unpack('i', file_rb.read())
    
def remove(id_ , title , author):
    print(id_, title, author)

def search(id_, title, author):
    print(id_, title, author)

def exit(*kw):
    print('exit')

OPERATIONS = {
    'ADD': add,
    'SEARCH': remove,
    'REMOVE': search,
    'EXIT': exit,
}

def parse_input(input_):
    regex = r"(?P<operation>\w*)?( id='(?P<id>[^']*)')?( titulo='(?P<title>[^']*)')?( autor='(?P<author>[^']*)')?"
    match = re.search(regex, input_)
    return match.groupdict().values()

operation = ''
while operation != 'EXIT':
    operation, *args = parse_input(input())
    print('----------------------------------------------------------')
    OPERATIONS[operation](*args)
    
    
    
----------------------------------------------------------
from struct import pack, unpack, calcsize
import sys
file_wb = open("file", "wb")
file_rb = open("file", "rb")


# id,user,password|id,user,password|...

from struct import pack, unpack, calcsize

file_wb = open("file", "wb")

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
binary_content = file_rb.read()
content = unpack(pack_format, binary_content)

print(content)







