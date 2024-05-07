#include <stdio.h>
#include "StackL.h"

int main() {
	element item;
	top = NULL;
	printf("\n** 순차 스택 연산 **\n");
	printStack();

	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("peek=>%d", item);
	item = pop(); printStack();
	printf("\t pop->%d", item);
	item = pop(); printStack();
	printf("\t pop->%d", item);
	item = pop(); printStack();
	printf("\t pop->%d", item);
	getchar(); return 0;
}