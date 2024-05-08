#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	linkedList_h* L1;
	listNode* p;
	L1 = createLinkedList_h();		// ���� ����Ʈ ����

	printf("(1) ����Ʈ�� [��],[��],[��] ��� �����ϱ�! \n");
	insertLastNode(L1, "��"); insertLastNode(L1, "��"); insertLastNode(L1, "��");
	printList(L1);

	printf("\n(2) ����Ʈ���� [��] ��� Ž���ϱ�! \n");
	p = searchNode(L1, "��");
	if (p == NULL) printf("ã�� �����Ͱ� �����ϴ�. \n");
	else printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);

	printf("\n(3) ����Ʈ�� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(L1, p, "��");
	printList(L1);

	printf("\n(4) ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(L1, "��");			// ������ ��� ��ġ p�� ã��
	deleteNode(L1, p);					// ������ p ��� ����
	printList(L1);

	printf("\n(5) ����Ʈ ������ �������� �ٲٱ�! \n");
	reverse(L1);
	printList(L1);

	freeLinkedList_h(L1);				// ����Ʈ�� �޸� ����
	getchar();

	return 0;
}