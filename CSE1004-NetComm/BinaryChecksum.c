#include<stdio.h>

void doSender();
void doReceiver();

int rows;
#define cols 8

int data[100][cols];

void main() {
	doSender();
	doReceiver();
}

void doSender() {
	int i, j;

	printf("Enter the number of data rows: ");
	scanf("%d", &rows);

	printf("Enter data row by row (Separated by space):\n");
	for(i = 0; i < rows; i++)
		for(j = 0 ; j < cols; j++)
			scanf("%d", &data[i][j]);

			
}

void doReceiver() {

}