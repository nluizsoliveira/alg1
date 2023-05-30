from project.modules.indexers.primary_index import PrimaryIndex
from project.modules.binary_handlers.file import File


records_file = File('output_files/records_file')
primary_index = PrimaryIndex('output_files/primary_index')

print(" ========== TEST get_RAM_index ========= ")
RAM_index = primary_index.get_RAM_index()

print('\t test 1: get_RAM_index empty case')
print(f'\t\t ■ RAM_index = {RAM_index}')

print('\t test 2: get_RAM_index after inserting 1 record')
record_input = ('1', 'title', 'author')
id_ = record_input[0]
print(f'\t\t 1. record_input: {record_input}')

compressed_record = records_file.append_record(record_input)
print(f'\t\t 2. compressed_record: {compressed_record}')

print("========== TEST append ========= ")
out = primary_index.append(id_, *compressed_record)
print(f'\t\t 3. self.file: {primary_index.file.read_entire_file()}')
print(f'\t\t ■ RAM_index: {primary_index.RAM_index}')


print(" ========== TEST search ========= ")
print('\t test 3: search existant string id')
result1 = primary_index.search(id_)
print(f'\t\t ■ RAM_index: {result1}')

print('\t test 4: search existant int id')
result1 = primary_index.search(int(id_))
print(f'\t\t ■ RAM_index: {result1}')


print('\t test 5: search not existent id')
result1 = primary_index.search(999)
print(f'\t\t ■ RAM_index: {result1}')