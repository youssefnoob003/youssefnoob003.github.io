//Convertit un nombre de la base decimal vers une autre base.

#include <stdio.h>

long conv(int n, int base);

int main()
{
    int n, b;
    printf("donnez un entier: ");
    scanf("%i", &n);
    printf("donnez la base: ");
    scanf("%i", &b);
    printf("conversion : %li \n", conv(n, b));
}

long conv(int n, int base)
{
    if (n < base) return n;

    else return n % base + 10 * conv(n / base, base);
}