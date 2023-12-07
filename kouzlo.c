#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define INITIAL_CAPACITY 5
#define MAX_LEN 100 

char* toLower(char *str) 
{
    char *ptr = str;
    while (*ptr)
    {
        *ptr = tolower(*ptr);
        ptr++;
    }
    return str;
}

bool containsMoreSameWords(char *str[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            char lower_str1[MAX_LEN];
            char lower_str2[MAX_LEN];

            strcpy(lower_str1, str[i]);
            strcpy(lower_str2, str[j]);

            toLower(lower_str1);
            toLower(lower_str2);

            if (strcmp(lower_str1, lower_str2) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool containsNonLetters(const char *str)
{
    while (*str)
    {
        if (!isalpha(*str))
        {
            return true; // Non-letter character found
        }
        str++;
    }
    return false; // Only letters in the string
}

char *maxStr(char *x, char *y)
{
    if (strcmp(x, y) > 0)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void compareStrings(char *s1, char *s2, int *idx)
{
    char *max_str = maxStr(s1, s2);
    for (int i = 0; max_str[i] != '\0'; i++)
    {
        // If s1 is greater than s2
        if (tolower(s1[i]) > tolower(s2[i]))
        {
            // Update idx to the index of the smaller string
            *idx = 1;
            return;
        }
        // If s2 is greater than s1
        else if (tolower(s2[i]) > tolower(s1[i]))
        {
            // Update idx to the index of the smaller string
            *idx = 0;
            return;
        }
    }
    // If both strings are equal, set idx to -1
    *idx = -1;
}

void selectionSort(char **arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            int result;
            compareStrings(arr[min_idx], arr[j], &result);

            // If arr[j] is lexicographically smaller, update min_idx
            if (result == 1)
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i)
        {
            char *temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main()
{

    char **matrix = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    int rows = 0;

    char input[MAX_LEN];

    printf("Enter elements (type 'Ctrl+D' to end input):\n");
    while (true)
    {
        int conversions = scanf(" %s", input);

        if (conversions == EOF)
        {
            break;
        }

        if (rows >= INITIAL_CAPACITY)
        {
            matrix = realloc(matrix, (rows + 1) * sizeof(char *));
        }

        matrix[rows] = (char *)malloc(strlen(input) + 1);
        strcpy(matrix[rows], input);

        rows++;
    }

    if (containsNonLetters(input) || containsMoreSameWords(matrix, rows))
    {
        printf("Nespravny vstup.");
        return;
    }

    selectionSort(matrix, rows);

    printf("\nSorted Matrix:\n");
    for (int i = rows - 1; i >= 0; i--)
    {
        printf("%s ", matrix[i]);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
