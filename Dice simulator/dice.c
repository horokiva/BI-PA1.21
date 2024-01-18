#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generateRandomNumber(int upper) 
{
    srand(time(NULL));

    int random_number = (rand() % upper) + 1;

    return random_number;
}

int main () 
{
    int dice_size;
    char response;

    while (true)
    {
    
        printf("Enter dice size: "); 

        int conversion = scanf("%d", &dice_size);

        if (conversion == EOF) 
        {
            break;
        }
        if (conversion != 1) 
        {
            printf("Wrong input. Try once again.\n");
            scanf("%*s"); // Vycistenie vstupu

            printf("Do you want to continue: ");
            if (scanf("%s", &response) == "y") 
            {
                continue;
            }
        }

        int random_number = generateRandomNumber(dice_size);
        printf("You've got %d\n", random_number);
    }

    return 0; 
}
