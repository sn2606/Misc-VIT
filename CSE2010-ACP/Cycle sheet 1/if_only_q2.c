#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Write a program which takes a character input and checks whether it is vowel or consonant

int main()
{
    char a;
    printf("Enter a character: ");
    scanf("%c", &a);
	
	int l,u;
	
	l = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
	u = (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');

    	
	if(l || u)
    {
        printf("Character entered is a vowel.");
    }
	
    if((l || u) == 0)
    {
		if(isalpha(a))
		{
			printf("Character is a consonant.");
		}
        
		if(isalpha(a) == 0)
		{	
			printf("Character is neither a vowel nor a consonant.");
		}
    }


    return 0;
}
