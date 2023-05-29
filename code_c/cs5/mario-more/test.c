#include <stdio.h>

int main()
{
    int a;
    do
    {
        a = 0;
        scanf("%i", &a);
    }while (a == 0);
    printf("%i\n", a);
}