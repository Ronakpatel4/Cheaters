//
// Created by Ronak on 5/6/2020.
//

#ifndef CHEATERS_CHUNK_H
#define CHEATERS_CHUNK_H

#endif //CHEATERS_CHUNK_H

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
using std::string;

//Place for any non hash related functions

int getdir (string dir, vector<string> &files);

void lower(string &chunk);