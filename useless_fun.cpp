#define _CRT_SECURE_NO_WARNINGS
#include "useless_fun.h"
#include <stdio.h>
#include <string.h>
#define SIZE 300

int useless_fun(char outp[][SIZE])
{
    FILE* input = fopen("output.c", "r");
    char buff[SIZE] = { 0 }, name[SIZE] = { 0 };
    char all_fun[SIZE][30] = { 0 };
    int count = 0, ind = 0, useless_count = 0;
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
                strcpy(all_fun[count], name);
                count++;
                for (int i = 0; i < ind; i++) {
                    name[i] = '\0';
                }
                ind = 0;
            }
        }
    }
    while (!feof(input)) {
        fscanf(input, "%s", buff);
        if (strchr(buff, '(') != 0) {
            while (buff[ind] != '(') {
                name[ind] = buff[ind];
                ind++;
            }
            for (int i = 0; i < count; i++) {
                if (strcmp(name, all_fun[i]) == 0) {
                    used_fun[i]++;
                }
            }
        }
        for (int i = 0; i < ind; i++) {
            name[i] = '\0';
        }
        ind = 0;
    }
    for (int i = 0; i < count; i++) {
        if (used_fun[i] == 0) {
            strcpy(outp[useless_count], all_fun[i]);
            useless_count++;
        }
    }
    fclose(input);
    return useless_count;
}
