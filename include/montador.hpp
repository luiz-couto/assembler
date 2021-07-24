#ifndef MONTADOR_H
#define MONTADOR_H

#include <fstream>

using namespace std;

class Montador {
private:
    fstream file;
    int translation[];

public:
    Montador(/* args */);
    ~Montador();
};


#endif
