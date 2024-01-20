#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generateRandomNumber(int upper) 
{
    return rand() % upper + 1;
}

int main () 
{
    int dice_size;
    char response;

    srand(time(NULL));

    while (true)
    {
        printf("Enter dice size: "); 

        if (scanf("%d", &dice_size) != 1) 
        {
            printf("Wrong input. Try once again.\n");
            scanf("%*s"); // Clear input buffer

            printf("Do you want to continue? (y/n): ");
            scanf(" %c", &response); // Use %c to read a single character

            if (response == 'y' || response == 'Y') 
            {
                continue;
            }
            else
            {
                break;
            }
        }

        int random_number = generateRandomNumber(dice_size);
        printf("You've got %d\n", random_number);
    }

    return 0; 
}
