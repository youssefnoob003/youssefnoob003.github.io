//Finding pairs of integers in an array that sum up to a given target value.

#include <stdio.h>
#include <stdlib.h>

// Function to input the array elements
void get_array(int *array, int len);

// Function to find pairs in the array that sum up to the target value
void result(int *array, int len, int target_value);

int main()
{
    // Variables initialization
    int len, target_value;

    // Array input
    printf("Length of the array: ");
    scanf("%i", &len);

    while (len < 2)
    {
        printf("Length of the array should be > 2: ");
        scanf("%i", &len);
    }

    int *array = malloc(sizeof(int) * len);
    get_array(array, len);

    // Target value input
    printf("Target value: ");
    scanf("%i", &target_value);

    // Execute main function
    result(array, len, target_value);

    // Free allocated memory
    free(array);

    return 0;
}

void get_array(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Input array[%i]: ", i);
        scanf("%i", array + i);
    }
}

void result(int *array, int len, int target_value)
{
    // Loop through the array and find pairs that sum up to the target value
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int val = *(array + i) + *(array + j);

            // Check if the pair sums up to the target value
            if (val == target_value)
            {
                printf("Pair found: (%i, %i)\n", i, j);
            }
        }
    }
}
