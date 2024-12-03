#include <stdio.h>
#include <cstring>
#include "commands.h"
//#include "..\Stack\Stack.h"


int main()
{
    FILE* in = fopen("tocompile.txt", "r");
    FILE* out = fopen("compiled.txt", "w");
    Compile(in, out);
    fclose(in);
    fclose(out);
    return 0;
}


void Compile(FILE* in, FILE* out)
{
    char cmd[10] = "";
    while (1)
    {
        fscanf(in, "%s", cmd);
        #ifdef DEBUG       //-D DEBUG
            printf("%s", cmd);
        #endif

        if (strcmp(cmd, "push") == 0)
        {
            fprintf(out, "%d ", PUSH);

            int arg = 0;
            fscanf(in, "%d", &arg);
            fprintf(out, "%d ", arg);
        }

        else if (strcmp(cmd, "pop") == 0)
        {
            fprintf(out, "%d ", POP);

            fscanf(in, "%s", cmd);

            fprintf(out, "%d ", *cmd - 'a');
        }

        else if (strcmp(cmd, "add") == 0)
        {
            fprintf(out, "%d ", ADD);
        }

        else if (strcmp(cmd, "sub") == 0)
        {
            fprintf(out, "%d ", SUB);
        }

        else if (strcmp(cmd, "mul") == 0)
        {
            fprintf(out, "%d ", MUL);
        }

        else if (strcmp(cmd, "div") == 0)
        {
            fprintf(out, "%d ", DIV);
        }

        else if (strcmp(cmd, "hlt") == 0)
        {
            fprintf(out, "%d", HLT);
            break;
        }

        else if (strcmp(cmd, "out") == 0)
        {
            fprintf(out, "%d ", OUT);
            //break;
        }

        else
        {
            printf("\"%s\" is not a command", cmd);
        }

    }

}

