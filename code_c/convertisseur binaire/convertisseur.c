#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int convertir_decimal(int *t, int n);

// Function to calculate power of a number
int puissance(int a, int b);

// Function to take input from the user
void saisie(char **tab, int n);

// Function to convert a string of binary digits to an integer array
void chaine_binaire(char *ch, int *t);

// Function to display the decimal conversions
void affichage(char **tab, int n);

int main()
{
    int n;
    printf("Donnez la longueur du tableau : ");
    scanf("%i", &n);

    // Allocate memory for the array of strings
    char **tab = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        *(tab + i) = malloc(sizeof(char) * 100);
    }

    // Input binary strings from the user
    saisie(tab, n);

    // Display decimal conversions
    affichage(tab, n);

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(*(tab + i));
    }
    free(tab);

    return 0;
}

int convertir_decimal(int *t, int n)
{
    int res = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        res = res + t[i] * puissance(2, n - 1 - i);
    }
    return res;
}

int puissance(int a, int b)
{
    int res = 1;
    if (b == 0)
    {
        return 1;
    }
    for (int i = 0; i < b; i++)
    {
        res = res * a;
    }
    return res;
}

void saisie(char **tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Donnez T[%i]: ", i);
        scanf("%s", *(tab + i));
    }
}

void chaine_binaire(char *ch, int *t)
{
    int n = strlen(ch);
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == '1')
        {
            t[i] = 1;
        }
        else
        {
            t[i] = 0;
        }
    }
}

void affichage(char **tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        int *tmp = malloc(sizeof(int) * 100);
        chaine_binaire(*(tab + i), tmp);
        int res = convertir_decimal(tmp, strlen(*(tab + i)));
        printf("%i\n", res);
        free(tmp);
    }
}
