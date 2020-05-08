//
// Created by Ronak on 5/6/2020.
//
#include "chunk.h"
using namespace std;

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

void lower(string &chunk){
    transform(chunk.begin(), chunk.end(), chunk.begin(), ::tolower);        //Function to convert chunk into all lowercase if applicable
}

