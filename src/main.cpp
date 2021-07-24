#include <iostream>

#include "constants.hpp"
#include "montador.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error("usage: ./montador <file_name>");
    }

    Assembler *assembler = new Assembler(argv[1]);
    assembler->run();

    return 0;
}
