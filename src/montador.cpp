#include "montador.hpp"
#include "constants.hpp"

using namespace std;

Assembler::Assembler(string filename) {
    this->labels.push_back("IGN");
    this->nextStates = {IGN, IGN};

    fstream file;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        error("could not open file");
    }

    bool endOfFile = false;
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string word;
        int pos = 0;

        while (getline(ss, word, ' ')) {
            if (word == " " || word.length() == 0) {
                continue;
            } 
            pos++;
            int wordType = processWord(word,pos);
            if (wordType == COMMENT) {
                break;
            } else if (wordType == END) {
                endOfFile = true;
                break;
            }
        }

        if (endOfFile) break;
    }

    //debugA(this->translation, this->translation.size());

    cout << "MV-EXE" << endl;
    cout << this->translation.size() << " 100" << " 999" << " 100" << endl;
    
    for (long unsigned int i=0; i<this->translation.size(); i++) {
        if (this->translation[i] < 0) {
            string label = this->labels[this->translation[i] * -1];
            int pos = this->labelsToPos[label];
            cout << pos - i;
        } else {
            cout << this->translation[i];
        }
        if (i != this->translation.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

Assembler::~Assembler() {
}

void Assembler::run() {

}

int Assembler::processWord(string str, int pos) {
    if (str[0] == ';') {
        return COMMENT;
    }

    if (str == "END") {
        return END;
    }

    int reg = isRegister(str);
    if (reg != -1) {
        checkNextState(REG);
        this->translation.push_back(reg);
        return REG;
    }

    int inst = isInstruction(str);
    if (inst != -1) {
        checkNextState(INST);
        if (inst != WORD) {
            this->translation.push_back(inst);
        }
        setNextStates(STATES[inst]);
        return INST;
    }

    bool isInt = isNumber(str);
    if (isInt) {
        checkNextState(INT);
        this->translation.push_back(stoi(str));
        return INT;
    }

    bool isLab = isLabel(str, pos);
    if (isLab) {
        str.pop_back();
        this->labelsToPos.insert(pair<string,int>(str, this->translation.size() - 1));
        return LAB;
    }

    checkNextState(MEM);
    int val = -1 * this->labels.size();
    this->labels.push_back(str);
    this->translation.push_back(val);

    return MEM;
   
}

int Assembler::isInstruction(string str) {
    for (int i=0; i<INST_SIZE; i++) {
        if (str == INSTRUCTIONS[i]) {
            return i;
        }
    }

    return -1;
}

int Assembler::isRegister(string str) {
    for (int i=0; i<REG_SIZE; i++) {
        if (str == REGISTERS[i]) {
            return i;
        }
    }
    return -1;
}

bool Assembler::isNumber(const string& str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool Assembler::isLabel(string str, int pos) {
    if (pos == 1) {
        if (str[str.length() - 1] == ':') {
            return true;
        }
    }
    return false;
}

void Assembler::setNextStates(const int states[2]) {
    this->nextStates[0] = states[0];
    this->nextStates[1] = states[1];
}

void Assembler::checkNextState(int state) {
    if(this->nextStates[0] == IGN) {
        if(this->nextStates[1] == state || this->nextStates[1] == IGN) {
            this->nextStates[1] = IGN;
            return;
        } else {
            std::stringstream ss;
            ss << "expected " << this->nextStates[1] << " but got " << state;
            error(ss.str());
        }
    }
    if (this->nextStates[0] == state) {
        this->nextStates[0] = IGN;
        return;
    } else {
        std::stringstream ss;
        ss << "expected " << this->nextStates[0] << " but got " << state;
        error(ss.str());
    }
}

