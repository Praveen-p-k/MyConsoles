#include <stdio.h>

int main ()
{
    int n = 3, m = n;
    int length = n + n - 1;
    int array[length][length];

    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < (length - i); j++)
        {
            array[i][j] = m;
            array[j][i] = m;
            array[length - i - 1][j] = m;
            array[j][length - i - 1] = m;
        }
        m--;
    }
    
    for (int i = 0; i < length;  i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }
}