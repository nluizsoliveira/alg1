## **On running the project**

I'm using `Makefile` diretifs to automate preparing, running an testing the project. 
As makefile diretifs call `bash` scripts, it's necessarry to run it in a `linux/GNU-like` environment. 

### Testing 
```bash
make test 
```
Calls `make_scripts/test.sh`, which: 

0. For each `.in` file in `project/tests/integration_tests/output_files/`: 
    1. Run `main.py` with `.in` as input, dumps the output into `.returned file`
    2. Compares `.returned` to `.out` files. 
    3. Print (v) success if they're identical. If they're not, print (x) fail

### Prepare running
```bash
make all
```

Cleans temporary output files that need to be excluded before running `main.py`. 

### Running
```bash
make run
```

Runs the `main.py`.

### Zip
```bash
make zip
```

Cleans temporary output files and zips folders/files into a `trab.zip` file. 

## Project Structure
I've created auxiliary files/methods for binary files operating and encoding/decoding. 

They're available at:
1. Encoding/Decoding: `project/modules/binary_handlers/encoder_decoder`
2. Binary File Handling: `project/modules/binary_handlers/file`

Both `RecordFile`, `PrimaryIndex` and `SecondaryIndex` are available at `project/modules/record_file_and_indexers/`. 


1. `RecordFile` inherits from `File`, but have additional features for handling active/unactive records (Necessary for deleting).
2. `PrimaryIndex` and `SecondaryIndex` are composed by their own `File` and `RAM_index`.
3. `Orchestrator`, available at `project/orchestrator.py` is the one actually performing operations and updating files and indexes. 

## Implementation Details

### 1. **Index updates are handled through RAM_index objects.** 

`Index` files are updated only when `Index.update_file()` is called. 
It's up to the parent class composing Index (ex: `Orchestrator`)
to decide when updating. (ex: after `EXIT` signals the end of the operations batch)

### 2. **RAM_index is a `<Dictionary>`, not a `<List>`.** 

Reason: In a scenery of non-static content (many insertions/deletions)
Dict operations are faster than List operations, even when sorting/BinSearching.  
See https://stackoverflow.com/a/15486389/13982165


### 3. **Primary Index Entries are `(id_,position,stream_size,pack_format)` instead of `(id, byte_offset)`.**

Reason: Python is not a typed language. It handles binary writing/reading 
through `<struct>` module, which encodes/decodes content trough 
`packing`, `unpacking`, `pack_format` and `pack_size`.

#### **Example: encode('c', 42, 'string'), write it on RecordFile, store it on PrimaryIndex, retreive it from PrimaryIndex, and decode it**

```python
# ENCODING RECORD ON <RecordFile>. WRITING BINARY STREAM ON FILE. 
INPUT: ('c', 42, 'string')
    encode(INPUT):
        stream_size: 14,
        binary_stream: b'c\x00\x00\x00*\x00\x00\x00string',
        pack_format: 'ci6s'
    RecordFile.write(binary_stream)

# APPENDING ENCODED RECORD ON <PrimaryIndex>
ENCODED_RECORD: (14, 'ci6s') #(stream_size, pack_format)
    append(id_, ENCODED_RECORD):
        position = ftell(eof)
        RAM_index.append(id_, position, stream_size, pack_format)

# READING ENCODED RECORD ON <PrimaryIndex>
    search(id_):
        RAM_entry = RAM_index.get(id)
        id_, position, stream_size, pack_format = RAM_entry
        PrimaryIndex.RecordFile.read(position, stream_size, pack_format)

# READING ENCODED RECORD ON <RecordFile>
<RecordFile>
RAM_INDEX_ENTRY: (position, stream_size, pack_format)
        file.seek(position)
        binary_stream = file.read(stream_size)
        decode(pack_format, binary_stream):
            returns ('c', 42, 'string')
```



