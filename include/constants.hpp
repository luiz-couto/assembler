#include <string>
using namespace std;

/*
DEBUG definitions
*/

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }

/*
Instructions definitions
*/

#define print(x) cout << #x << " = " << x << endl;
#define error(msg) { cout << "error: " << msg << endl; exit(EXIT_FAILURE); }

#define IGN -1
#define REG 0
#define MEM 1
#define INST 2
#define LAB 3
#define COMMENT 4
#define INT 5
#define END 6

#define HALT 0
#define HALT_GRAPH {IGN,IGN}

#define LOAD 1
#define LOAD_GRAPH {REG,MEM}

#define STORE 2
#define STORE_GRAPH {REG,MEM}

#define READ 3
#define READ_GRAPH {REG,IGN}

#define WRITE 4
#define WRITE_GRAPH {REG,IGN}

#define COPY 5
#define COPY_GRAPH {REG,REG}

#define PUSH 6
#define PUSH_GRAPH {REG,IGN}

#define POP 7
#define POP_GRAPH {REG,IGN}

#define ADD 8
#define ADD_GRAPH {REG,REG}

#define SUB 9
#define SUB_GRAPH {REG,REG}

#define MUL 10
#define MUL_GRAPH {REG,REG}

#define DIV 11
#define DIV_GRAPH {REG,REG}

#define MOD 12
#define MOD_GRAPH {REG,REG}

#define AND 13
#define AND_GRAPH {REG,REG}

#define OR 14
#define OR_GRAPH {REG,REG}

#define NOT 15
#define NOT_GRAPH {REG,IGN}

#define JUMP 16
#define JUMP_GRAPH {MEM,IGN}

#define JZ 17
#define JZ_GRAPH {MEM,IGN}

#define JN 18
#define JN_GRAPH {MEM,IGN}

#define CALL 19
#define CALL_GRAPH {MEM,IGN}

#define RET 20
#define RET_GRAPH {IGN,IGN}

#define WORD 21
#define WORD_GRAPH {INT,IGN}

#define INST_SIZE 22
const string INSTRUCTIONS[INST_SIZE] = {"HALT","LOAD","STORE","READ","WRITE","COPY","PUSH","POP","ADD","SUB","MUL","DIV","MOD","AND","OR","NOT","JUMP","JZ","JN","CALL","RET","WORD"};
const int STATES[INST_SIZE][2] = {HALT_GRAPH,LOAD_GRAPH,STORE_GRAPH,READ_GRAPH,WRITE_GRAPH,COPY_GRAPH,PUSH_GRAPH,POP_GRAPH,ADD_GRAPH,SUB_GRAPH,MUL_GRAPH,DIV_GRAPH,MOD_GRAPH,AND_GRAPH,OR_GRAPH,NOT_GRAPH,JUMP_GRAPH,JZ_GRAPH,JN_GRAPH,CALL_GRAPH,RET_GRAPH,WORD_GRAPH};

#define REG_SIZE 4
const string REGISTERS[REG_SIZE] = {"R0","R1","R2","R3"};
