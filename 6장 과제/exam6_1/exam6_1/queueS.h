#pragma once
#define Q_SIZE 4
typedef char element; // 걍 char를 element로 하겠다.

typedef struct { // 시험에 나옴[중요*]
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue();
int isQueueEmpty(QueueType* Q);
int isQueueFull(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
element peekQ(QueueType* Q);
void printQ(QueueType* Q);