#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <sndfile.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) cout << "Wrong arguments" << endl;

    SF_INFO inf;
    inf.format = 0;
    SNDFILE* inFile = sf_open(argv[1], SFM_READ, &inf);

    cout << inf.frames << endl;
    cout<<inf.channels<<endl;

    inf.format = SF_FORMAT_WAV | SF_FORMAT_PCM_32;

    SNDFILE* outFile = sf_open(argv[2], SFM_WRITE, &inf);
    
    int readCount;
    float ptr[inf.frames*inf.channels];
    while((readCount = (int) sf_readf_float (inFile, ptr, 1)) > 0){
        cout<<readCount<<endl;
        sf_writef_float (outFile, ptr, readCount);
    }

    sf_close(inFile);
    sf_close(outFile);

    return 0;
}