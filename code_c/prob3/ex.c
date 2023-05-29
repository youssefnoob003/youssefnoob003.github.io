//Find the longest palindromic substring in a given input string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is palindromic
int is_palindrome(char *string);

// Function to find the longest palindromic substring
void longest_palindrome(char *string);

int main()
{
    // String input
    char *string = malloc(sizeof(char) * 1000);
    printf("Input: ");
    scanf("%s", string);

    // Execute main function
    longest_palindrome(string);

    // Free allocated memory
    free(string);

    return 0;
}

int is_palindrome(char *string)
{
    // Get the length of the input string
    int n = strlen(string);

    // Loop to compare symmetric characters in the string
    for (int i = 0; i < n / 2; i++)
    {
        if (string[i] != string[n - 1 - i])
        {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

void longest_palindrome(char *string)
{
    // Initialize variables
    char *longest_palindromic_substring = malloc(sizeof(string));
    int n = strlen(string);
    int max_length = 0;

    // Loop through each character in the string
    for (int i = 0; i < n - 1; i++)
    {
        // Create temporary substring starting from index i
        char *tmp = malloc(sizeof(string));
        int tmp_length = 2;

        tmp[0] = string[i];
        tmp[1] = string[i + 1];

        // Extend the temporary substring until it is no longer palindromic or reaches the end of the string
        while (tmp_length < n - i && is_palindrome(tmp) == 1)
        {
            tmp[tmp_length] = string[i + tmp_length];
            tmp_length++;
        }

        // Check if the resultant substring is palindromic
        if (is_palindrome(tmp) == 1)
        {
            // Check if it is the longest substring so far
            if (tmp_length > max_length)
            {
                max_length = tmp_length;
                strcpy(longest_palindromic_substring, tmp);
            }
        }

        // Free memory for tmp to avoid memory errors
        free(tmp);
    }

    printf("Longest palindromic substring: %s\n", longest_palindromic_substring);

    free(longest_palindromic_substring);
}
