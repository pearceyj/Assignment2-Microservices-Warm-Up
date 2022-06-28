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
    // if (!fout) {
    //     // Print an error and exit
    //     cout << "Uh oh, there was a problem opening the file..." << endl;
    //     return -1;
    // }
    fout << n;
    cout << "...rand number written to file..." << endl;
    return 0;
}
string read() {
    fstream fin;
    fin.open("prng-service.txt");
    //If file could not be opened
    // if (!fin) {
    //     // Print an error and exit
    //     cout << "Uh oh, there was a problem opening the file..." << endl;
    //     return "";
    // }
    string req;
    fin >> req;
    return req;
}

int main() {

    srand(time(NULL));

    while(true) {
        if(read() == "run") {
            cout << "...executing rand number generation..." << endl;
            int num = rand();
            string output = to_string(num);
            write(output);
        }
        else if (read() == "exit") {
            cout << "prng service EXIT" << endl;
            break;
        }
    }
    return 0;
}
