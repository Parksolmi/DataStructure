#pragma once
#include "ThreadedBinNode.h"

class ThreadedBinTree
{
	ThreadedBinNode* root; //루트 노드를 가리키는 포인터 변수
public:

	ThreadedBinTree() : root(NULL) { } //생성자 : 루트 노드를 NULL로 설정
	~ThreadedBinTree() { } //소멸자

	void setRoot(ThreadedBinNode* node) { root = node; } //루트 노드를 매개변수로 받은 노드로 set하는 함수
	ThreadedBinNode* getRoot() { return root; } //루트 노드를 get해오는 함수
	bool isEmpty() { return root == NULL; } // 루트 노드가 비었는지 아닌지 확인하는 함수

	void threadedInorder() { //스레드 방식의 inorder방문함수 : 중위순회로 방문하고, recursion이 없다.
		if (!isEmpty()) { //루트 노드가 비어있지 않다면
			printf("스레드 이진 트리: ");
			ThreadedBinNode* q = root; //루트 노드를 새로운 노드 포인터 q에 저장하고
			while (q->getLeft()) q = q->getLeft(); //q의 왼쪽 노드가 참이면(즉, 0이 아니면) q의 왼쪽 노드를 get해와서 q에 저장한다.
												// == q의 왼쪽 노드가 거짓(0)일 때까지 q의 왼쪽 노드를 반환한다.
			do {
				printf("%c ", q->getData()); //q의 왼쪽 노드가 거짓(0)이면 q의 데이터를 출력한다.
				q = findSuccessor(q); //q의 후속자를 찾아서 q에 저장한다.
			} while (q); //q가 참인 동안(0이 아닌 동안) 반복한다.
			printf("\n");
		}
	}

	//중위 후속자를 찾는 함수로 오른쪽 노드를 찾는 함수이다.
	ThreadedBinNode* findSuccessor(ThreadedBinNode* p) {
		ThreadedBinNode* q = p->getRight(); //매개 변수로 받은 노드 p의 오른쪽 자식 노드를 q에 저장한다.

		if (q == NULL || p->bThread) return q; //만약 q가 비었거나, p의 스레드가 연결되어 있다면 q를 반환한다.

		while (q->getLeft() != NULL) q = q->getLeft(); //q의 왼쪽 노드가 존재한다면 왼쪽 노드를 먼저 방문해야 하므로
													//q의 왼쪽 노드가 비어있을 때까지 이를 반환하여 q에 다시 저장한다.
		return q;
	}
};
