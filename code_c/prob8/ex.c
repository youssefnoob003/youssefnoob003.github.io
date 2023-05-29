//Generating all possible combinations of balanced parentheses using a backtracking approach.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comb(int n);
void rev(char *ch);
void swap(char *a, char *b);

int main()
{
    int n;
    scanf("%i", &n);
    comb(n);
    return 0;
}

void comb(int n)
{
    char *ch = malloc(sizeof(char) * n * 2 + 1);

    // Generate the initial string with balanced parentheses
    for (int i = 0; i < n; i++)
    {
        ch[i] = '(';
        ch[n * 2 - 1 - i] = ')';
    }
    printf("%s\n", ch);

    // Generate all combinations by swapping parentheses pairs
    for (int i = 1; i < n; i++)
    {
        for (int j = n; j < n * 2 - 1; j++)
        {
            char *tmp = malloc(sizeof(char) * n * 2 + 1);
            strcpy(tmp, ch);
            swap(tmp + i, tmp + j);
            printf("%s\n", tmp);
            rev(tmp);
            free(tmp);
        }
    }

    free(ch);
}

void swap(char *a, char *b)
{
    // Swap the values of two characters
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void rev(char *ch)
{
    int n = strlen(ch);
    // TODO: Implement the code for reversing the string `ch`.
    // This function is currently empty.
    printf("\n");
}
