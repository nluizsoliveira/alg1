from project.binary_files_handlers.file import File
from project.indexers.primary_index import PrimaryIndex


def remove(id_ , title , author, record_file, primary_index):
    pass

def search( record_file, primary_index):
    

def exit(*kw):
    print('EXIT')


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








