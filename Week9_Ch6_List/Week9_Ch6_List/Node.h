#pragma once
#include <iostream>

using namespace std;

class Node {
	Node* link; //다음 노드를 가리키는 포인터 변수
	int data; //노드의 데이터 필드
public:
	Node(int val = 0) : data(val), link(NULL) {} //생성자 : 노드 초기화
	Node* getLink() { return link; } //노드의 link를 반환하는 함수
	int getData() { return data; } //노드의 data를 반환하는 함수
	void setLink(Node* next) { link = next; } //노드의 링크를 매개변수로 받은 노드의 주소값으로 set하는 함수
	void display() { cout << " <" << data << ">"; } //노드의 데이터를 출력하는 함수
	bool hasData(int val) { return data = val; } //데이터를 매개변수로 받아서 해당 데이터가 존재하는지 여부를 검사하는 함수

	//자신의 다음에 새로운 노드 n을 삽입하는 함수
	void insertNext(Node* n)
	{
		if (n != NULL) { //만약 새로운 노드 n이 NULL이 아니라면
			n->link = link; //n의 링크에 링크를 삽입하여 다음 노드를 가리키게 하고
			link = n; //링크에 n을 넣어 n의 전에 있는 노드가 n을 가리키게 한다.
		}
	}

	//자신의 다음 노드를 리스트에서 삭제하는 함수
	Node* removeNext() {
		Node* removed = link; //remove할 노드는 해당 노드의 링크가 가리키는 노드이다.
		if (removed != NULL) //만약 removed가 NULL이 아니라면 (즉, 다음 노드가 존재한다면)
		{
			link = removed->link; //노드의 link가 remove할 노드의 다음 노드를 가리키도록 한다.
		}
		return removed; //삭제된 노드의 주소를 반환
						//반환하지 않으면 삭제된 노드의 메모리가 해제되지 않고 위치를 잃어버리게 된다.
	}

};