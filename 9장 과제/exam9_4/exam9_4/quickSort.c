#include <stdio.h>

int i = 0;

int partition(int a[], int begin, int end, int size) {
	int pivot, L, R, t, temp;
	L = begin;
	R = end;
	pivot = begin;
	printf("\n [%d´Ü°è: pivot= %d ]\n", ++i, a[pivot]);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R) {
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;

			if (L == pivot) pivot = R;
		}
	}
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	for (t = 0; t < size; t++) printf("%5d", a[t]);
	printf("\n");
	return R;
}

void quickSort(int a[], int begin, int end,int size) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end, size);
		quickSort(a, begin, p - 1, size);
		quickSort(a, p + 1, end, size);
	}
}