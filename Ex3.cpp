#include <iostream>
#include <string>
#include <stdio.h>
#include <sndfile.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3){
        cout << "Wrong arguments" << endl;
        return 1;
    }
    
    SF_INFO inf;
    inf.format = 0;
    SNDFILE* inFile = sf_open(argv[1], SFM_READ, &inf);

    cout << "Orignal Frames    : " << inf.frames << endl;
    cout << "Original Channels : " << inf.channels << endl;

    SNDFILE* outFile = sf_open(argv[2], SFM_WRITE, &inf);
    
    int readCount;
    float ptr[inf.frames*inf.channels];
    int framesCopied=0;
    while((readCount = (int) sf_readf_float (inFile, ptr, 1)) > 0){
        sf_writef_float(outFile, ptr, readCount);
        framesCopied++;
    }

    sf_close(inFile);
    sf_close(outFile);

    cout << "Frames Copied     : " << framesCopied << endl;

    return 0;
}