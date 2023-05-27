import re
from file import File
from primary_index import PrimaryIndex

from binary_record_encoder_decoder import RecordEncoder, RecordDecoder
encode = RecordEncoder.encode
decode = RecordDecoder.decode

#  last_byteoffset + last_size;
# Baixa indice primário
# Parseia indice primario 
# Procura por id = id_
# Se existir, imprime erro
# Se não existir, 
def add(id_, title, author, record_file):
    record_file.write(int(id_), title, author)

    print('Registro inserido')

    
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
             r"( titulo='(?P<title>[^']*)')?"
             r"( autor='(?P<author>[^']*)')?")
    match = re.search(regex, input_)
    return match.groupdict().values()

record_file = File('file')
    
operation = ''
while operation != 'EXIT':
    operation, *args = parse_input(input())
    print('----------------------------------------------------------')
    OPERATIONS[operation](*args, record_file)
    

# id,user,password|id,user,password|...








