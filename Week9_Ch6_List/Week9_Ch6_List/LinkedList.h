#pragma once
#include "Node.h"

class LinkedList {
	Node org; //헤드 노드 (포인터X)

public :
	LinkedList() : org(0) {} //생성자
	~LinkedList() { clear(); } //소멸자 : 전체 리스트를 clear함
	void clear() { while (!isEmpty()) delete remove(0); } //리스트가 공백 상태가 될 때까지 0번 위치의 노드를 remove하는 함수
	Node* getHead() { return org.getLink(); } //헤드 노드의 링크를 반환하는 함수
	bool isEmpty() { return getHead() == NULL; } //공백 상태를 검사하는 함수
												 //헤드 노드의 링크가 NULL이면 노드가 하나도 없다는 말이므로 공백상태이다.

	//pos번째 항목을 반환하는 함수
	Node* getEntry(int pos) {
		Node* n = &org; //org(헤드 노드)의 주소값을 노드 포인터 n에 삽입
		for (int i = -1; i < pos; i++, n = n->getLink()) { //0번째 노드를 고려하여 i를 -1부터 반복문을 시작
														   //n에 n의 링크를 삽입하여 계속해서 다음 노드를 가리키도록 한다.
			if (n == NULL) break;
		}
		return n; //pos번째 항목을 가리키는 n을 반환
	}

	//리스트의 어떤 위치에 항목 삽입하는 함수
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1); //이전 노드를 찾아와서 prev가 가리키도록 한다
		if (prev != NULL) {  //prev가 비어있지 않다면
			prev->insertNext(n); //prev의 next에 노드 n을 삽입
		}
	}

	//리스트의 어떤 위치의 항목을 삭제하는 함수
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1); //이전 노드를 찾아와서 prev가 가리키도록 한다
		return prev->removeNext(); //prev의 다음 노드를 삭제한다.
	}

	//탐색 함수
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) //노드 포인터 p가 첫 번째부터 끝(NULL)까지
															   //계속 다음 노드를 가리키면서 반복문을 돌린다.
			if (p->hasData(val)) return p; //노드 포인터 p의 데이터가 val인지 확인하여 true이면 노드p를 반환한다.
		return NULL; //해당 데이터(val)가 존재하지 않으면 NULL을 반환한다.
	}

	//리스트의 pos번째 노드를 다른 노드로 교체
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1); //이전 노드를 찾아와서 prev가 가리키도록 한다
		if (prev != NULL) { 
			delete prev->removeNext(); //prev의 다음 노드를 삭제하고
			prev->insertNext(n); //prev의 다음 노드에 n을 삽입한다.
		}
	}

	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) //리스트의 처음(getHead())부터 끝(NULL)까지 반복문을 돌면서
			count++; //count변수 증가시킨다
		return count; //count를 반환하여 size를 알려준다.
	}

	void display() {
		cout << "[전체 항목 수 = " << size() << "]";
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		cout << endl;
	}

	//(연습문제1)리스트의 값을 모두 합하는 함수
	int calcSum() {
		int sum = 0; //합을 저장하는 변수
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			sum += p->getData(); //노드의 데이터를 가져와서 sum에 더한다
		}

		return sum; //sum을 반환
	}

	//(연습문제2)리스트에 해당 데이터가 몇 개 존재하는지 검사하는 함수
	int countNode(int val) {
		int count = 0; //합을 저장하는 변수
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			//해당 노드와 val의 값이 같으면 count변수 증가
			if (p->getData() == val) count++; 
		}

		return count;
	}
};
