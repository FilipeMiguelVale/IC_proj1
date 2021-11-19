#include <stdio.h>
#include <fstream>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int counts[256] = {0};

    int num_words = 0;         // Total number of words
    int num_chars = 0;         // Total number of characters (including underscores)
    int in_word = 0;           // Are we currently inside a word?
    string line;
    ifstream myfile (argv[1]);

    while (getline(myfile, line))
    {
        for( int i = 0; line[i] != 0; i++ )
        {
            if( isalpha(line[i]) )
            {
                counts[line[i]]++;
                num_chars++;

                if( !in_word ) {
                    in_word = 1;
                    num_words++;
                }
            }
            else {
                in_word = 0;
            }      
        }
    }
    
    printf( "Word total: %d\n", num_words );
    printf( "Character total: %d\n", num_chars );
    

    for( int i = 0; i < 256; i++ )  // Yes, this loop range is excessive...
    {
        if( counts[i] == 0 ) continue;
        printf( "%c: ", (char)i );
        for( int x = 0; x < counts[i]; x++ ) fputc('*', stdout);
        printf( " (%d)\n", counts[i] );
    }

    double entropy=0;
    double p=0;
    for(int i=0;i<=23;i++){
        if (counts[line[i]] != 0) {
        p=(double) counts[line[i]]/sizeof(line);   //probability of the element
        entropy+=p*log(p);  //entropy=-(sum(p*log(p)))
        }
    }

    printf("Histogram Entropy->  %f \n", entropy*-1);
        
    return 1;
}