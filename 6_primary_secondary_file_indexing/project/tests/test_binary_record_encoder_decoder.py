from project.binary_files_handlers.binary_record_encoder_decoder import RecordEncoder, RecordDecoder

INPUT = ('c', 42, 'string')

print(" ========== TEST ENCODING ========= ")
print('\t INPUT:', INPUT)
stream_size, binary_stream, pack_format = RecordEncoder.encode(*INPUT)
print(f'\t encode(INPUT):\n'
      f'\t\tstream_size: {stream_size}\n'
      f'\t\tbinary_stream: {binary_stream}\n'
      f'\t\tpack_format: {pack_format}')


print(" ========== TEST READING ENCODED RECORDS ========= ")
file_wb = open("file", "wb")
file_wb.write(binary_stream)
file_wb.close()
print(f'\twrote: {binary_stream}')

file_rb = open("file", "rb")
recovered_binary_stream = file_rb.read(stream_size)
file_rb.close()
print(f'\trecovered: {recovered_binary_stream}')

print(" ========== TEST DECODING ENCODED RECORDS ========= ")
decoded = RecordDecoder.decode(pack_format, recovered_binary_stream)
print(f'\tdecoded: {decoded}')
