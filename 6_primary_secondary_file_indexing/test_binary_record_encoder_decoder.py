from binary_record_encoder_decoder import RecordEncoder, RecordDecoder


stream_size, binary_stream, pack_format = RecordEncoder.encode('c', 42, 'string')

file_wb = open("file", "wb")
file_wb.write(binary_stream)
file_wb.close()

file_rb = open("file", "rb")
recovered_binary_stream = file_rb.read(stream_size)
file_rb.close()

decoded = RecordDecoder.decode(pack_format, recovered_binary_stream)
print(decoded)
