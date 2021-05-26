#include<stdio.h>
#include<math.h>

/*
	Binary representation as 2^0 2^1 2^2 ....
	
	char b[cLen];
	int n = dataLen;
	for(i = 0; i < cLen; i++, n /= 2)
		b[i] = n % 2;
*/
void doSender();
void doReceiver();

void main() {
	int c;

	printf("All inputs in the form 1 2 .... n\n");
	printf("Choose an option: ");
	printf("\n1 - Sender Side");
	printf("\n2 - Receiver Side\n");
	scanf("%d", &c);

	switch(c) {
		case 1: doSender(); break;
		case 2: doReceiver(); break;
		default: printf("\nInvalid input"); return;
	}
} 

void doReceiver() {
	int data[100], parity[100];
	int i, j, n, ct = 0, p;
	int dataLen, cLen = 0;

	printf("Enter size of data: \n");
	scanf("%d", &dataLen);

	cLen = (int)(log(dataLen)/log(2)) + 1;
	printf("\nParity bits = %d", cLen);
	char b[cLen];

	printf("\nEnter %d bit data: \n", dataLen);
	for(i = 1; i <= dataLen; i++)
		scanf("%d", &data[i]);

	for(i = 0; i < cLen; i++)
		parity[i] = 0;

	for(i = 1; i <= dataLen; i++) {
		n = i;
		for(j = 0; j < cLen; j++, n /= 2)
			b[j] = n % 2;

		for(j = 0; j < cLen; j++)
			if(b[j]  == 1)
				parity[j] = parity[j] ^ data[i];
	}

	for(i = 0; i < cLen; i++)
		ct += (int)(pow(2, i) * parity[i]);
		
	printf("\nCT = %d\n", ct);

	if(ct == 0) {
		printf("No error\n");
	} else {
		printf("\nError on position %d", ct);
        
        printf("\nData received : ");
        for(i = 1; i <= dataLen; i++)
            printf("%d", data[i]);
        
        printf("\nCorrect message is:\n");
 
        //if errorneous bit is 0 we complement it else vice versa
        if(data[ct] == 0)
            data[ct] = 1;
        else
            data[ct] = 0;
        
        for (i = 1; i <= dataLen; i++) {
            printf("%d", data[i]);
        }
		printf("\n");
	}

}

void doSender() {
	int input[100], data[100];
	int i, j, d = 0, d1 = 1, n, ct, p;
	int dataLen, totalLen, cLen = 0;

	printf("Enter size of data: \n");
	scanf("%d", &dataLen);

	while(dataLen + cLen + 1 > pow(2, cLen))
		cLen++;
	totalLen = cLen + dataLen;
	printf("Parity Bits = %d", cLen);
	char b[cLen];

	printf("\nEnter %d bit data: \n", dataLen);
	for(i = 1; i <= dataLen; i++)
		scanf("%d", &input[i]);


	for(i = 1; i <= totalLen; i++) {
		if(i == pow(2, d)) {
			data[i] = 0;
			d++;
		}
		else {
			data[i] = input[d1];
			d1++;
		}
	}

	for(i = 1; i <= totalLen; i++) {
		n = i;
		for(j = 0; j < cLen; j++, n /= 2)
			b[j] = n % 2;

		for(j = 0; j < cLen; j++) {
			p = (int)pow(2, j);
			if(b[j]  == 1)
				data[p] = data[p] ^ data[i];
		}	
	}

	printf("\nHamming Code: \n");
	for(i = 1; i <= totalLen; i++)
		printf("%d", data[i]);

	printf("\nParity Bits: \n");
	for(j = 0; j < cLen; j++) {
		p = (int)pow(2, j);
		printf("P%d - %d\n", p, data[p]);
	}	

	printf("\n");
}