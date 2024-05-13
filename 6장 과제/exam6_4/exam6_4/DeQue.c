#include <stdio.h>
#include <stdlib.h>
#include "DeQue.h"

DQue* createQueue() {
	DQue* DQ;
	DQ = (DQue*)malloc(sizeof(DQue));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isDeQueEmpty(DQue* DQ) {
	if (DQ->front == NULL) return 1;
	else return 0;
}

void insertFront(DQue* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQueEmpty(DQ)) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}

void insertRear(DQue* DQ, element item) {
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDeQueEmpty(DQ)) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

element deleteFront(DQue* DQ) {
	DQNode* old = DQ->front;
	element item;
	if (isDeQueEmpty(DQ)) {
		printf(" DeQue is empty! ");
		return;
	}
	else {
		item = old->data;
		if (DQ->front->rlink == NULL) {		// 삭제할 노드가 유일한 Queue 내의 node일 때
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

element deleteRear(DQue* DQ) {
	DQNode* old = DQ->rear;
	element item;
	if (isDeQueEmpty(DQ)) {
		printf(" DeQue is empty! ");
		return;
	}
	else {
		item = old->data;
		if(DQ->rear->llink==NULL){		// 삭제할 노드가 유일한 Queue 내의 node일 떄
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

element peekFront(DQue* DQ) {
	element item;
	if (isDeQueEmpty(DQ)) {
		printf(" DeQue is empty! ");
		return;
	}
	else {
		item = DQ->front->data;
		return item;
	}
}

element peekRear(DQue* DQ) {
	element item;
	if (isDeQueEmpty(DQ)) {
		printf(" DeQue is empty! ");
		return;
	}
	else {
		item = DQ->rear->data;
		return item;
	}
}

void printDQ(DQue* DQ) {
	DQNode* temp = DQ->front;
	printf("DeQue: [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf("  ]");
}