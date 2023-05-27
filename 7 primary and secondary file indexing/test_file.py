from file import File

record_file = File('file')

def test_append_records():
    print('Test Append')
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
    print('Test Read Records')
    for id_, size, format, insert_position in appended_records: 
        print('\trecovering: ', insert_position, size, format)
        fields = record_file.read_at_position(insert_position, size, format)
        print('\trecovered: ', fields)

# appended_records = test_append_records()
# test_read_records(appended_records)
