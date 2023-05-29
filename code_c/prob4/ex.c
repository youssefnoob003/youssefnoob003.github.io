//Reverse an integer entered by the user. 

#include <stdio.h>

// Function declarations
void reverse(int n);
int int_len(int n); // Returns the length of an integer
int power(int x, int y); // Returns x raised to the power of y

int main()
{
    // User input
    int n;
    printf("Original integer: ");
    scanf("%i", &n);

    // Main function
    reverse(n);

    return 0;
}

void reverse(int n)
{
    // Initialize local variables
    int reversed_integer = 0;
    int n_len = int_len(n);

    // Main loop
    for (int i = 0; i < n_len; i++)
    {
        int digit = n % 10;

        // Reverse the number by placing the digit originally at index i at the index (n_len - i - 1)
        reversed_integer += power(10, n_len - i - 1) * digit;

        n = n / 10;
    }

    printf("Reversed integer: %i\n", reversed_integer);
}

int int_len(int n)
{
    // Initialize the return variable
    int length = 0;

    while (n != 0)
    {
        length++;
        n = n / 10;
    }

    return length;
}

int power(int x, int y)
{
    // Initialize the return variable
    int result = 1;

    for (int i = 0; i < y; i++)
    {
        result = result * x;
    }

    return result;
}
