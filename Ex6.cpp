#include <iostream>
#include <sndfile.h>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 2){
        cout << "Wrong arguments" << endl;
        return 1;
    }

    SF_INFO inf;
    inf.format = 0;
    SNDFILE* inFile = sf_open(argv[1], SFM_READ, &inf);

    printf("Opened file\n");
	printf("    Sample rate : %d\n", inf.samplerate);
	printf("    Channels    : %d\n", inf.channels);
    printf("    Frames      : %ld\n", inf.frames);
    printf("    Format      : %d\n", inf.format);

    
    int nItems=(int)inf.frames*inf.channels;
    float* allFrames=(float*) malloc(nItems*sizeof(float));
    float* right_channel=(float*) malloc(inf.frames*sizeof(float));
    float* left_channel=(float*) malloc(inf.frames*sizeof(float));

    int readItems = sf_readf_float(inFile, allFrames, nItems);

    for(int i=0; i<readItems ; i++){
        if(i%2==0){
            right_channel[(int)floor(i/2)] = allFrames[i];
        }
        else if(i%2!=0){
            left_channel[(int)floor(i/2)] = allFrames[i];
        }
    }

    map<float, int> H_left_channel;
    map<float, int> H_right_channel;
    map<float, int> H_mono;
    map<float, int>::iterator it;

    for(int i=0; i<inf.frames ; i++){
        float l=left_channel[i];
        float r=right_channel[i];
        float avg=(left_channel[i]+right_channel[i])/2;

        H_left_channel[l]+=1;
        H_right_channel[r]+=1;
        H_mono[avg]+=1;
    }

    cout << "---------------- LEFT CHANNEL ----------------" << endl;
    
    double entr=0;
    double p=0;
    for(it=H_left_channel.begin(); it!=H_left_channel.end();it++){
        // cout << it->first << " ";
        // for(int i=0 ; i<it->second ; i++){
        //     cout << "*";
        // }
        // cout << endl;

        p=(double)H_left_channel[it->first]/(inf.frames);
        entr+=p*log(p);
    }

    cout << entr << endl;

    cout << "---------------- RIGHT CHANNEL ----------------" << endl;

    entr=0;
    for(it=H_right_channel.begin(); it!=H_right_channel.end();it++){
        // cout << it->first << " ";
        // for(int i=0 ; i<it->second ; i++){
        //     cout << "*";
        // }
        // cout << endl;

        p=(double)H_right_channel[it->first]/(inf.frames);
        entr+=p*log(p);
    }

    cout << entr << endl;

    cout << "---------------- MONO ----------------" << endl;

    entr=0;
    for(it=H_mono.begin(); it!=H_mono.end();it++){
        // cout << it->first << " ";
        // for(int i=0 ; i<it->second ; i++){
        //     cout << "*";
        // }
        // cout << endl;
        
        p=(double)H_mono[it->first]/(inf.frames);
        entr+=p*log(p);
    }

    cout << entr << endl;

    sf_close(inFile);

    return 0;
}