#include <iostream>
#include <sndfile.h>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3){
        cout << "Wrong arguments" << endl;
        return 1;
    }

    SF_INFO inf;
    inf.format = 0;
    SNDFILE* inFile = sf_open(argv[1], SFM_READ, &inf);
    SNDFILE* outFile = sf_open(argv[2], SFM_WRITE, &inf);
    
    int readCount;
    short ptr[inf.frames*inf.channels];
    while((readCount = (int) sf_readf_short(inFile, ptr, 1)) > 0){
        ptr[0]=(ptr[0] >> 10) << 10;
        ptr[1]=(ptr[1] >> 10) << 10;
        sf_writef_short(outFile, ptr, readCount);
    }

    return 0;
}