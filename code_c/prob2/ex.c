//Finding the length of the longest substring without repeating characters in a given input string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the length of the longest substring without repeating characters
int result(char *string);

int main()
{
    // String input
    char *string = malloc(sizeof(char) * 100);
    printf("Input: ");
    scanf("%s", string);

    // Execute main function
    int longestSubstringLength = result(string);

    // Display result
    printf("Length of the longest substring without repeating characters: %i\n", longestSubstringLength);

    // Free allocated memory
    free(string);

    return 0;
}

int result(char *string)
{
    // Variables initialization
    int longestLength = 0;  // The final result
    int currentLength = 0;  // Length of the current substring without repeating characters
    int n = strlen(string); // Length of the string

    // Loop through each character
    for (int i = 0; i < n; i++)
    {
        currentLength++;

        // Checking if there's a different character
        if (string[i] != string[i + 1])
        {
            // Checking if it's the longest substring
            if (currentLength > longestLength)
            {
                longestLength = currentLength;
            }

            // Resetting the counter
            currentLength = 0;
        }
    }

    return longestLength;
}
