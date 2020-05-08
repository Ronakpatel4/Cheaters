Command to use plagiarismChecker: ./plagiarismChecker "path name" "chunk size to check" "minimum number of chunks shared"

When entering path name include full path aside from the final /
Ex) Path from directory: sm_doc_set/
    Enter: sm_doc_set
Ex) Path from directory: Cheaters/sm_doc_set/
    Enter: Cheaters/sm_doc_set

Chunk size determines the length of test the Checker will use to detect cases of plagiarism

Minimum number of chunks shared is the lowest amount of text chunks shared between the files in the directory

Output will look like:


"Number of matches": "index of file 1, index of file 2"

Ex)
700: filenameA, filenameD
350: filenameA, filenameC
350: filenameC, filenameD
205: filenameB, filenameE
204: filenameA, filenameB

