#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() { int count = 0; int arr[20][20] = 0; for (int i = 0;i<20;i++) { for (int j=0;j<20;j++) { count += i;
            count += j;
            printf("count = %d\n", count);
        }
    }
}