//Checking the validity of a string containing parentheses, brackets, and braces.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int checker(char *string);

int main()
{
    char *string = malloc(sizeof(char) * 100);
    scanf("%s", string);
    unsigned int check = checker(string);

    if (check)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    free(string);
    return 0;
}

unsigned int checker(char *string)
{
    int n = strlen(string);

    char *T = malloc(sizeof(char) * n);
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (string[i] == '{' || string[i] == '(' || string[i] == '[')
        {
            T[j] = string[i];
            j++;
        }
        else if (string[i] == '}' || string[i] == ')' || string[i] == ']')
        {
            if (!(string[i] - T[j - 1] == 1 || string[i] - T[j - 1] == 2))
            {
                free(T);
                return 0;
            }
            j--;
        }
    }
    free(T);
    return (j == 0);
}
