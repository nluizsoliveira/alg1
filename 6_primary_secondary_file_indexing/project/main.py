import re
from project.binary_files_handlers.file import File
from project.indexers.primary_index import PrimaryIndex

def add(id_, title, author, record_file, primary_index):
    record = primary_index.search(id_)
    if record:
        print('Erro ao inserir registro, chave primária duplicada')
    else:
        stream_size, pack_format, append_position = record_file.append_record((id_, title, author))
        primary_index.append(id_, stream_size, pack_format, append_position)
        print('Registro inserido')

def remove(id_ , title , author, record_file, primary_index):
    pass

def search(id_, title, author, record_file, primary_index):
    if id_:
        record = primary_index.search(id_)
        if record:
            id_, stream_size, pack_format, position = record
            position = int(position)
            stream_size = int(stream_size)
            id_, title, author = record_file.read_at_position(position, stream_size, pack_format)
            print(f'{id_} - {title} - {author}')
        else:
            print('Não encontrado')

    elif author: 
        pass # record = secondary_index.search(author)

def exit(*kw):
    print('EXIT')

OPERATIONS = {
    'ADD': add,
    'SEARCH': search,
    'REMOVE': remove,
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
primary_index = PrimaryIndex('primary_index')

operation = ''
while operation != 'EXIT':
    operation, id_, title, author = parse_input(input())
    if id_:
        id = int(id_)
    print('----------------------------------------------------------')
    OPERATIONS[operation](id_,title, author, record_file, primary_index)
    

# id,user,password|id,user,password|...








