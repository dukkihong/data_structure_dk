#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StackL.h"

int main() {
	char* sen = NULL;
	sen = (char*)malloc(sizeof(char) * 100);
	printf("후위 표기식 : ");
	scanf("%s", sen);
	int res;
	int length = strlen(sen);
	for (int i = 0; i < length; i++) {
		if (sen[i] != '+' && sen[i] != '-' && sen[i] != '*' && sen[i] != '/') {
			element val = sen[i] - '0';
			push(val);
		}
		else {
			int a = pop();
			int b = pop();
			switch(sen[i]) {
			case '+':
				res = b + a ;
				break;
			case'-':
				res = b - a ;
				break;
			case'*':
				res = b * a ;
				break;
			case'/':
				res = b / a ;
				break;
			}
			push(res);
		}
	}
	res = pop();
	printf("\n연산 결과=>%d", res);
}