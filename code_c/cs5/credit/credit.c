#include <stdio.h>


long user_input();
unsigned int checker(long credit_card); //check's for card validity with Luhn’s Algorithm
void type(long credit_card); //prints out the credit card name (or INVALID)

int len(long  n); //returns the number of digits in a long
int sum(int x); //returns the sum of digits in an integer
long power(int a, int b); //returns a**b


int main()
{
    long credit_card = user_input();

    if (checker(credit_card))
    {
        type(credit_card);
    }
    else
    {
        printf("INVALID\n");
    }
}

long user_input()
{
    long n;

    do
    {
        printf("Input a valid credit card number: ");
        int nb_read = scanf("%li", &n);
        while (nb_read != 1)
        {
            printf("invalid!\ntry again: ");
            scanf("%*[^\n]");
            nb_read = scanf("%li", &n);
        }
    }
    while (n < 0);

    return n;
}

unsigned int checker(long credit_card)
{
    int res = 0;
    int n = len(credit_card);

    for(int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            res = res + sum((credit_card % 10) * 2);
        }
        else
        {
            res = res + (credit_card % 10);
        }

        credit_card = credit_card / 10;
    }
    return (res % 10) == 0;
}

int len(long  n)
{
    int res = 0;
    while (n > 0)
    {
        n = n /10;
        res++;
    }
    return res;
}

int sum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res = res + x % 10;
        x = x / 10;
    }
    return res;
}

void type(long credit_card)
{
    if (len(credit_card) == 15 && (credit_card / power(10, len(credit_card) - 2) == 34 || credit_card / power(10, len(credit_card) - 2) == 37)) printf("AMEX\n");
    else if ((len(credit_card) == 13 || (len(credit_card) == 16)) && credit_card / power(10, len(credit_card) - 1) == 4) printf("VISA\n");
    else if (len(credit_card) == 16 && (credit_card / credit_card / power(10, len(credit_card) - 2) >= 51 || credit_card / power(10, len(credit_card) - 2) <= 55)) printf("MASTERCARD\n");
    else printf("INVALID\n");
}

long power(int a, int b)
{
    long res = 1;
    for(int i = 0; i < b; i++)
    {
        res = res * a;
    }
    return res;
}