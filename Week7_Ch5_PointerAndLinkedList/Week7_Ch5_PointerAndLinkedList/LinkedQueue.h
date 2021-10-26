#pragma once

#include "Node2.h"		
class LinkedQueue
{
	Node* front; //가장 먼저 들어간 노드를 가리키는 포인터 변수 
	Node* rear; //가장 나중에 들어간 노드를 가리키는 포인터 변수
public:
	LinkedQueue() : front(NULL), rear(NULL) { } //생성자 : front와 rear모두 NULL값을 가리키게 하여 큐를 초기화한다.
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); } //소멸자 : 큐가 공백이 될 때까지 dequeue()로 데이터를 꺼낸다.
	bool isEmpty() { return front == NULL; } //front가 NULL을 가리키는지 확인하여 공백검사하는 함수

	// 삽입 연산
	void enqueue(Node* n) {
		if (isEmpty()) front = rear = n; //비어있으면 front와 rear모두 삽입되는 데이터를 가리키게 한다.
		else { //비어있지 않으면
			rear->setLink(n); //rear가 가리키는 값은 매개변수로 받은 노드 n으로 set하고
			rear = n; //rear에 n을 대입하여 n을 rear로 설정한다.
		}
	}
	// 삭제 연산
	Node* dequeue() {
		if (isEmpty()) return NULL; //큐가 비었다면 NULL을 반환한다.
		Node* temp = front; //노드 temp에 front를 대입하고
		front = front->getLink(); //front에 front가 가리키는 데이터를 대입한다.(즉 다음 데이터를 가리키도록 한다)
		if (front == NULL) rear = NULL; //만약 front가 NULL을 가리킨다면 rear도 NULL을 가리키도록 하여 공백상태를 만든다.
		return temp; //노드 temp반환(즉, front가 원래 가리키던 값을 반환하는 것)
	}
	Node* peek() { return front; }  //노드를 삭제하진 않고 그냥 front 값만 리턴하여 보여준다.

	void display() { //큐에 있는 데이터를 모두 보여주는 함수
		printf("[큐 내용] : ");
		for (Node* p = front; p != NULL; p = p->getLink()) //노드 포인터 p가 front부터 다음 노드를 계속 가리키면서 
															// NULL이 될 때까지 반복
			p->display(); //Node.h에 있는 display함수를 호출
		printf("\n");
	}
};
