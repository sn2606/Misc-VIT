#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define P 3

// C program to  read 3 digit numbers and print the digits in words using switch case

int main()
{
    int arr[P], n, i, r, w;
    int status, temp;

    printf("Enter 3 digit number: ");
    status = scanf("%d", &n); // Reading a three digit number, and storing the status of scanf
    // scanf() returns a value indicating how well the string matched the format passed,
    // i.e. how many parameters were successfully filled with data.

    // If status is not 1, or status is 1 but number is not 3 digit are failure cases
    while(status!=1 || n < 100 || n > 999)
    {
		while((temp=getchar()) != EOF && temp != '\n'); // It creates an infinite loop otherwise
		printf("Invalid input... please enter a three digit number: ");
		fflush(stdin); // Flushing the input, just for good measure
		status = scanf("%d", &n);
	}

    w = n; // Not manipulating value of input is a good practice

    // Creating an array of digits in the number in order

    for(i = 0; i < P; i++)
    {
        r = w % 10;
        arr[P-i-1] = r;
        w /= 10;
    }

    for(i = 0; i < P; i++) // Looping over digits in order
    {
        switch(arr[i]) // Using Switch statement to print name of digit
        {
        case 1:
            printf("One ");
            break;
        case 2:
            printf("Two ");
            break;
        case 3:
            printf("Three ");
            break;
        case 4:
            printf("Four ");
            break;
        case 5:
            printf("Five ");
            break;
        case 6:
            printf("Six ");
            break;
        case 7:
            printf("Seven ");
            break;
        case 8:
            printf("Eight ");
            break;
        case 9:
            printf("Nine ");
            break;
        case 0:
            printf("Zero ");
            break;
        default:
            break;
        } // Switch ends here
    } // For ends here

    return 0;
}
