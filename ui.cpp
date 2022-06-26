#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int write(string r) {
    ofstream fout;
    fout.open("prng-service.txt", ofstream::trunc);
    //If file could not be opened
    if (!fout) {
        // Print an error and exit
        cout << "Uh oh, there was a problem opening the file..." << endl;
        return -1;
    }
    fout << r;
    return 0;
}
// int read() {
//     ofstream fout;
//     fout.open("prng-service.txt");
//     //If file could not be opened
//     if (!fout) {
//         // Print an error and exit
//         cout << "Uh oh, there was a problem opening the file..." << endl;
//         return -1;
//     }
//     return 0;
// }

int get_response() {
    string str;
    bool valid;
    int valid_resp;
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
    valid_resp = stoi(str);
    return valid_resp;
}

int main() {

    cout << "\n\t\tWelcome to the random image service!" << endl;

    int response = 0;
    while(true) {
        cout << "\nEnter '1' to retrieve image\t\t\tEnter \'0' to quit\n" << endl;
        response = get_response();
        switch(response){
            case 0: {
                cout << "Have a good day!" << endl;
                return 0;
            }
            case 1: {
                if(write("run") == -1) {
                    cout << "Something went wrong..." << endl;
                }
                break;
            }
        }
    }
    
    return 0;
}
