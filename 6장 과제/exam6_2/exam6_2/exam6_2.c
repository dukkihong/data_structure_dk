#include "cQueueS.h"

int main() {
	QueueType* cQ = createCQueue();
	element data;
	printf("\n ***** 원형 큐 연산 ***** \n");
	printf("\n 삽입A>>"); enCQueue(cQ, 'A'); printCQ(cQ);		// cQ[0]이 아닌 cQ[1]에 첫번째 data저장
	printf("\n 삽입B>>"); enCQueue(cQ, 'B'); printCQ(cQ);
	printf("\n 삽입C>>"); enCQueue(cQ, 'C'); printCQ(cQ);
	data = peekCQ(cQ); printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deCQueue(cQ); printCQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deCQueue(cQ); printCQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deCQueue(cQ); printCQ(cQ);
	printf("\t\t삭제 데이터: %c", data);
	printf("\n 삽입D>>"); enCQueue(cQ, 'D'); printCQ(cQ);
	printf("\n 삽입E>>"); enCQueue(cQ, 'E'); printCQ(cQ);
	getchar(); return 0;
}