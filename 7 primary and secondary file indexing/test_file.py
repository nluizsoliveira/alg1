from file import File

record_file = File('file')

def test_append_record():
    print('Test Append Record')
    records = [
        (int('5'), 'The Diary of a Young Girl', 'Anne Frank'),
        (int('8'), 'The Fault in Our Stars', 'John Green'),
        (int('14'), 'Looking for Alaska', 'John Green'),
    ]
    for fields in records:
        print('\t appending: ', fields)
        stream_size, pack_format = record_file.append_record(fields)
        print('\t appended:  ', stream_size, pack_format)
        print('\t-----')

def test_read_at_position():
    print('Test Read at position')
    sizes = [39, 36, 32]
    formats = ['i25s10s', 'i22s10s', 'i18s10s']
    start_positions = [0, 39, 39+36] # will be get from primary index
    
    for size, format, position in zip(sizes, formats, start_positions):
        print('\trecovering: ', position, size, format)
        fields = record_file.read_at_position(position, size, format)
        print('\trecovered: ', fields)
        print('\t-----')

test_append_record()
test_read_at_position()
