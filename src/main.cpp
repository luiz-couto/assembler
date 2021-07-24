#include <iostream>
#include <fstream>
#include <string>

#include "constants.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("usage: ./montador <file_name>");
    }

    fstream file;
    file.open(argv[1], ios::in);
    if (!file.is_open()) {
        error("could not open file");
    }

    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }

    return 0;
}

void processWord(string str) {

    if (str[0] == ';') {
        return;
    }

    if (str == "HALT") {
        
    }
    else if (str == "LOAD") {

    }
    else if (str == "STORE") {

    }

}