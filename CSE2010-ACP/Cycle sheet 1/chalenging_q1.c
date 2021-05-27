#include <stdio.h>
#include <stdlib.h>
#define N 27

// Write a C program to display alphabets as given below
// az by cx dw ev fu gt hs ir
// jq kp lo mn nm ol pk qj ri
// sh tg uf ve wd xc yb za

int main()
{
    char alpha[N] = "abcdefghijklmnopqrstuvwxyz";
    int l, i, j, status, step;

    printf("Enter number of lines you want to print: ");
    status = scanf("%d", &l);

    // Line number validation. Max we can print 26 lines
    while(status == 0 && l >= N)
    {
        printf("Please enter a valid input (natural number less than 27): ");
        fflush(stdin);
        status = scanf("%d", &l);
    }

    step = (N-1)/l;
    printf("%d\n\n", step);

    for(i = 0; i < l; i++)
    {
        // (i-1) because i starts at 1 and index in array starts at 0
        // (i-1)*(step+1) because we need line starting index not line ending
        // +step because those many more numbers will be printed
        // alpha[j] and alpha[N-2-j] because opp alphas are printed and
        // 26 alphas are there (0 - 25) index

        if((N-1) % l == 0)
        {
           for(j = i*(step); j <= (i*(step) + step - 1) && j <= 25; j++)
            {
                printf("%c%c ", alpha[j], alpha[N-2-j]);
            }
        }

        else
        {
            for(j = i*(step + 1); j <= (i*(step + 1) + step) && j <= 25; j++)
            {
                printf("%c%c ", alpha[j], alpha[N-2-j]);
            }
        }

        printf("\n");
    }

    return 0;
}
