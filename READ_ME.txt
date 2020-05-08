Command to use plagiarismChecker: ./plagiarismChecker "path name" "chunk size to check" "minimum number of chunks shared"

When entering path name include full path aside from the final /
Ex) Path from directory: sm_doc_set/
    Enter: sm_doc_set
Ex) Path from directory: Cheaters/sm_doc_set/
    Enter: Cheaters/sm_doc_set

Chunk size determines the length of test the Checker will use to detect cases of plagiarism

Minimum number of chunks shared is the lowest amount of text chunks shared between the files in the directory

Output will look like:
Display hash table with file indexes
10001 - -> 0- -> 2- -> 19
10002 - -> 0- -> 0- -> 1- -> 10- -> 10- -> 11- -> 18- -> 19- -> 21
10003 - -> 6- -> 15- -> 19
10004 - -> 0- -> 11- -> 14- -> 14- -> 17- -> 22
10005 - -> 0- -> 18- -> 18
10006 - -> 14- -> 18- -> 18




"Number of matches": "file 1, file 2"

Ex)
700: filenameA, filenameD
350: filenameA, filenameC
350: filenameC, filenameD
205: filenameB, filenameE
204: filenameA, filenameB

