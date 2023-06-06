from project.modules.record_file_and_indexers.primary_index import PrimaryIndex
from project.modules.record_file_and_indexers.record_file import RecordFile


records_file = RecordFile('project/tests/unitary_tests/output_files/records_file')
primary_index = PrimaryIndex('project/tests/unitary_tests/output_files/primary_index')

print(" ========== TEST get_RAM_index ========= ")
RAM_index = primary_index.get_RAM_index()

print('\t test 1: get_RAM_index empty case')
print(f'\t\t ■ RAM_index = {RAM_index}')

print(" ========== TEST READ_ENTIRE FILE ========= ")
record_input_1 = ('1', 'title', 'author')
record_input_2 = ('2', 'title2', 'author2')

print(f'\t 1. appending 2 records on records_file')
print(f'\t\t record_input: {record_input_1}')
print(f'\t\t record_input: {record_input_2}')

id_1 = record_input_1[0]
id_2 = record_input_2[0]


compressed_record_1 = records_file.append_record(record_input_1)
compressed_record_2 = records_file.append_record(record_input_2)

print(f'\t\t compressed_record 1: {compressed_record_1}')
print(f'\t\t compressed_record 2: {compressed_record_2}')


primary_index.append(id_1, *compressed_record_1)
primary_index.append(id_2, *compressed_record_2)

print(f'\t 2. File after appending 2 records:\n\t\t {primary_index.file.read_entire_file()}')

print("========== TEST  get_RAM_index ========= ")
print(f'\t 1. After inserting 2 records')
print(f'\t\t ■ RAM_index: {primary_index.RAM_index}')


print(" ========== TEST search ========= ")
print('\t 1: search existant string id')
result1 = primary_index.search(id_1)
print(f'\t\t ■ search(1): {result1}')

result2 = primary_index.search(id_2)
print(f'\t\t ■ search(2): {result2}')

print('\t 2: search not existent id')
result1 = primary_index.search(999)
print(f'\t\t ■ search(999): {result1}')

print(" ========== TEST delete ========= ")
print('\t 1: delete unexistant id')
result1 = primary_index.delete(999)