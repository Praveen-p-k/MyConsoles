#include <stdio.h>
#include <stdbool.h>

bool checkPrimeOrNot(int number)
{
    int count = 0;
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }
    if (count)
    {
        return false;
    }
    return true;
}
int reverse(int number)
{
    int reversedNumber = 0;
    while (number)
    {
        reversedNumber = (reversedNumber * 10) + (number % 10);
        number /= 10;
    }
    return reversedNumber;
}
int main(void)
{
    int from = 10, to = 100;

    for (int number = from; number <= to; number++)
    {
        if (number < 10)
        {
            printf("%d, ", number);
        }
        else if (checkPrimeOrNot(number))
        {
            int reversedNumber = reverse(number);
            if (checkPrimeOrNot(reversedNumber))
            {
                printf("%d, ", number);
            }
        }
    }
}