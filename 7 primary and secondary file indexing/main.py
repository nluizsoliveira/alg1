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
    return match.groupdict().values()

operation = ''
while operation != 'EXIT':
    operation, *args = parse_input(input())
    OPERATIONS[operation](*args)
