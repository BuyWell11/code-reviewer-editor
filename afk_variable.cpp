#define _CRT_SECURE_NO_WARNINGS
#include "afk_variable.h"
#include <stdio.h>
#include <string.h>
#define SIZE 300

int afk_var(char vars[][SIZE])
{
    FILE* inp = fopen("output.c", "r");
    char temp[SIZE] = { 0 };
    char vars2[SIZE][SIZE] = { 0 };
    int num_var[SIZE] = { 0 };
    int cnt = 0;
    int col = 0, colv = 0;
    int cntbr = 0;

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

                strcpy(vars2[col], temp);
                col++;
            }
        }

        for (int k = 0; k < col; ++k)
        {
            if (strcmp(temp, vars2[k]) == 0)
            {
                num_var[k]++;
            }
        }

        cntbr = 0;
    }

    for (int k = 0; k < col; ++k)
    {
        if (num_var[k] - 1 == 0)
        {
            cnt++;
            strcpy(vars[colv], vars2[k]);
            colv++;
        }
    }

    fclose(inp);
    return cnt;
}
