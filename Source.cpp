#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "function_c.h"
#include "afk_variable.h"
#include "looping.h"
#include "vars_initialization.h"
#include "useless_fun.h"
#include "incorrect_name.h"
#include "formatting.h"
#define SIZE 300

typedef struct string_ {
    char str[SIZE];
}strings;

int main() {
    char recurs_funs[SIZE][SIZE] = { 0 };
    char vars[SIZE][SIZE] = { 0 };
    char vars_init_[SIZE][SIZE] = { 0 };
    char useless_funс[SIZE][SIZE] = { 0 };
    char incorrect_names[SIZE][SIZE] = { 0 };
    int cnt = 0;

    ////////////////////////////////////////////// Максимальная вложенность циклов
    cnt = formatting();

    switch (cnt)
    {
    case 0:
        printf("There are no cycles in the program.\n\n");
        break;
    default:
        printf("Maximum cycle deep: %d.\n\n", cnt);
    }

    /////////////////////////////////////////// Зацикливание
    cnt = looping();

    switch (cnt)
    {
    case 1:
        printf("Looping is here.\n\n");
        break;
    default:
        printf("Looping isn't here.\n\n");
    }

    /////////////////////////////////////////// Неиспользуемые функции
    cnt = useless_fun(useless_funс);

    switch (cnt)
    {
    case 0:
        printf("All functions are useful./There are no functions.\n\n");
        break;
    default:
        printf("%d useless function(-s):\n", cnt);

        for (int i = 0; i < cnt; i++) {
            printf("%s\n", useless_funс[i]);
        }
        printf("\n");
    }

    /////////////////////////////////////////// Рекурсивные функции
    cnt = fun_cycle(recurs_funs);

    switch (cnt)
    {
    case 0:
        printf("There are no recursive functions.\n\n");
        break;
    default:
        printf("%d recursive function(-s):\n", cnt);

        for (int k = 0; k < cnt; ++k)
        {
            printf("%s\n", recurs_funs[k]);
        }
        printf("\n");
    }

    /////////////////////////////////////////// Неиспользуемые переменные
    cnt = afk_var(vars);

    switch (cnt)
    {
    case 0:
        printf("All variables are used./There are no variables.\n\n");
        break;
    default:
        printf("%d unused variable(-s):\n", cnt);
        for (int k = 0; k < cnt; ++k)
        {
            printf("%s\n", vars[k]);
        }
        printf("\n");
    }

    /////////////////////////////////////////// Начальные значения переменных
    cnt = vars_init(vars_init_);

    switch (cnt)
    {
    case 0:
        printf("All variables have initial values./There are no variables.\n\n");
        break;
    default:
        printf("%d variable(-s) isn't (aren't) initialised:\n", cnt);
        for (int k = 0; k < cnt; ++k)
        {
            printf("%s\n", vars_init_[k]);
        }
        printf("\n");
    }

    ////////////////////////////////////////// Корректные имена переменных
    cnt = incorrect_name(incorrect_names);

    switch (cnt)
    {
    case 0:
        printf("All variables have correct names./There are no variables.\n\n");
        break;
    default:
        printf("Incorrect names:\n");
        for (int i = 0; i < cnt; i++)
        {
            printf("%s\n", incorrect_names[i]);
        }
        printf("\n");
    }

    return 0;
}