#include<stdio.h>

int doDivision();
void doSender();
void doReceiver();

void main() {
	int c;

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

void doSender() {
	int i, j, k;
	int data[100], divisor[100];

	int dataLen, divLen, fullLen;

	printf("\nSender Side:\n");

	printf("Enter Data length: ");
	scanf("%d", &dataLen);

	printf("Enter Divisor length: ");
	scanf("%d", &divLen);

	fullLen = dataLen + divLen - 1;

	printf("\nEnter %d Bit Data: \n", dataLen);
	for(i = 0; i < dataLen; i++)	
		scanf("%d", &data[i]);
	
	for(i = dataLen; i < fullLen; i++)
		data[i] = 0;	
		
	printf("Data: \n");
	for(i = 0; i < fullLen; i++)
		printf("%d", data[i]);
	
	printf("\nEnter %d bit Divisor: \n", divLen);
	for(i = 0; i < divLen; i++)
		scanf("%d", &divisor[i]);
		
	int rem = doDivision(dataLen, divLen, data, divisor);
}

void doReceiver() {
	int i, j, k;
	int data[100], divisor[100];

	int dataLen, divLen, fullLen;

	printf("\nReceiver Side:\n");

	printf("Enter Data length: ");
	scanf("%d", &dataLen);

	printf("Enter Divisor length: ");
	scanf("%d", &divLen);

	printf("\nEnter %d Bit Data: \n", dataLen);
	for(i = 0; i < dataLen; i++)	
		scanf("%d", &data[i]);	
		
	printf("Data: \n");
	for(i = 0; i < dataLen; i++)
		printf("%d", data[i]);
	
	printf("\nEnter %d bit Divisor: \n", divLen);
	for(i = 0; i < divLen; i++)
		scanf("%d", &divisor[i]);
		
	int rem = doDivision(dataLen, divLen, data, divisor);
	// printf("%d", rem);
	if(rem == 0)
		printf("\nNo error\n");
	else
		printf("\nError\n");
}

int doDivision(int dataLen, int divLen, int data[], int divisor[]) {
	int carry[100], div[100], dividend[100];
	int i, j, k;
	int rem = 0;

	for(i = 0; i < divLen; i++) {
		carry[i] = 0;
		div[i] = divisor[i];
		dividend[i] = data[i];
	}

	for(i = 0; i < dataLen; i++) {

		// printf("\nDividend: ");
		// for(j = 0; j < divLen; j++)
		// 	printf("%d", dividend[j]);

		// printf("\nDivisor: ");
		// for(j = 0; j < divLen; j++)
		// 	printf("%d", div[j]);


		for(j = 0; j < divLen - 1; j++) {
			if(dividend[j + 1] == div[j + 1])
				carry[j] = 0;
			else
				carry[j] = 1;
		}
		carry[divLen - 1] = data[i + divLen];

		if(i == dataLen - 1) {
			printf("\nRemainder: ");
			for(j = 0; j < divLen - 1; j++) {
				printf("%d", carry[j]);	
				rem *= 10;
				rem += carry[j];
			}	

			printf("\n");
		} else {
			// printf("\nCarry: ");
			// for(j = 0; j < divLen; j++)
			// 	printf("%d", carry[j]);	

			// printf("\n");
		}

		for(j = 0; j < divLen; j++) {
			dividend[j] = carry[j];
			carry[j] = 0;
		}

		if(dividend[0] == 0)
			for(j = 0; j < divLen; j++)
				div[j] = 0;
		else
			for(j = 0; j < divLen; j++)
				div[j] = divisor[j];		
	}

	return rem;
}