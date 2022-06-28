#include <iostream>
#include <cstdlib> //rand(), srand()
#include <ctime> //time()
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int write(string dir) {
    ofstream fout;
    fout.open("image-service.txt", ofstream::trunc);
    //If file could not be opened
    // if (!fout) {
    //     // Print an error and exit
    //     cout << "Uh oh, there was a problem opening the file..." << endl;
    //     return -1;
    // }
    fout << dir;
    cout << "...image dir written to file..." << endl;
    return 0;
}
string read() {
    fstream fin;
    fin.open("image-service.txt");
    //If file could not be opened
    // if (!fin) {
    //     // Print an error and exit
    //     cout << "Uh oh, there was a problem opening the file..." << endl;
    //     return "";
    // }
    string num;
    fin >> num;
    return num;
}

bool isNumber(string s) {
    if(s.size()==0)
        return false;
    for(int i = 0;i < s.size();i++) {
        if((s[i] >= '0' && s[i] <= '9') == false) {
            return false;
        }
    }
    return true;
}

int main() {

    srand(time(NULL));
    vector<string> imageDirs {
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\diglett_alola.png",
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\gengar_mega.png",
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\meowth_alola.png",
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\raichu_alola.png",
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\solgaleo.jpg",
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\venusaur_mega.png",
        "C:\\Users\\GilliganMuscaria\\Documents\\school\\summer22\\CS_361\\repos\\Assignment2-Microservices-Warm-Up\\Images\\zapdos_galar.png",
    };

    int size = imageDirs.size();
    while(true) {
        int idx;
        string req = read();
        if (req == "exit") {
            cout << "image service EXIT" << endl;
            return 0;
        }
        if(isNumber(req)) {
            cout << "...reading random number..." << endl;
            idx = stoi(req);
            if(idx >= size)
                idx = idx%size;
            write(imageDirs.at(idx));
        }
    }
    return 0;
}
