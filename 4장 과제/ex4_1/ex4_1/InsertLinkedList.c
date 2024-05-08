#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "InsertLinkedList.h"
// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;		// 공백 리스트이므로 NULL로 설정
	return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head != NULL) {		// 공백 리스트가 될 떄까지 실행
		p = L->head;				// 첫 번째 노드 저장
		L->head = L->head->link;	// 변수 head를 계속 해서 다음 노드의 주소로 초기화
		free(p);					// 실행 중인 turn에서 해제할 노드 해제, p에 저장된 주소 날림
		p = NULL;
	}
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
	listNode* p;
	printf("L= (");
	p = L->head;
	while (p != NULL) {					// p가 가리키는 head가 NULL이 아닐 떄까지 반복
		printf("%s", p->data);			// p->data는 p가 가리키는 노드의 data필드
		p = p->link;					// p를 p가 가리키고 있는 노드가 가리키는 노드의 주소로 초기화 
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {	// x는 삽입할 문자
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));	// 삽입할 새 노드 할당
	strcpy(newNode->data, x);						// 새 노드의 데이터 필드에 x 저장
	newNode->link = L->head;						// newNode의 link필드를 L의 head값인 원래 첫 번째 노드의 주소로 초기화
	L->head = newNode;								// L의 head는 첫 번째로 삽입된 newNode의 주소로 초기화
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L->head == NULL) {					 // 공백 리스트인 경우
		newNode->link = NULL;				// 새 노드를 첫 번째이자 마지막 노드로 연결
		L->head = newNode;
	}
	else if (pre == NULL) {					// 삽입 위치를 지정하는 포인터 pre가 NULL인 경우 (맨 앞에 삽입)
		newNode->link = L->head;
		L->head = newNode;					// 새 노드를 첫 번째 노드로 삽입
	}
	else {
		newNode->link = pre->link;			// 포인터 pre의 노드 뒤에 새 노드 연결
		pre->link = newNode;
	}
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {				// 현재 리스트가 공백인 경우
		L->head = newNode;				// 새 노드를 리스트의 시작 노드로 연결
		return;
	}
	// 현재 리스트가 공백이 아닌 경우
	temp = L->head;									// temp를 첫 번째 node의 주소로 초기화
	while (temp->link != NULL) temp = temp->link;	// 현재 리스트의 마지막 노드를 찾음				그러니까 temp->link는 결국 temp가 가리키고 있는 노드의 link필드이므로 다음 노드의 주소 의미
	temp->link = newNode;							// 새 노드를 마지막 노드(temp)의 다음 노드
}
// 리스트에서 노드 p를 삭제하는 연산 (시험)
void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;					// 삭제할 노드의 선행자 노드를 나타낼 포인터
	if (L->head == NULL) return;	// 공백 리스트라면 삭제 연산 중단
	if (L->head->link == NULL) {	// 리스트에 노드가 한 개만 있는 경우
		free(L->head);				// 첫 번째 노드를 메모리에서 해제하고
		L->head = NULL;				// 리스트 시작 포인터를 NULL로 설정
		return;
	}
	else if(p == NULL) return;		// 삭제할 노드가 없다면 삭제 연산 중단
	else {							// 삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해서 찾음
		pre = L->head;				// head에 저장된 값이니까 첫 번째 노드
		while(pre->link != p) {
			pre = pre->link;		// 노드의 주소와 삭제할 p의 주소가 같아질 떄까지 노드 넘기면서 반복문 실행
		}
		pre->link = p->link;		// 삭제할 노드 p의 선행자 노드의 다음 노드를 연결
		free(p);					// 삭제 노드의 메모리 해제
	 }
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}