#ifndef __COMMANDS_CODES__
#define __COMMANDS_CODES__

enum Commands
{
    PUSH,
    POP,

    ADD,
    SUB,
    MUL,
    DIV,

    OUT,
    HLT,
};

enum Registers
{
    AX,
    BX,
    CX,
    DX,
};


struct processor
{
    int* cmds;
    int* regs;
    int* memory;
};


void Compile(FILE* fileFromPtr, FILE* fileToPtr);

#endif
