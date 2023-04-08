#include <stdio.h>

void space (int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("   ");
    }
}

int main ()
{
    int num = 5, m = 1;
    int key = -1;

    for (int i = 0; i < num; i++)
    {
        key *= -1;
        space(num - i);
        for (int j = 0; j < num; j++)
        {
            printf("%2d ", m);
            m += key;
        }
        m += num - key;
        printf("\n");
    }
}