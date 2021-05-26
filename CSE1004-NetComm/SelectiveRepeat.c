#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int doReceiver();
int doSender();

int sent[100];
int flag[100];
int expected = 0;
int windowPos = 0;
int window;
int frameCount;

void main() {
	int data[100];
	int i, j = 0, send, rcv, k;

	printf("Enter window size: ");
	scanf("%d", &window);

	printf("Enter number of frames to send: ");
	scanf("%d", &frameCount);

	for(i = 0; i < frameCount; i++) {
		data[i] = rand()/2000000;
	}

	for(i = 0; i < frameCount; i++) {
		printf("%d\t", data[i]);
		flag[i] = -1;
	}

	while(j < frameCount) {
		printf("\n\nSending Frames %d-%d\n", windowPos, windowPos+window-1);
		int retry = 1;

		// Initially Send Data
		for(i = windowPos; i < windowPos + window && i < frameCount; i++) {
			if(flag[i] < 0) {
				printf("Sending data = (%d)%d\n", i, data[i]);
				sent[i] = doSender(data[i]);
			}
			if(sent[i] < 0) flag[i] = -1;
			else flag[i] = 0;
		}

		// Receive Data
		for(i = 0; i < frameCount; i++)
			printf("%d\t", flag[i]);
		printf("\n");	

		for(i = windowPos; i < windowPos + window && i < frameCount; i++) {
			if(flag[i] == 1) continue;
			else if(flag[i] == 0) {
				printf("\nReceiving data = %d\n", data[i]);
				sent[i] = doReceiver(data[i]);
				if(sent[i] < 0) flag[i] = -1;
				else flag[i] = 1;
			} else {
				printf("Data %d not received\n", i);
			}
		}

		k = windowPos;
		for(i = k; i < k + window && i < frameCount; i++) {
			if(flag[i] == 1) {windowPos++; j++;}
			else break;
		}

		for(i = k; i < k + window && i < frameCount; i++) {
			if(flag[i] < 1) {retry = 1; break;}
			else retry = 0;
		}
	}
}

int doSender(int data) {
	int choice;
	printf("What would you like to do?\n");
	printf("1 - Send Data\n");
	printf("2 - Send and Lose Data\n");
	scanf("%d", &choice);

	switch(choice) {
		case 2: return -1*data;
		default: return data;
	}
}

int doReceiver(int data) {
	if(data < 0)
		return data;

	int choice;
	printf("What would you like to do?\n");
	printf("1 - Send back ACK\n");
	printf("2 - Send back NACK\n");
	scanf("%d", &choice);

	switch(choice) {
		case 2: return -1*data;
		default: return data;
	}
}