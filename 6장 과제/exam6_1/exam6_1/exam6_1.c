#include "queueS.h"
#include <stdio.h>

int main() {
	QueueType* Q1 = createQueue();
	element data;
	printf("\n ***** 순차 큐 연산 ***** \n");
	printf("\n 삽입A>>");
	enQueue(Q1, 'A');
	printQ(Q1);
	printf("\n 삽입B>>");
	enQueue(Q1, 'B');
	printQ(Q1);
	printf("\n 삽입C>>");
	enQueue(Q1, 'C');
	printQ(Q1);
	data = peekQ(Q1);	// 시험[*중요]
	printf(" peek item : %c \n", data);
	printf("\n 삭제 >>");
	data = deQueue(Q1);		// deQueue를 해도 실제 메모리 내에 저장된 값이 사라지지는 않음 [*중요]
	printQ(Q1);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제 >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삭제 >>");
	data = deQueue(Q1);
	printQ(Q1);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삽입D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n 삽입E>>"); enQueue(Q1, 'E'); printQ(Q1);

	getchar(); return 0;
}