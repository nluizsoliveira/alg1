import re

def parse_input(input_):
    regex = (r"(?P<operation>\w*)?"
             r"( id='(?P<id>[^']*)')?"
             r"( titulo='(?P<title>[^']*)')?"
             r"( autor='(?P<author>[^']*)')?")
    match = re.search(regex, input_)
    operation, id_, title, author = match.groupdict().values()
    if id_:
        id_ = int(id_)
    return operation, id_, title, author
