//convert an integer into a Roman numeral.

#include <stdio.h>

// Function declarations
void int_to_roman(int n);
void print_c_n_times(char c, int n); // Prints a character c, n times

int main()
{
    // User input
    int n;
    printf("Original integer: ");
    scanf("%i", &n);

    // Main function
    int_to_roman(n);

    return 0;
}

void int_to_roman(int n)
{
    // Each number n is n = a * 1000 + b * 500 + c * 100 + d * 50 + e * 10 + f * 5 + g
    // To convert each number to Roman numerals, we calculate a, b, c, d, e, f, and g

    // Calculating a and printing 'M' a times
    print_c_n_times('M', n / 1000);
    n = n % 1000;

    // Calculating b and printing 'D' b times
    print_c_n_times('D', n / 500);
    n = n % 500;

    // In Roman numerals, 400 is written as 'CD'
    // So, according to c, if c = 4, we print 'CD', else we print 'C' c times
    int tmp = n / 100;
    n = n % 100;

    switch (tmp)
    {
        case 4:
            printf("CD");
            break;

        default:
            print_c_n_times('C', tmp);
            break;
    }

    // Calculating d and printing 'L' d times
    print_c_n_times('L', n / 50);
    n = n % 50;

    // In Roman numerals, 40 is written as 'XL'
    // So, according to e, if e = 4, we print 'XL', else we print 'X' e times
    tmp = n / 10;
    n = n % 10;

    switch (tmp)
    {
        case 4:
            printf("XL");
            break;

        default:
            print_c_n_times('X', tmp);
            break;
    }

    // Calculating f and printing 'V' f times
    print_c_n_times('V', n / 5);
    n = n % 5;

    // In Roman numerals, 4 is written as 'IV'
    // So, we initiate a counter, if g = 4, we print 'IV', else we print 'I' g times
    tmp = n;

    switch (tmp)
    {
        case 4:
            printf("IV");
            break;

        default:
            print_c_n_times('I', tmp);
            break;
    }

    printf("\n");
}

void print_c_n_times(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}
