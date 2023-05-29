#include <cs50.h>
#include <stdio.h>

void spaces(int n);
void blocks(int n);

int main(void)
{
    int height;
    do
    {
        printf("height: ");
        int nb_read = scanf("%d", &height);
        while (nb_read != 1)
        {
            printf("thats not a number!\ntry again: ");
            scanf("%*[^\n]");
            nb_read = scanf("%d", &height);
        }
    }
    while (height < 1 || height > 9);

    for (int i = 1; i <= height; i++)
    {
        spaces(height - i);
        blocks(i);
        printf("  ");
        blocks(i);
        printf("\n");
    }
}

void spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void blocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}