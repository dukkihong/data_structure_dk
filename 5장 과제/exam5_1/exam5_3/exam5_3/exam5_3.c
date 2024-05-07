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
			if (isStackEmpty()) printf("\n������ ��ȣ�� Ʋ���� ���Ǿ����ϴ�!");
			else {
				char temp;
				temp = pop();
				if ((temp == '(' && a != ')') || (temp == '{' && a != '}') || (temp == '[' && a != ']')) {
					printf("\n������ ��ȣ�� Ʋ���� ���Ǿ����ϴ�!");
				}
				else break;
			}
		}
	}
	if (top == NULL) printf("\n������ ��ȣ�� �°� ���Ǿ����ϴ�!");
	else printf("\n������ ��ȣ�� Ʋ���� ���Ǿ����ϴ�!");
}