/*
Instructions definitions
*/

#define print(x) cout << #x << " = " << x << endl;
#define error(msg) { cout << "error: " << msg << endl; exit(EXIT_FAILURE); }

#define REG 0
#define MEM 1
#define INST 2
#define LAB 3

#define HALT 0
#define HALT_GRAPH = {}

#define LOAD 1
#define LOAD_GRAPH {REG,MEM}

#define STORE 2
#define STORE_GRAPH {REG,MEM}

#define READ 3
#define READ_GRAPH {REG}

#define WRITE 4
#define WRITE_GRAPH {REG}

#define COPY 5
#define COPY_GRAPH {REG,REG}

#define PUSH 6
#define PUSH_GRAPH {REG}

#define POP 7
#define POP_GRAPH {REG}

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
#define NOT_GRAPH {REG}

#define JUMP 16
#define JUMP_GRAPH {MEM}

#define JZ 17
#define JZ_GRAPH {MEM}

#define JN 18
#define JN_GRAPH {MEM}

#define CALL 19
#define CALL_GRAPH {MEM}

#define RET 20
#define RET_GRAPH {}