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

def get_binary_stream(*kwargs):
    

def add(id_, title, author):
    file_wb = open("file", "wb")
    binary_stream = pack(pack_format, id_, title, author)

    print(id_, title, author)
    
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
    regex = (r"(?P<operation>\w*)?"
             r"( id='(?P<id>[^']*)')?"
             r"( titulo='(?P<title>[^']*)')?
             r"( autor='(?P<author>[^']*)')?")
    match = re.search(regex, input_)
    return match.groupdict().values()

operation = ''
while operation != 'EXIT':
    operation, *args = parse_input(input())
    print('----------------------------------------------------------')
    OPERATIONS[operation](*args)
    

# id,user,password|id,user,password|...








