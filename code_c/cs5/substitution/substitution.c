#include <string.h>
#include <stdio.h>
#include <ctype.h>

unsigned int checker(char *key); // checks for key validity
char replace(char c, char *key); // replaces a character with its corresponding crypted character

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (checker(key) != 1)
    {
        printf("Key must contain 26 unique letters.\n");
        return 1;
    }

    // user input
    char text[100];
    printf("plaintext: ");
    scanf("%[^\n]s", text);

    // output
    printf("ciphertext: ");
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", replace(text[i], key)); // prints out each crypted char
    }
    printf("\n");
}

unsigned int checker(char *key)
{

    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            return 0; // returns 0 if a non letter found
        }
        for (int j = i + 1; key[j] != '\0'; j++)
        {
            if (key[i] == key[j])
            {
                return 0; // checks for duplicates
            }
        }
    }

    return 1;
}

char replace(char c, char *key)
{
    if (isalpha(c) == 0)
    {
        return c; // returns c unchanged if it's not a letter
    }
    if (isupper(c))
    {
        return toupper(key[toupper(c) - 65]); // handles uppercase letter
    }
    else
    {
        return tolower(key[toupper(c) - 65]); // handles lowercase letter
    }
}