#define _CRT_SECURE_NO_WARNINGS
#include "incorrect_name.h"
#include <stdio.h>
#include <string.h>
#define SIZE 100

int incorrect_name(char names[][SIZE])
{
    FILE* input = fopen("output.c", "r");
    char buff[SIZE] = { 0 }, name[SIZE] = { 0 };
    char all_name[SIZE][30] = { 0 };
    int count = 0, ind = 0, incorrect_count = 0;
    int used_fun[SIZE] = { 0 };
    while (!feof(input)) {
        fscanf(input, "%s", buff);
        if (strcmp(buff, "int") == 0 || strcmp(buff, "void") == 0 || strcmp(buff, "char") == 0 || strcmp(buff, "float") == 0 || strcmp(buff, "double") == 0) {
            fscanf(input, "%s", buff);
            if (strcmp(buff, "main()") == 0)
                break;
            if (strchr(buff, '(') != 0) {
                while (buff[ind] != '(') {
                    name[ind] = buff[ind];
                    ind++;
                }
                strcpy(all_name[count], name);
                count++;
                for (int i = 0; i < ind; i++) {
                    name[i] = '\0';
                }
            }
        }
        ind = 0;
    }
    while (!feof(input)) {
        fscanf(input, "%s", buff);
        if (strcmp(buff, "int") == 0 || strcmp(buff, "char") == 0 || strcmp(buff, "void") == 0 || strcmp(buff, "float") == 0 || strcmp(buff, "double") == 0)
        {
            fscanf(input, "%s", buff);

            if (strchr(buff, '(') == 0)
            {
                if (strchr(buff, '[') != 0)
                {
                    while (buff[ind] != '[')
                    {
                        ind++;
                    }

                    buff[ind] = '\0';
                }
                else if (strchr(buff, ';') != 0)
                {
                    while (buff[ind] != ';')
                    {
                        ind++;
                    }

                    buff[ind] = '\0';
                }
                strcpy(all_name[count], buff);
                count++;
            }
            ind = 0;
        }
    }
    for (int i = 0; i < count; i++) {
        if (!((all_name[i][0] >= 'a' && all_name[i][0] <= 'z') || (all_name[i][0] >= 'A' && all_name[i][0] <= 'Z') || all_name[i][0] == '*')) {
            strcpy(names[incorrect_count], all_name[i]);
            incorrect_count++;
        }
        else if (strcmp(all_name[i], "int") == 0 || strcmp(all_name[i], "char") == 0 || strcmp(all_name[i], "void") == 0 || strcmp(all_name[i], "float") == 0 || strcmp(all_name[i], "double") == 0) {
            strcpy(names[incorrect_count], all_name[i]);
            incorrect_count++;
        }
        else {
            for (int j = 1; j < strlen(all_name[i]); j++) {
                if (!((all_name[i][j] >= '0' && all_name[i][j] <= '9') || (all_name[i][j] >= 'a' && all_name[i][j] <= 'z') || (all_name[i][j] >= 'A' && all_name[i][j] <= 'Z') || all_name[i][j] == '_')) {
                    strcpy(names[incorrect_count], all_name[i]);
                    incorrect_count++;
                }
            }
        }

    }
    fclose(input);
    return incorrect_count;
}
