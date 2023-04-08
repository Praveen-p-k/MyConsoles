#include <stdio.h>

void reverse(int array[], int front, int back)
{
    for (int i = front; i <= front + (back - front) / 2; i++)
    {
        int copy = array[i];
        array[i] = array[back - (i - front)];
        array[back - (i - front)] = copy;
    }
}

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int size = sizeof(array) / sizeof(array[0]);

    int position = 3;

    for (int i = 0; i < size; i += position)
    {
        int remaining = size - i;
        if (remaining < position)
        {
            reverse(array, i, size - 1);
        }
        else
        {
            reverse(array, i, i + position - 1);
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
