#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int aboba(int a, int b)
{
    if (a > b)
    {
        aboba(a-1, b);
    }

    return a;
}

int ab(int a, int b)
{
    if (a > b)
    {
        aboba(a - 1, b);
    }
}

int boynextdoor(int a, int b)
{
    if (a < b)
    {
        boynextdoor(a, b - 2);
    }
}

int main()
{
    int x = 1;
    int t = 0;
    char temp;
    int a = 10;
    int b = 7;

    while (true)
    {
        x++;
    }
    while (1)
    {
        123;
    }
    for (;;) {
        count += i;
        break;
    }

    aboba(a, b);
    boynextdoor(a - 2, b);
}
