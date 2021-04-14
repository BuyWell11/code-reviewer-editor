#define _CRT_SECURE_NO_WARNINGS
#include "function_c.h"
#include <stdio.h>
#include <string.h>
#define SIZE 300

int is_temp_fun(char temp[SIZE], char fun_name[SIZE])
{
    int cnt = 0;
    for (int k = 0; k < strlen(fun_name); ++k)
    {
        if (temp[k] == fun_name[k])
        {
            cnt++;
        }
    }

    if (cnt == strlen(fun_name) && temp[cnt] == '(')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int fun_cycle(char outp[][SIZE])
{
    FILE* inp = fopen("output.c", "r");
    char temp[SIZE] = { 0 };
    int k = 0;
    int cnt = 0, cnt_open = 0, cnt_close = 0;
    int col = 0;
    
    while (!feof(inp))
    {
        fscanf(inp, "%s", temp);
        if (strcmp(temp, "main()") == 0)
        {
            fclose(inp);
            return 0;
        }

        if (strcmp(temp, "int") == 0 || strcmp(temp, "char") == 0 || strcmp(temp, "void") == 0 || strcmp(temp, "float") == 0 || strcmp(temp, "double") == 0)
        {
            fscanf(inp, "%s", temp);
            if (strchr(temp, '(') != 0)
            {
                char fun_name[SIZE] = { 0 };

                while (temp[k] != '(')
                {
                    fun_name[k] = temp[k];
                    k++;
                }

                while (cnt_open != cnt_close || cnt_open == 0 && cnt_open == 0)
                {
                    fscanf(inp, "%s", temp);

                    if (strcmp(temp, "{") == 0)
                    {
                        cnt_open++;
                    }
                    else if (strcmp(temp, "}") == 0)
                    {
                        cnt_close++;
                    }
                    else if (strchr(temp, '(') != 0 && is_temp_fun(temp, fun_name) == 1)
                    {
                        cnt++;
                    }
                }

                strcpy(outp[col], fun_name);
                col++;
            }
            cnt_open = 0;
            cnt_close = 0;

            k = 0;
        }
    }

    fclose(inp);
    return cnt;
}
