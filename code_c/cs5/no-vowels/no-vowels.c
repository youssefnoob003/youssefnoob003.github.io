// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <stdio.h>
#include <stdlib.h>

char replace(char c);
char *rep(char *w);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return -1;
    }
    char *word = argv[1];

    printf("%s\n", rep(word));
}

char replace(char c)
{
    switch (c)
    {
        case 'a': return '6';
        case 'e': return '3';
        case 'o': return '0';
        case 'i': return '1';
        default: return c;
    }
}

char *rep(char *w)
{
    char *res = malloc(sizeof(w));
    int i;
    for (i = 0; w[i] != '\0'; i++)
    {
        res[i] = replace(w[i]);
    }
    return res;
}