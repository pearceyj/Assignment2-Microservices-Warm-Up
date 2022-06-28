#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

int write(string service) {
    ofstream fout;
    if(service == "run"){
        fout.open("prng-service.txt", ofstream::trunc);
    }
    else {
        fout.open("image-service.txt", ofstream::trunc);
    }
    //If file could not be opened
    if (!fout) {
        // Print an error and exit
        cout << "Uh oh, there was a problem opening the file..." << endl;
        return -1;
    }
    fout << service;
    fout.close();
    return 0;
}

string read(string service) {
    fstream fin;
    if(service == "prng")
        fin.open("prng-service.txt");
    if(service == "image")
        fin.open("image-service.txt");
    //If file could not be opened
    if (!fin) {
        // Print an error and exit
        cout << "Uh oh, there was a problem opening the file..." << endl;
        return NULL;
    }
    string req;
    fin >> req;
    fin.close();
    return req;
}

int get_res() {
    string str;
    bool valid;
    int valid_res;
    do {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) {

            if (!(str[i] == 48 || str[i] == 49) || str.length() > 1) {
                cout << "Please enter '1' or '0' only.\n";
                valid = false;
                break;
            }
            else
                valid = true;
        }
    }while (valid == false);
    valid_res = stoi(str);
    return valid_res;
}

void exit_all() {
    cout << "Exiting..." << endl;
    ofstream fout;
    fout.open("prng-service.txt", ofstream::trunc);
    fout << "exit";
    fout.close();
    fout.open("image-service.txt", ofstream::trunc);
    fout << "exit";
    fout.close();
}

int main() {

    cout << "\n\t\tWelcome to the random image service!" << endl;

    int res = 0;
    while(true) {
        cout << "\nEnter '1' to retrieve image\t\t\tEnter \'0' to quit\n" << endl;
        res = get_res();
        switch(res){
            case 0: {
                cout << "Have a good day!" << endl;
                exit_all();
                return 0;
            }
            case 1: {
                if(write("run") == -1) {
                    cout << "Something went wrong..." << endl;
                    exit_all();
                    return -1;
                }
                while(true){
                    string status = read("prng");
                    if(status != "run") {
                        write(status);
                        sleep_until(system_clock::now() + seconds(1));
                        break;
                    }
                    cout << read("image") << endl;
                }
                break;
            }
        }
    }

    return 0;
}
