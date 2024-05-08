#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "InsertLinkedList.h"
// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;		// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {		// ���� ����Ʈ�� �� ������ ����
		p = L->head;				// ù ��° ��� ����
		L->head = L->head->link;	// ���� head�� ��� �ؼ� ���� ����� �ּҷ� �ʱ�ȭ
		free(p);					// ���� ���� turn���� ������ ��� ����, p�� ����� �ּ� ����
		p = NULL;
	}
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
	listNode* p;
	printf("L= (");
	p = L->head;
	while (p != NULL) {					// p�� ����Ű�� head�� NULL�� �ƴ� ������ �ݺ�
		printf("%s", p->data);			// p->data�� p�� ����Ű�� ����� data�ʵ�
		p = p->link;					// p�� p�� ����Ű�� �ִ� ��尡 ����Ű�� ����� �ּҷ� �ʱ�ȭ 
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h* L, char* x) {	// x�� ������ ����
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));	// ������ �� ��� �Ҵ�
	strcpy(newNode->data, x);						// �� ����� ������ �ʵ忡 x ����
	newNode->link = L->head;						// newNode�� link�ʵ带 L�� head���� ���� ù ��° ����� �ּҷ� �ʱ�ȭ
	L->head = newNode;								// L�� head�� ù ��°�� ���Ե� newNode�� �ּҷ� �ʱ�ȭ
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {					 // ���� ����Ʈ�� ���
		newNode->link = NULL;				// �� ��带 ù ��°���� ������ ���� ����
		L->head = newNode;
	}
	else if (pre == NULL) {					// ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ��� (�� �տ� ����)
		newNode->link = L->head;
		L->head = newNode;					// �� ��带 ù ��° ���� ����
	}
	else {
		newNode->link = pre->link;			// ������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}

// ������ ���� �����ϴ� ����
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {				// ���� ����Ʈ�� ������ ���
		L->head = newNode;				// �� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;									// temp�� ù ��° node�� �ּҷ� �ʱ�ȭ
	while (temp->link != NULL) temp = temp->link;	// ���� ����Ʈ�� ������ ��带 ã��				�׷��ϱ� temp->link�� �ᱹ temp�� ����Ű�� �ִ� ����� link�ʵ��̹Ƿ� ���� ����� �ּ� �ǹ�
	temp->link = newNode;							// �� ��带 ������ ���(temp)�� ���� ���
}
// ����Ʈ���� ��� p�� �����ϴ� ���� (����)
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;					// ������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL) return;	// ���� ����Ʈ��� ���� ���� �ߴ�
	if (L->head->link == NULL) {	// ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(L->head);				// ù ��° ��带 �޸𸮿��� �����ϰ�
		L->head = NULL;				// ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if(p == NULL) return;		// ������ ��尡 ���ٸ� ���� ���� �ߴ�
	else {							// ������ ��� p�� ������ ��带 ������ pre�� �̿��ؼ� ã��
		pre = L->head;				// head�� ����� ���̴ϱ� ù ��° ���
		while(pre->link != p) {
			pre = pre->link;		// ����� �ּҿ� ������ p�� �ּҰ� ������ ������ ��� �ѱ�鼭 �ݺ��� ����
		}
		pre->link = p->link;		// ������ ��� p�� ������ ����� ���� ��带 ����
		free(p);					// ���� ����� �޸� ����
	 }
}

// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}