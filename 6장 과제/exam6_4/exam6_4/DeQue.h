#pragma once
typedef char element;

typedef struct DQNode{
	element data;
	struct DQNode* llink;
	struct DQNode* rlink;
}DQNode;

typedef struct DQue{
	DQNode* front;
	DQNode* rear;
}DQue;

DQue* createQueue();
int isDeQueEmpty(DQue* DQ);
void insertFront(DQue* DQ, element item);
void insertRear(DQue* DQ, element item);
element deleteFront(DQue* DQ);
element deleteRear(DQue* DQ);
element peekFront(DQue* DQ);
element peekRear(DQue* DQ);
void printDQ(DQue* DQ);