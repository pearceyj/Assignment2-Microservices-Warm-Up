#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>


using namespace std;
namespace fs = filesystem;

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
std::string read() {
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

    srand(time(NULL));

    int count = 0;
    string path = "/path/to/directory";
    for (const auto & entry : fs::directory_iterator(path)) {
                cout << entry.path() << endl;
                count++;
    }

    bool run = true;
    while(run == true) {
        if(read() == "run") {
            int num = rand() % count;
            string output = to_string(num);
            write(output);
        }
        else if (read() == "exit")
            run = false;
    }
    return 0;
}
