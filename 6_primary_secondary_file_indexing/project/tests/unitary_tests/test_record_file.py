from project.modules.record_file_and_indexers.record_file import RecordFile

record_file = RecordFile('project/tests/unitary_tests/output_files/records_file')

def test_append_records():
    print(" ========== TEST APPEND RECORDS ========= ")

    records = [
        (int('5'), 'The Diary of a Young Girl', 'Anne Frank'),
        (int('8'), 'The Fault in Our Stars', 'John Green'),
        (int('14'), 'Looking for Alaska', 'John Green'),
    ]

    print('\t appending: ', records)
    appended_records = []
    for fields in records: 
        appended = record_file.append_record(fields)
        appended_records.append((fields[0], *appended))
    print('\t appended: ', appended_records)

    return appended_records
    
# BUG: RecordFile.read_at_position returns 3 values
# while PrimaryIndex.read_at_position returns 4 values

def test_read_records(appended_records):
    print(" ========== TEST READ RECORDS ========= ")
    for id_, insert_position, size, format in appended_records: 
        print('\trecovering: ', insert_position, size, format)
        fields = record_file.read_at_position((id_, insert_position, size, format))
        print('\trecovered: ', fields)

def test_read_entire_file():
    print(" ========== TEST READ ENTIRE FILE ========= ")
    buffer = record_file.read_entire_file()
    print(buffer)
    return buffer

def test_delete_record(position, stream_size, pack_format):
    print(" ========== TEST DELETE RECORD ========= ")
    buffer = record_file.read_entire_file()
    print('before deleting record at position', position, buffer)
    record_file.delete_record(position, stream_size, pack_format)
    buffer = record_file.read_entire_file()
    print('after deleting record at position', position, buffer)

appended_records = test_append_records()
test_read_records(appended_records)
test_read_entire_file()

id_, appending_position, stream_size, pack_format = appended_records[0]
appending_position = int(appending_position)
stream_size = int(stream_size)
test_delete_record(appending_position, stream_size, pack_format)
