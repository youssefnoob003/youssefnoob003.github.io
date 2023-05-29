#include <stdio.h>
#include <string.h>

// Function declarations
char dernier(char *ch);
char *debut(char *ch);
char *ajoutF(char *ch, char c);
int len(char *ch);
int extrait(char *ch1, char *ch2);
int croissant(char *ch);
char *succ(char* ch);

int main()
{
    char ch1[100];
    scanf("%s", ch1);
    printf("%s\n", succ(ch1));
}

// Returns the last character of a string
char dernier(char *ch)
{
    return ch[strlen(ch) - 1];
}

// Removes the last character of a string
char *debut(char *ch)
{
    ch[strlen(ch) - 1] = '\0';
    return ch;
}

// Adds a character to the end of a string
char *ajoutF(char *ch, char c)
{
    ch[strlen(ch)] = c;
    return ch;
}

// Computes the length of a string
int len(char *ch)
{
    if (*ch == '\0')
        return 0;
    else
        return len(ch + 1) + 1;
}

// Checks if ch1 is an extraction of ch2
int extrait(char *ch1, char *ch2)
{
    if (*ch1 == '\0')
        return 1;
    else if (*ch2 == '\0')
        return 0;
    else if (dernier(ch1) == dernier(ch2)) 
        return extrait(debut(ch1), debut(ch2));
    else
        return extrait(ch1, debut(ch2));
}

// Checks if the characters in a string are in ascending order
int croissant(char *ch)
{
    if (len(ch) == 1)
    {
        return 1;
    }
    else if (dernier(ch) >= dernier(debut(ch)))
    {
        return croissant(ch);
    }
    else
        return 0;
}

// Generates the successor of a string representing a number
char *succ(char* ch)
{
    if (*ch == '\0')
    {
        *ch = '1';
        return ch;
    }
    else if (dernier(ch) < '9')
        return ajoutF(debut(ch), dernier(ch) + 1);
    else
        return ajoutF(succ(debut(ch)), '0');
}
