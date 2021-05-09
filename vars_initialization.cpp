#define _CRT_SECURE_NO_WARNINGS
#include "vars_initialization.h"
#include <stdio.h>
#include <string.h>
#define SIZE 300

int vars_init(char outp[][SIZE])
{
    FILE *inp = fopen("output.c", "r");
    char temp[SIZE] = { 0 };
    char vars2[SIZE][SIZE] = { 0 };
    int num_var[SIZE] = { 0 };
    int cnt = 0;
    int col = 0, colv = 0;
    int cntbr = 0;
    int cntd = 0;
    int cntpl = 0;

    while (!feof(inp))
    {
        fscanf(inp, "%s", temp);

        if (strcmp(temp, "int") == 0 || strcmp(temp, "char") == 0 || strcmp(temp, "void") == 0 || strcmp(temp, "float") == 0 || strcmp(temp, "double") == 0)
        {
            fscanf(inp, "%s", temp);

            if (strchr(temp, '(') == 0)
            {
                if (strchr(temp, '[') != 0)
                {
                    while (temp[cntbr] != '[')
                    {
                        cntbr++;
                    }

                    temp[cntbr] = '\0';
                }

                if (strchr(temp, ';') != 0)
                {
                    if (strchr(temp, '[') == 0)
                    {
                        while (temp[cntd] != ';')
                        {
                            cntd++;
                        }

                        temp[cntd] = '\0';
                    }
                    
                    strcpy(outp[cnt], temp);
                    cnt++;
                }
            }
        }

        cntbr = 0;
        cntd = 0;

    }

    fclose(inp);
    return cnt;
}
