#define _CRT_SECURE_NO_WARNINGS
#include "looping.h"
#include <stdio.h>
#include <string.h>
#define SIZE 300

int looping()
{
    FILE* inp = fopen("output.c", "r");
    char temp[SIZE] = { 0 };
    int cnt = 0, cnt_open = 0, cnt_close = 0;
    int fl = 0;

    while (!feof(inp))
    {
        fscanf(inp, "%s", temp);
        
        if (strcmp(temp, "for") == 0 || strcmp(temp, "while") == 0)
        {
            fscanf(inp, "%s", temp);
            fl = 0;
            cnt = 0;

            if (strcmp(temp, "(;;)") == 0 || strcmp(temp, "(true)") == 0 || strcmp(temp, "(1)") == 0)
            {
                while (cnt_open != cnt_close || cnt_open == 0 && cnt_open == 0)
                {
                    fl = 1;
                    fscanf(inp, "%s", temp);

                    if (strcmp(temp, "{") == 0)
                    {
                        cnt_open++;
                    }
                    else if (strcmp(temp, "}") == 0)
                    {
                        cnt_close++;
                    }
                    
                    if (strcmp(temp, "break;") == 0)
                    {
                        cnt++;
                    }
                }

                if (fl = 1 && cnt == 0)
                {
                    fclose(inp);
                    return 1;
                }
            }
        }

        cnt_open = 0;
        cnt_close = 0;
    }

    fclose(inp);
    return 0;
}
