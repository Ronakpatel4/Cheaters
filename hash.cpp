//
// Created by Ronak on 5/7/2020.
//

#include "hash.h"
#include "chunk.h"
using namespace std;

Hash::Hash() {

}

void Hash::HashMake(int csize, int nfiles) {
    chunksize = csize;
    numfiles = nfiles;
    this->M = 10007;

}


void Hash::MatchTable(int nfiles) {
    matches = new int* [nfiles];
    for (int i = 0; i < nfiles; i++) {
        matches[i] = new int[nfiles];
        memset(matches[i], 0, nfiles * sizeof(int));            //Set all values in table to 0
    }
}

void Hash::newChain(int fnum, int key) {                        //key is value 0-M in hash list
    int n = 0;
    vector<int>::iterator i;
    int j = 0;
    for(i = hashl[key].begin(); i != hashl[key].end(); i++){
        if(hashl[key].at(j) == fnum){                                        //Checking for existing fnum in that hash value
            n = 0;
            break;
        }
        else if(hashl[key].at(j) != fnum){
            n = 1;
        }
        j++;
    }
//    if(n == 1) {
        hashl[key].push_back(fnum);                             //Add index of file to list
//    }
}

int Hash::HashKey(string chunk) {
    long long int tot = 0;
    long long int mult = 1;
    for(int i = 0; i < chunk.length(); i++){
        mult = (i % 4) ? 1 : mult * 256;
        tot += chunk[i] * mult;
    }
    tot = tot % 10007;
    return (int)(tot);                                               //Hashing function
}

void Hash::display() {
    vector<int>::iterator j;
    int k = 0;
    for(int i = 0; i < M; i++){
        k = 0;
        cout << i << " ";
        for(j = hashl[i].begin(); j != hashl[i].end(); j++){
            cout << "- -> " << hashl[i].at(k);
            k++;
        }
        cout << endl;
    }
}

void Hash::Match(int sim, int files) {
    vector<int>::iterator j;
    vector<int>::iterator l;
    int k = 0;
    for(int i = 0; i < M; i++) {
        k = 0;

        for (j = hashl[i].begin(); j != hashl[i].end(); j++) {
            for(l = hashl[i].begin(); l != hashl[i].end(); l++){
                for(int x = k+1; x < files; x++){
                    if(hashl[i].at(x) != hashl[i].at(k)){
                        matches[x][k] +=1;
                    }
                }
            }
            k++;
        }

    }

    for(int i = 0; i < files; i++){
        for(int y = i+1; y < files; y++) {
            if (matches[i][y] >= sim) {
                cout << matches[i][y] << "matches :" << i << " " << y <<endl;
            }
        }
    }


}

