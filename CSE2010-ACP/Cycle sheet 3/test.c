# include <stdio.h>
# include <stdlib.h>
# define N 50

void decimal_to_n(int num, int n);

int main()
{
    int num = 9;
    int n = 10;

    decimal_to_n(num, n);

    return 0;
}

// Function to convert the number from base 10 to base n
// Where 1 < n <= 16
// Input is decimal number n
void decimal_to_n(int num, int n)
{
    char residue[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char c[N], converted[N];
    int i = 0, j, rem, temp;

    while (num != 0)
    {
        rem = num % n;
        c[i] = residue[rem];
        num /= n;
        i++;
    }

    printf("i = %d\n", i);

    c[i] = '\0';
    converted[i] = '\0';

    for(j = 0; c[j] != '\0'; j++)
    {
        converted[i-1-j] = c[j];
    }

    printf("%s\n", c);        
}