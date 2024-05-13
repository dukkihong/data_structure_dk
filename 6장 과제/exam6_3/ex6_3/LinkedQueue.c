#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

LQueue* createQueue() {
	LQueue* LQ;
	LQ = (LQueue*)malloc(sizeof(LQueue));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isLQEmpty(LQueue* LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

void enLQueue(LQueue* LQ, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deLQueue(LQueue* LQ) {
	QNode* old = LQ->front;
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL) {
			LQ->rear == NULL;
		}
		free(old);
		return item;
	}
}

element peekLQ(LQueue* LQ) {
	element item;
	if (isLQEmpty(LQ)) return;
	else {
		item = LQ->front->data;
		return item;
	}
}

void printLQ(LQueue* LQ) {
	QNode* temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf("  ]");
}