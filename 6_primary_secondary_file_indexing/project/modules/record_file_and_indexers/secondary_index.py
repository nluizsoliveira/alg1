
from project.modules.binary_handlers.file import File

# IMPROVE: Create Index class. Inherit SeconderyIndex and PrimaryIndex from Index
class SecondaryIndex():
    SEP_1 = '|'
    SEP_2 = ','
    SEP_3 = '\n'

    def __init__(self, path):  
        self.path = path
        self.file = File(self.path)
        self.RAM_index = self.get_RAM_index()

    def append(self, key, value):
        current_values = self.RAM_index.get(key)
        if current_values:
            current_values.append(value)
        else:
            self.RAM_index.update({key: [value]})


    def search(self, key):
        return self.RAM_index.get(key)
    
    def get_RAM_index(self):
        if self.file.size: 
            return self.read_RAM_index_from_file()
        else:
            return {}

    def read_RAM_index_from_file(self):
        buffer = self.file.read_entire_file()
        str_buffer = str(buffer, encoding='utf-8')
        index_lines = str_buffer.split()
        RAM_index = {}
        for line in index_line:
            key, values = line.split(self.SEP_1)
            ids = values.split(self.SEP_2)
            RAM_index.update({key: ids})
        return RAM_index
    
    def remove_key(self, key):
        return self.RAM_index.pop(key, None)
    
    def remove_value(self, key, value):
        values = self.RAM_index.get(key)
        values.remove(value)
        return value


"""
key|id_,id_,id .split('|')
"""