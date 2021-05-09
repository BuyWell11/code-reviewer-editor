#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "formatting.h"
#define SIZE 300

int formatting()
{
    FILE* input = fopen("main2.c", "r");
    FILE* output = fopen("output.c", "w");
    char buff[SIZE] = { 0 };
    char c = '0';
    int tabs = 0, cycle_deep = 0, max_deep = 0, tabs_flag = 0, comm_flag = 0, comm_end_flag = 1, cycle_flag = 0;

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
                if (cycle_flag != 0) {
                    cycle_deep--;
                    cycle_flag--;
                }
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
            cycle_flag++;
            if (cycle_deep > max_deep) {
                max_deep = cycle_deep;
            }
        }
    }

    fclose(input);
    fclose(output);
    return max_deep;
}
