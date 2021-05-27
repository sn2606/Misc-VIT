#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define P 10

// C program to  read 3 digit numbers and print the digits in words using switch case

int main()
{
    int count[P] = {0};
    int i, option, s;
    char c;

    printf("Enter a digit between 0 to 9 or enter q if you want to quit.\n");

    do
    {
        SCAN: printf("\nEnter the command: "); //statement scan
        fflush(stdin);
        s = scanf("%d", &option); // status of scan

        while(s == 0)
        {
            printf("Invalid Entry! Enter digits please!\n");
            goto SCAN;
        }

        switch(option) // Using Switch increase the count of digit entered in array
        {
        case 0:
            count[0]++;
            break;
        case 1:
            count[1]++;
            break;
        case 2:
            count[2]++;
            break;
        case 3:
            count[3]++;
            break;
        case 4:
            count[4]++;
            break;
        case 5:
            count[5]++;
            break;
        case 6:
            count[6]++;
            break;
        case 7:
            count[7]++;
            break;
        case 8:
            count[8]++;
            break;
        case 9:
            count[9]++;
            break;
        default:
			printf("\nInvalid entry!\n\n");
            break;
            }   // Switch ends here
        printf("\nDo you want to continue?(Yes/No): ");
        fflush(stdin);
        scanf("%c", &c);
        c = tolower(c);

    }while(c != 'n'); // Do while loop ends here


    for(i = 0; i < P; i++)
    {
        if(count[i] != 0)
            printf("Count of digit %d is %d.\n", i, count[i]); // Printing the count
    }

    return 0;
}
