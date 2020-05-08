//
// Created by Ronak on 5/7/2020.
//

#ifndef CHEATERS_HASH_H
#define CHEATERS_HASH_H

#endif //CHEATERS_HASH_H

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "chunk.h"

using namespace std;
using std::string;

class Hash{
    private:
    int chunksize;
    int numfiles;
    int **matches;
    int M;


    public:
    Hash();
    void HashMake(int csize, int nfiles);
    void MatchTable(int nfiles);
    void newChain(int fnum, int key);
    int HashKey(string chunk);
    void Match(int sim, int files);
    void display();
    vector<int> hashl[10007];
};