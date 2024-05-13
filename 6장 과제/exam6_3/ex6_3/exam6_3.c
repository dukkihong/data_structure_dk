#include "LinkedQueue.h"

int main() {
	LQueue* LQ = createQueue();
	element data;
	printf("***** 연결 큐 연산 *****\n");
	printf("\n 삽입A>>"); enLQueue(LQ, 'A'); printLQ(LQ);
	printf("\n 삽입B>>"); enLQueue(LQ, 'B'); printLQ(LQ);
	printf("\n 삽입C>>"); enLQueue(LQ, 'C'); printLQ(LQ);
	data = peekLQ(LQ); printf("\tpeek item: %c\n",data);
	printf("\n 삭제 >>"); data = deLQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deLQueue(LQ); printLQ(LQ);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deLQueue(LQ); printLQ(LQ);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삽입D>>"); enLQueue(LQ, 'D'); printLQ(LQ);
	printf("\n 삽입E>>"); enLQueue(LQ, 'E'); printLQ(LQ);
}