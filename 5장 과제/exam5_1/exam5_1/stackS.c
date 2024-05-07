#include <stdio.h>
#include <string.h>
#include "stackS.h"

int top = -1;

int isStackEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isStackFull() {
	if (top == STACK_SIZE-1) return 1;
	else return 0;
}

void push(element item) {
	if (isStackFull() == 1) {
		printf("Stack is full \n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

element pop() {
	if (isStackEmpty() == 1) {
		printf("Stack is empty \n");
		return 0;
	}
	else {
		return stack[top--];
	}
}

element peek() {
	if (isStackEmpty() == 1) {
		printf("Stack is empty \n");
		exit(1);
	}
	else return stack[top];
}

void printStack() {
	printf("\n Stack [ ");
	for (int i=0; i < (top+1); i++) {
		printf("%d ", stack[i]);
	}
	printf("] ");
}