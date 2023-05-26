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


id_ = 12
separator1 = b','
user = 'user'
password = 'password'
separator2 = b'|'

def get_struct_format(user, password):
    #int char char[len(user)] char char[len(password)] char
    return f"ic{'c'*len(user)}c{'c'*len(password)}c"
    
    
struct_format = get_struct_format(user, password) # 'iccccccccccccccc'

# binary_stream = struct.pack(struct_format, id_, separator1, *user, separator1, *password, separator2)
# unpacked = struct.unpack(struct_format)

binary_stream = pack('ici', 3 , b',', 2)
file_wb.write(binary_stream)
odio = file_rb.read()

treco = unpack('ici', odio)
print(treco)


