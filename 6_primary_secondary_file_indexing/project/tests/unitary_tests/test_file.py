from project.modules.binary_handlers.file import File

record_file = File('project/tests/unitary_tests/output_files/records_file')

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
    

def test_read_records(appended_records):
    print(" ========== TEST READ RECORDS ========= ")
    for id_, insert_position, size, format in appended_records: 
        print('\trecovering: ', insert_position, size, format)
        fields = record_file.read_at_position((insert_position, size, format))
        print('\trecovered: ', fields)

def test_read_entire_file():
    print(" ========== TEST READ ENTIRE FILE ========= ")
    buffer = record_file.read_entire_file()
    print(buffer)
    return buffer

appended_records = test_append_records()
test_read_records(appended_records)
test_read_entire_file()

