#include <stdio.h>

#include "commands.h"
#include "..\Stack\Stack.h"      //-I..\Stack\


void Run(processor* proc);


int main(int argc, const char* argv[])
{
    FILE* filePtr = 0;
    //printf("%d %s %s", argc, argv[0], argv[1]);
    if (argc > 1)
    {
        filePtr = fopen(argv[1], "r");                //rb wb
        printf("reading from %s", argv[1]);           //fwrite
    }                                                 //fread
    else
    {
        filePtr = fopen("compiled.txt", "r");
        printf("reading from default source");
    }

    int cmd = -1, cmdNum = 0;



    while (fscanf(filePtr, "%d ", &cmd) != EOF)
    {
        cmdNum++;
        printf("cmds[%d] = %d\n", cmdNum, cmd);
    }
    printf("cmds[%d] = %d\n", cmdNum, cmd);

    fseek(filePtr, 0, SEEK_SET);

    int* cmds = (int*)calloc(cmdNum, sizeof(int));

    for (int i = 0; i < cmdNum; i++)
    {
        fscanf(filePtr, "%d", cmds + i);
        printf("cmds[%d] = %d\n", i, cmds[i]);
    }

    fclose(filePtr);

    processor proc;
    int regs[4] = {0};
    proc.regs = regs;
    proc.cmds = cmds;

    Run(&proc);
}


void Run(processor* proc)
{
    MyStack_t stk = {};
    StackCtor(&stk);
    int i = 0, run = 1;

    while (run)
    {
        switch (proc->cmds[i])
        {
            case PUSH:

                StackPush(proc->cmds[i+1], &stk);
                i++;

                break;

            case POP:

                proc->regs[proc->cmds[i+1]] = StackPop(&stk);

                printf("ax = %d\n", proc->regs[0]);
                printf("bx = %d\n", proc->regs[1]);

                break;

            case ADD:

                {
                int arg1 = StackPop(&stk);
                int arg2 = StackPop(&stk);

                StackPush(arg1 + arg2, &stk);

                break;
                }

            case SUB:

                {
                int arg1 = StackPop(&stk);
                int arg2 = StackPop(&stk);

                StackPush(arg2 - arg1, &stk);

                break;
                }

            case MUL:

                {
                int arg1 = StackPop(&stk);
                int arg2 = StackPop(&stk);

                StackPush(arg1 * arg2, &stk);

                break;
                }

            case DIV:

                {
                int arg1 = StackPop(&stk);
                int arg2 = StackPop(&stk);

                StackPush(arg2 / arg1, &stk);

                break;
                }

            case HLT:

                printf("program ended\n");

                free(proc->cmds);
                run = 0;

                break;

            case OUT:

                printf("result = %d\n", StackPop(&stk));

                break;
        }

        i++;
    }
}
