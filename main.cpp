#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "chunk.h"
#include "hash.h"

using namespace std;
using std::string;

int main(int argc, char *argv[])
{
   char *fName = new char[80];
    strcpy(fName, argv[1]);
    string dir = fName;

    char *chunknumber = new char[80];
    int chunknum = strtol(chunknumber, NULL, 10);

    char *numin = new char[80];
    int similar = strtol(numin, NULL, 10);

//    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    ifstream inFile;
    vector<string> fin;
    string s;
    string path;

    getdir(dir,files);
    files.erase(files.begin());                         //Remove first two vector entries . and ..
    files.erase(files.begin());

    vector <string> chunk;                              //Chunk manipulation initialization
    string chunkdata;
    int key;
    Hash x;
    x.HashMake(14,files.size());
    x.MatchTable(files.size());
    vector<int> *hashl[10007];

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << " " << files[i] << endl;

        path = dir + "/" + files[i];
        inFile.open(path.c_str());
        inFile >> s;
        while (inFile) {
            chunk.push_back(s);                                 //Add words to chunk

            if(chunk.size() == 6){                              //Number is placeholder for argv[2]
                for(int j = 0; j < chunk.size(); j++){
                    chunkdata += chunk.at(j);
                }
                lower(chunkdata);                           //Make chunk all lowercase
                key = x.HashKey(chunkdata);
                x.newChain(i, key);
//                cout << chunkdata << " " << key << endl;                     //Add hash function later to operate on chunk

                chunkdata.clear();                             //Prepare buffer for new chunk
                chunk.erase(chunk.begin());                    //Erase first word to prep for next one
            }
            inFile >> s;
        }
        chunk.clear();
        inFile.close();

    }
//    x.display();
    x.Match(similar, files.size());
//    delete[] fName;
//    delete[] chunknumber;
//    delete[] numin;
    return 0;
}
