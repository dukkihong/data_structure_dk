#include <stdio.h>
void quickSort(int a[], int begin, int end, int size);

int main() {
	int list[8] = { 69,10,30,2,16,8,31,22 }, i = 0;
	int size = sizeof(list) / sizeof(list[5]);
	printf("\n정렬할 원소: ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
	printf("\n\n<<<<<<<<<<<<<<<<< 퀵 정렬 수행 >>>>>>>>>>>>>>>>>>>>\n");
	quickSort(list, 0, size - 1, size);

	getchar(); return 0;
}