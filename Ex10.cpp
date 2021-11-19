#include <iostream>
#include <sndfile.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3){
        cout << "Wrong arguments" << endl;
        cout << "usage PROG_NAME ORIGNAL_FILE COPIED_FILE N_BITS" << endl;
        return 1;
    }

    int nbits=atoi(argv[2]);
    cout << nbits << endl;
    if ((nbits < 0) && (nbits > 15)){
        cout << "N_BITS must be between 0 and 16" << endl;
        return 1;
    }

    SF_INFO inf;
    inf.format = 0;
    SNDFILE* inFile = sf_open(argv[1], SFM_READ, &inf);

    double delta=2/pow(2, (16-nbits));
    double maximum_error=delta/2;

    cout << "MAXIMUM ERROR: " << maximum_error << endl;

    double snr=6.02*(16-nbits);

    cout << "SNR          : " << snr << endl;

    return 0;
}