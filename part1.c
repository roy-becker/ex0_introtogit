#include <stdio.h>
#include <stdlib.h>


#define NOT_POWER_OF_TWO -1


int exp_of_two(int n)
{
    int c = 0;
    int temp = 1;

    while (temp < n)
    {
        c++;
        temp *= 2;
    }

    if (temp == n)
    {
        return c;
    }
    return NOT_POWER_OF_TWO;
}


int main()
{
    printf("Enter size of input:");

    int size;
    if (scanf(" %d", &size) != 1)
    {
        return 0;
    }

    if (size <= 0)
    {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter numbers:");

    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        if (scanf(" %d", &arr[i]) != 1)
        {
            printf("Invalid number\n");
            free(arr);
            return 0;
        }
    }

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        int temp = exp_of_two(arr[i]);

        if (temp != NOT_POWER_OF_TWO)
        {
            printf("The number %d is a power of 2: %d = 2 ^ %d\n", arr[i], arr[i], temp);
            sum += temp;
        }
    }

    free(arr);

    printf("Total exponent sum is %d\n", sum);
    
    return 0;
}