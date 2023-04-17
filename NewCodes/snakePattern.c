#include <stdio.h>

int main ()
{
    char operator[3];
    operator[0] = '-';
    operator[2] = '+';

    int length = 15;
    int key = 1;
    for (int i = 1; i < length; i++) 
    {
        key *= -1;
        printf("%d%c", i, operator[key + 1]);
    }
    printf("%d", length);
}