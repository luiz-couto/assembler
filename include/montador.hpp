#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Assembler {
private:
    fstream file;
    vector<int> translation;
    vector<string> labels;
    map<string, int> labelsToPos;
    vector<int> nextStates;

public:
    Assembler(string filename);
    ~Assembler();
    void findLabels(fstream file);
    int processWord(string str, int pos);
    void setNextStates(const int states[2]);
    void checkNextState(int state);
    void run();
};


#endif
