# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

plagiarismCatcher: main.o hash.o chunk.o
	g++ -o plagiarismCatcher main.o hash.o chunk.o

main.o: main.cpp chunk.h hash.h
	g++ -c main.cpp

hash.o: hash.cpp hash.h chunk.h
	g++ -c hash.cpp

chunk.o: chunk.cpp chunk.h
	g++ -c chunk.cpp