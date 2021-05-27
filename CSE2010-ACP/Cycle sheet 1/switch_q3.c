#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Write a menu driven program to perform mathematical functions like,
// 1.sin(x), 2.cos(x), 3.tan(x), 4.log(x), 5.log10(x), 6.sqrt(x).
// Using switch case. Read x from the user

int main()
{
    float x;
    int option;
    char c;

    printf("Enter the value of x: ");
    scanf("%f", &x); // Reading the floating point number

    // Giving menu
    printf("Enter the option:\n1. sin(x)\n2. cos(x)\n3. tan(x)\n4. log(x)\n5. log10(x)\n6. sqrt(x)");

    do{
        printf("\nEnter option number: ");
        scanf("%d", &option); // Reading the option

        switch(option)
            {                // Beginning switch statement
            case 1:
                printf("sin(x) = %f\n", sin(x));
                break;
            case 2:
                printf("cos(x) = %f\n", cos(x));
                break;
            case 3:
                printf("tan(x) = %f\n", tan(x));
                break;
            case 4:
                printf("log(x) = %f\n", log(x));
                break;
            case 5:
                printf("log10(x) = %f\n", log10(x));
                break;
            case 6:
                printf("sqrt(x) = %f\n", sqrt(x));
                break;
            default:
                printf("Invalid option!");
                break;
            }                  // End of switch statement

            printf("\nDo you want to continue?(y/n): "); // If the user wishes to stop?
            fflush(stdin);
            scanf("%c", &c);
            c = tolower(c);

        }while(c != 'n');       // End of do-while loop

    END: return 0;             // END label and exit program
}
