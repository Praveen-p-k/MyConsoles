#include <stdio.h>

int main()
{
    int currency[5][2] = 
    {
        { 2000, 1 }, 
        { 500, 5 }, 
        { 200, 1 }, 
        { 100, 1 }, 
        { 50, 4 }
    };

    int returnAmout = 2000;
    int sum = 0, j;

    for (int i = 0; i < 5; i++)
    {
        if (sum + currency[i][0] <= returnAmout && currency[i][1])
        {
            printf("%d \tX    ", currency[i][0]);
            for (j = 0; j < currency[i][1]; j++)
            {
                if (sum + currency[i][0] <= returnAmout)
                {
                    sum += currency[i][0];
                }
                else 
                {
                    break;
                }
            }
            printf("%d = %d\n", j, j * currency[i][0]);
        }
    }
    printf("-------------------------\n");
    printf("\tTotal  = %d\n", sum);
    printf("-------------------------\n");
}
