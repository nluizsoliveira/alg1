from primary_index import PrimaryIndex
from test_file import test_append_records


primary_index = PrimaryIndex('primary_index')
appended_records = test_append_records()

for id_, stream_size, pack_format, insert_position in appended_records:
    primary_index.append(id_, pack_format, insert_position)

print(" ========== TEST PRIMARY INDEX.SEARCH ========= ")

primary_index.search('5') # finds
primary_index.search(5)   # does not find