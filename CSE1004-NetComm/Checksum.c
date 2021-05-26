#include<stdio.h>
#include<math.h>

void doSender();
void doReceiver();

void main() {
	doSender();
	doReceiver();
}

void doSender() {
	char data[100], hexData[100];
	int dataLen, dataVals[100], concatData[100];
	int i, total = 0;

	printf("Enter data length: ");
	scanf("%d", &dataLen);

	printf("\nEnter data: ");
	// for(i = 0; i < dataLen; i++)
	scanf("%s", data);
	
	if(dataLen % 2 != 0) {
		data[dataLen++] = 'X';
	}

	for(i = 0; i < dataLen; i++) {
		dataVals[i] = (int)data[i];
		// printf("%c - %d\n", data[i], (int)data[i]);
	}

	for(i = 0; i < dataLen - 1; i += 2) {
		// concatData[i] = dataVals[i] * pow(10, (int)log10(dataVals[i+1])+1) + dataVals[i + 1];
		concatData[i/2] = dataVals[i] * pow(10, 3) + dataVals[i + 1];
		printf("%c%c - %d\n", data[i], data[i+1], concatData[i/2]);
	}

	for(i = 0; i < dataLen / 2; i++) {
		total += concatData[i];
	}
	printf("Total = %d\n", total);

	int carry = total / (int)pow(10, 6);
	printf("Carry = %d\n", carry);

	int partial = total - carry * pow(10, 6);
	int final = partial + carry;
	int checksum = 999999 - final;

	printf("Partial = %d\nFinal = %d\nChecksum = %d\n", partial, final, checksum);
	printf("Checksum value = %c%c\n", (char)(checksum / (int)pow(10, 3)), (char)(checksum % (int)pow(10, 3)));

}

void doReceiver() {
	char data[100], hexData[100];
	int dataLen, dataVals[100], concatData[100];
	int i, total = 0, checksumInp;

	printf("Enter data length: ");
	scanf("%d", &dataLen);

	printf("\nEnter data: ");
	scanf("%s", data);

	printf("\nEnter Checksum decimal value: ");
	scanf("%d", &checksumInp);
	total += checksumInp;
	
	if(dataLen % 2 != 0) {
		data[dataLen++] = 'X';
	}

	for(i = 0; i < dataLen; i++) {
		dataVals[i] = (int)data[i];
		// printf("%c - %d\n", data[i], (int)data[i]);
	}

	for(i = 0; i < dataLen - 1; i += 2) {
		// concatData[i] = dataVals[i] * pow(10, (int)log10(dataVals[i+1])+1) + dataVals[i + 1];
		concatData[i/2] = dataVals[i] * pow(10, 3) + dataVals[i + 1];
		printf("%c%c - %d\n", data[i], data[i+1], concatData[i/2]);
	}

	for(i = 0; i < dataLen / 2; i++) {
		total += concatData[i];
	}
	printf("Total = %d\n", total);

	int carry = total / (int)pow(10, 6);
	printf("Carry = %d\n", carry);

	int partial = total - carry * pow(10, 6);
	int final = partial + carry;
	int checksum = 999999 - final;

	printf("Partial = %d\nFinal = %d\nChecksum = %d\n", partial, final, checksum);
	// printf("Checksum value = %c%c\n", (checksum / (int)pow(10, 3)), (checksum % (int)pow(10, 3)));
}
