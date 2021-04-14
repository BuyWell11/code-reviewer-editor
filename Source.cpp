#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100

typedef struct string_ {
    char str[SIZE];
}strings;

int main() {
    FILE* input = fopen("main2.c", "r");
    FILE* output = fopen("output.c", "w");
    char buff[SIZE] = { 0 };
    char c = '0';
    char buff_char = '0';
    int tabs = 0, cycle_deep = 0, max_deep = 0, tabs_flag = 0;
    int cnt = 0;
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
        fprintf(output, "%s", buff);
        if (c == ' ' || c == '\n') {
            fprintf(output, "%c", c);
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
        if (strcmp(buff, "while") == 0 || strcmp(buff, "for") == 0) {
            cycle_deep++;
            if (cycle_deep > max_deep) {
                max_deep = cycle_deep;
            }
        }
    }
    
    ///////////////////////////////////////////
    rewind(output);
    cnt = fun_cycle(recurs_funs);
    printf("%d\n", cnt);

    for (int k = 0; k < cnt; ++k)
    {
        printf("%s\n", recurs_funs[k]);
    }
    ///////////////////////////////////////////

    fclose(input);
    fclose(output);
    return 0;
}
