//this code takes as input from the user an array of strings, each string is then converted
//character by character to its equivalent ascii number taken in an array, then printed

//declaring libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring functions
void get_array(char **array, int len);
void string_ascii(char *ch);//converts a string to an array of ascii numbers and prints it
void array_ascii(char **array, int n);//converts each string to an array of ascii numbers
void tab_aff(int *tab, int n);//prints an array of ints

int main()
{
    //initiating variables
    //n: lengh of the input array
    int n;
    printf("length of the array: ");
    scanf("%i", &n);

    //array input
    //allocating memory
    char **array = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        *(array + i) = malloc(sizeof(char) * 100);
    }
    
    //user input
    get_array(array, n);

    //main function
    array_ascii(array, n);

    //freeing memory
    for (int i = 0; i < n; i++)
    {
        free(*(array + i));
    }

    free(array);

    return 0;

}

void get_array(char **array, int len)
{  
    for (int i = 0; i < len; i++)
    {
        printf("input array[%i]: ", i);
        scanf("%s", *(array + i));
    }
}

void string_ascii(char *ch)
{
    //declaring local variables
    //n: length of the string ch
    int n = strlen(ch);

    //tab of the ascii numbers
    int *tab = malloc(sizeof(int) * n);

    //main loop
    for (int i = 0; i < n; i++)
    {
        tab[i] = (int) ch[i];
    }

    //printing tab
    tab_aff(tab, n);

    //freeing memory
    free(tab);
}

void tab_aff(int *tab, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", *(tab + i));
    }
    printf("]\n");
}

void array_ascii(char **array, int n)
{
    //looping through each string and executing the string_ascii function
    for (int i = 0; i < n; i++)
    {
        string_ascii(*(array + i));
    }
}