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
    string fileName;
    vector<int> translation;
    vector<string> labels;
    map<string, int> labelsToPos;
    vector<int> nextStates;
    int lineIdx;

public:
    Assembler(string filename);
    ~Assembler();
    int processWord(string str, int pos);
    void setNextStates(const int states[2]);
    void checkNextState(int state);
    int getNextState();
    int isInstruction(string str);
    int isRegister(string str);
    bool isNumber(const string& str);
    bool isLabel(string str, int pos);
    void run();
};


#endif
