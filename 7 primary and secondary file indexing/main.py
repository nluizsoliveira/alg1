import re

def add(id_, title, author):
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
    OPERATIONS[operation](*args)
    
    
