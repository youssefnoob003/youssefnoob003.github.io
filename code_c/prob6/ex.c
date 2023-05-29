//Find triplets in an array whose sum is equal to zero. 

#include <stdio.h>
#include <stdlib.h>

// Function declarations
void triplets(int *array, int n);
void get_array(int *array, int len);

int main()
{  
    // User input
    int n;
    printf("Length of array: ");
    scanf("%i", &n);

    int *array = malloc(sizeof(int) * n);
    get_array(array, n);

    // Main function
    triplets(array, n);

    free(array);

    return 0;
}

void triplets(int *array, int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (array[i] + array[j] + array[k] == 0)
                {
                    printf("%i  %i  %i\n", array[i], array[j], array[k]);
                }
            }
        }
    }
}

void get_array(int *array, int len)
{  
    for (int i = 0; i < len; i++)
    {
        printf("Input array[%i]: ", i);
        scanf("%i", &array[i]);
    }
}
