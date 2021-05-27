#include <stdio.h>
#include <stdlib.h>
#define N 101

int main()
{
    char s1[N];
    char ch;
    int i, count, min, max = 0;
    int char_freq[256] = {0};

    printf("Enter the string: ");
    fgets(s1,N-1,stdin);
	
	// Incrementing values in the ascii array
    for(i = 0; s1[i] != '\0'; i++)
    {
        char_freq[s1[i]]++;
    }

	// Finding the maximum char occurrence
	// At 33, the actual characters start, before that -> whitespace etc.
    for(i = 33; i<256; i++)
    {
        if(char_freq[i] > char_freq[max])
            max = i;
    }

    printf("The maximum occurring character is: %c.\n", max);
	
	// Finding the minimum char occurrence
    min = max;
    for(i = 33; i<256; i++)
    {
        if(char_freq[i] < char_freq[min] && char_freq[i] > 0)
            min = i;
    }

    printf("The minimum occurring character is: %c.\n", min);

	// P A R T 	II
	
    printf("\nEnter the character whose occurrence you want to find: ");
    scanf("%c", &ch);

    if(char_freq[ch] == 0)
        printf("This character has not occurred in the string.");
    else if(ch >= 65 && ch <= 90) // for capital alphabets
    {
        printf("[CASE SENSITIVE] %c has occurred %d times.\n", ch, char_freq[ch]);
        printf("[NOT CASE SENSITIVE] %c has occurred %d times.\n", ch, char_freq[ch] + char_freq[ch + 32]);
    }
    else if(ch >= 97 && ch <= 122)	// for small alphabets
    {
        printf("[CASE SENSITIVE] %c has occurred %d times.\n", ch, char_freq[ch]);
        printf("[NOT CASE SENSITIVE] %c has occurred %d times.\n", ch, char_freq[ch] + char_freq[ch + 32]);
    }
    else	// for other alphabets
        printf("%c has occurred %d times.\n", ch, char_freq[ch]);

    return 0;
}
