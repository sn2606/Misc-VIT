#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int doReceiver();
int doSender();

void main() {
	int frameCount, count = 0;
	int i, send, rcv, hold = 0, data;

	printf("Enter number of frames to send: ");
	scanf("%d", &frameCount);

	for(i = 0; i < frameCount;) {
		printf("\nFrame %d\n", i);
		if(!hold)
			data = rand();
		printf("Sending data = %d\n", data);
		send = doSender(data);
		if(send == -1) {
			printf("Data Lost, sending frame %d again\n", i);
			hold = 1;
			continue;
		}
		rcv = doReceiver(send);
		if(rcv == -1) {
			printf("Ack Lost, sending frame %d again\n", i);
			hold = 1;
		} else {
			printf("Received Data = %d\n", rcv);
			i++;
			hold = 0;
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
		case 2: return -1;
		default: return data;
	}
}

int doReceiver(int data) {
	int choice;
	if(data == -1) {
		printf("Frame lost\n");
		return -1;
	}

	printf("What would you like to do?\n");
	printf("1 - Receive Data\n");
	printf("2 - Ack Lost\n");
	scanf("%d", &choice);

	switch(choice) {
		case 2: return -1;
		default: return data;
	}
}