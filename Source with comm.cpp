#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "function_c.h"
#include "afk_variable.h"
#include "looping.h"
#define SIZE 300

typedef struct string_ {
    char str[SIZE];
}strings;

int main() {
    FILE* input = fopen("main2.c", "r");
    FILE* output = fopen("output.c", "w");
    char buff[SIZE] = { 0 };
    char c = '0';
    char buff_char = '0';
    char recurs_funs[SIZE][SIZE] = { 0 };
    char vars[SIZE][SIZE] = { 0 };
    int tabs = 0, cycle_deep = 0, max_deep = 0, tabs_flag = 0, comm_flag = 0, comm_end_flag = 1;

    while (!feof(input)) {
        fscanf(input, "%s", buff);
        if (strcmp(buff, "}") == 0) {
            tabs--;
        }
        for (int i = 0; i < tabs && tabs_flag == 1; i++) {
            fprintf(output, "\t");
        }
        tabs_flag = 0;
        c = fgetc(input);
        if (comm_flag == 1) {
            fprintf(output, "//");
            comm_flag = 0;
        }
        if (strcmp(buff, "/*") && strcmp(buff, "*/")) {
            fprintf(output, "%s", buff);
        }
        if ((c == ' ' || c == '\n') && strcmp(buff, "/*")) {
            fprintf(output, "%c", c);
            if (c == '\n') {
                tabs_flag = 1;
                if (comm_end_flag == 0) {
                    comm_flag = 1;
                }
            }
        }
        if (buff[strlen(buff) - 1] == ';') {
            if (c != '\n') {
                fprintf(output, "\n");
            }
            tabs_flag = 1;
        }
        if (strcmp(buff, "}") == 0) {
            if (tabs == cycle_deep) {
                cycle_deep--;
            }
            if (c != '\n') {
                fprintf(output, "\n");
            }
            tabs_flag = 1;
        }
        if (strcmp(buff, "{") == 0) {
            tabs++;
            if (c != '\n') {
                fprintf(output, "\n");
            }
            tabs_flag = 1;
        }
        if (strcmp(buff, "/*") == 0) {
            comm_flag = 1;
            comm_end_flag = 0;
        }
        if (strcmp(buff, "*/") == 0) {
            comm_flag = 0;
            comm_end_flag = 1;
        }
        if (strcmp(buff, "while") == 0 || strcmp(buff, "for") == 0) {
            cycle_deep++;
            if (cycle_deep > max_deep) {
                max_deep = cycle_deep;
            }
        }
    }

    ///////////////////////////////////////////
    rewind(output);
    int cnt = 0;
    cnt = fun_cycle(recurs_funs);
    printf("%d recursive function(-s):\n", cnt);

    for (int k = 0; k < cnt; ++k)
    {
        printf("%s\n", recurs_funs[k]);
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    cnt = 0;
    cnt = afk_var(vars);
    printf("%d unused variable(-s):\n", cnt);

    for (int k = 0; k < cnt; ++k)
    {
        printf("%s\n", vars[k]);
    }
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    cnt = 0;
    cnt = looping();

    if (cnt == 1)
    {
        printf("Looping is here\n");
    }
    else
    {
        printf("Looping isn't here\n");
    }
    ///////////////////////////////////////////
    printf("Maximum cycle length: %d", max_deep);

    fclose(input);
    fclose(output);
    return 0;
}