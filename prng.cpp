#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int write(string n) {
    ofstream fout;
    fout.open("prng-service.txt", ofstream::trunc);
    //If file could not be opened
    if (!fout) {
        // Print an error and exit
        cout << "Uh oh, there was a problem opening the file..." << endl;
        return -1;
    }
    fout << n;
    return 0;
}
string read() {
    fstream fin;
    fin.open("prng-service.txt");
    //If file could not be opened
    if (!fin) {
        // Print an error and exit
        cout << "Uh oh, there was a problem opening the file..." << endl;
        return NULL;
    }
    string req;
    fin >> req;
    return req;
}

int main() {

    vector<string> dirs;

    srand(time(NULL));

    if(read() == "run") {
        // int select = rand()%10;
        string ouput = to_string(rand()%10);
        write(ouput);
    }


    return 0;
}
