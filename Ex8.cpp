#include <iostream>
#include <sndfile.h>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 4){
        cout << "Wrong arguments" << endl;
        cout << "usage PROG_NAME INPUT_FILE OUTPUT_FILE N_BITS" << endl;
        return 1;
    }

    int nbits=stoi(argv[3]);
    cout << nbits << endl;
    if (0 < nbits && nbits < 15){
        cout << "N_BITS must be between 0 and 16" << endl;
        return 1;
    }

    SF_INFO inf;
    inf.format = 0;
    SNDFILE* inFile = sf_open(argv[1], SFM_READ, &inf);
    SNDFILE* outFile = sf_open(argv[2], SFM_WRITE, &inf);
    
    int readCount;
    short ptr[inf.frames*inf.channels];
    while((readCount = (int) sf_readf_short(inFile, ptr, 1)) > 0){
        ptr[0]=(ptr[0] >> nbits) << nbits;
        ptr[1]=(ptr[1] >> nbits) << nbits;
        sf_writef_short(outFile, ptr, readCount);
    }

    return 0;
}