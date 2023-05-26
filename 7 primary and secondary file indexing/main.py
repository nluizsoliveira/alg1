import re

def add(args):
    id_, title, author = args
    print(id_, title, author)

def remove(args):
    id_, _, _ = args
    print(id_)

def search(args):
    id_, _, _ = args
    print(id_)

def exit(args):
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
    
    operation = match.group('operation')
    id_ = match.group('id')
    title = match.group('title')
    author = match.group('author')
    
    return operation, (id_, title, author)

operation = ''
while operation != 'EXIT':
    operation, args = parse_input(input())
    OPERATIONS[operation](args)
