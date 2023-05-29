// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <stdlib.h>
#include <stdio.h>

unsigned int valid(char *password);

int main(void)
{
    char *password = malloc(sizeof(char) * 100);
    printf("Enter your password: ");
    scanf("%[^\n]s", password);
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
unsigned int valid(char *password)
{
    int ul = 0;
    int ll = 0;
    int num = 0;
    int c = 0;
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z') ul = 1;
        else if (password[i] >= 'a' && password[i] <= 'z') ll = 1;
        else if (password[i] >= '0' && password[i] <= '9') num = 1;
        else c = 1;
    }
    return ul && ll && num && c;
}
