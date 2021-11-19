#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char * argv[]) {
    string in;
    string out;
    vector<char> bytes;
    char byte = 0;
    
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);

    string line;
    while(ifs.get(byte)){
        bytes.push_back(byte);
    }
    
    for(auto i : bytes){
        ofs << i ;
    }

    return 0;
}