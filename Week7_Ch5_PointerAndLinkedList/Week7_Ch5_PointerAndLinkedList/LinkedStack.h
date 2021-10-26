#pragma once

#include "Node.h"
class LinkedStack
{
	Node* top; //가장 최근에 들어간 데이터를 가리키는 포인터 변수
public:
	LinkedStack() { top = NULL; } //생성자 : top을 NULL로 설정하여 스택 초기화.
	
	~LinkedStack() { while (!isEmpty()) delete pop(); } //소멸자 : 스택이 빌 때까지 pop하여 데이터 제거.
	
	bool isEmpty() { return top == NULL; } //top이 NULL인지 아닌지 리턴하여 스택의 공백검사를 하는 함수.
	
	void push(Node* n) { //새로운 노드 n을 추가하는 함수
		if (isEmpty()) top = n; //스택이 비었으면 top에 n을 대입한다.
		else { //스택이 빈 상태가 아니라면
			n->setLink(top); //n이 top을 가리키도록 하고
			top = n; //top에 n을 대입하여 n이 top이 되도록 설정한다.
		}
	}

	Node* pop() {
		if (isEmpty()) return NULL; //스택이 비었으면 NULL을 반환
		Node* n = top; //노드 포인터 n에 top을 대입하여 top이 가리키는 값을 똑같이 가리키도록 함.
		top = top->getLink(); //top에 top의 다음 번째 노드를 연결하여 기존의 top노드를 삭제
		return n; //n을 반환
	}

	Node* peek() { return top; } //top을 반환한다.

	void display() { //스택에 있는 데이터를 보여주는 함수
		printf("[LinkedStack]\n");
		for (Node* p = top; p != NULL; p = p->getLink()) //노드 포인터가 top부터 다음 번째 링크를 계속 가리키며 NULL까지 반복
			p->display(); //Student.h 클래스에 있는 display()함수 호출
		printf("\n");
	}
};
