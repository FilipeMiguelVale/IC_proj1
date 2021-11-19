#include <iostream>
#include <sndfile.h>
#include <cmath>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3){
        cout << "Wrong arguments" << endl;
        cout << "usage PROG_NAME ORIGNAL_FILE QUANTIZED_FILE" << endl;
        return 1;
    }

    SF_INFO ogInf;
    ogInf.format = 0;
    SNDFILE* ogFile = sf_open(argv[1], SFM_READ, &ogInf);
    SF_INFO cpInf;
    cpInf.format = 0;
    SNDFILE* cpFile = sf_open(argv[2], SFM_READ, &cpInf);

    int readCount=0;
    short ptr1[ogInf.channels];
    short ptr2[cpInf.channels];
    double sumMSE=0;

    double sumAVG=0;
    double peak=0;
    while((readCount = (int) sf_readf_short(ogFile, ptr1, 1)) > 0){
        sf_readf_short(cpFile, ptr2, 1);
        sumAVG+=(ptr1[0]+ptr1[1])/2;
        sumMSE += pow(((ptr1[0]+ptr1[1])/2) - ((ptr2[0]+ptr2[1])/2), 2);
        if(abs(((ptr1[0]+ptr1[1])/2) - ((ptr2[0]+ptr2[1])/2)) > peak) peak=abs(((ptr1[0]+ptr1[1])/2) - ((ptr2[0]+ptr2[1])/2));
    }

    double mse = sumMSE/(ogInf.frames*ogInf.channels);
    cout << "MEAN SQUARED ERROR : " << mse << endl;

    double avg=sumAVG/ogInf.frames;
    double snr = pow(avg, 2)/mse;
    cout << "SNR          : " << 10*log10(snr) << endl;

    cout << "MAX ERROR : " << peak << endl;

    return 0;
}