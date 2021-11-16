#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string in;
    string out;
    vector<char> bytes;
    char byte = 0;
    
    cout << "Que ficheiro quer ler?" << endl;
    cin >> in;
    cout << "Nome de ficheiro final" << endl;
    cin >> out;
    
    ifstream ifs(in);
    ofstream ofs(out);

    string line;
    while(ifs.get(byte)){
        bytes.push_back(byte);
    }
    
    for(auto i : bytes){
        ofs << i ;
    }

    return 0;
}