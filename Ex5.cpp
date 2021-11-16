#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

    int counts[256] = {0};

    int num_words = 0;         // Total number of words
    int num_chars = 0;         // Total number of characters (including underscores)
    int num_underscores = 0;   // Total number of underscores
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
            else if( line[i] == '_' )
            {
                counts[line[i]]++;
                num_underscores++;
                in_word = 0;
            }
            else {
                in_word = 0;
            }      
        }
    }
    
    printf( "Word total: %d\n", num_words );
    printf( "Character total: %d\n", num_chars );
    printf( "Character total omitting underscore: %d\n", num_chars - num_underscores );

    for( int i = 0; i < 256; i++ )  // Yes, this loop range is excessive...
    {
        if( counts[i] == 0 ) continue;
        printf( "%c: ", (char)i );
        for( int x = 0; x < counts[i]; x++ ) fputc('*', stdout);
        printf( " (%d)\n", counts[i] );
    }
}