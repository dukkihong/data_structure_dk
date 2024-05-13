#pragma once
typedef char element;

typedef struct QNode {
	element data;
	struct QNode* link;
}QNode;

typedef struct {
	QNode* front;
	QNode* rear;
}LQueue;

LQueue* createQueue();
int  isLQEmpty(LQueue* LQ);
void enLQueue(LQueue* LQ, element item);
element deLQueue(LQueue* LQ);
element peek(LQueue* LQ);
void printLQ(LQueue* LQ);