#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int count_letters(char *sentence);
int count_words(char *sentence);
int count_phrases(char *sentence);

int main(void)
{
    char *text = malloc(sizeof(char) * 100);
    printf("Text: ");
    scanf("%[^\n]", text);

    float L = ((float)count_letters(text) / count_words(text)) * 100;
    float S = ((float)count_phrases(text) / count_words(text)) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1) printf("Before Grade 1\n");
    else if (index > 16) printf("Grade 16+\n");
    else printf("Grade %i\n", (int)round(index));
}

int count_letters(char *sentence)
{
    int n = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (toupper(sentence[i]) >= 'A' && toupper(sentence[i]) <= 'Z') n++;
    }
    return n;
}

int count_words(char *sentence)
{
    int n = 0;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ') n++;
    }
    return n + 1;
}

int count_phrases(char *sentence)
{
    int n = 0;

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!' || sentence[i] == ';') n++;
    }
    return n;
}
