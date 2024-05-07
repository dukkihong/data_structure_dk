#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackL.h"

int main() {
	char* param=NULL;
	param = (char*)malloc(sizeof(char) * 100);
	scanf("%d", param);
	int length;
	length = strlen(param);
	top = NULL;
	for (int i = 0; i < length; i++) {
		char a = param[i];
		switch (a) {
		case '(':
		case'{':
		case'[':
			push(a); break;
		case')':
		case'}':
		case']':
			if (isStackEmpty()) printf("\n수식의 괄호가 틀리게 사용되었습니다!");
			else {
				char temp;
				temp = pop();
				if ((temp == '(' && a != ')') || (temp == '{' && a != '}') || (temp == '[' && a != ']')) {
					printf("\n수식의 괄호가 틀리게 사용되었습니다!");
				}
				else break;
			}
		}
	}
	if (top == NULL) printf("\n수식의 괄호가 맞게 사용되었습니다!");
	else printf("\n수식의 괄호가 틀리게 사용되었습니다!");
}