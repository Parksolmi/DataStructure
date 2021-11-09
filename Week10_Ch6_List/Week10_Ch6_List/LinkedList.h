#pragma once
#pragma once

#include "Node.h"
class LinkedList
{
	Node	org;	// 헤드 노드 (헤드 포인터가 아님)

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() { while (!isEmpty()) delete remove(0); }
	Node* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == NULL; }

	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL)
			prev->insertNext(n);
	}

	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}

	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}

	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}

	void display(char* str) {
		printf("%s [단순연결리스트 항목 수 = %2d] : ", str, size());
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}

	void reverse()
	{
		Node* p, * q, * r;
		p = getHead();
		q = NULL;

		while (p != NULL)
		{
			r = q; //r은 q를 따라간다.
			q = p; //q는 p를 따라간다.
			p = p->getLink(); //p는 계속 다음 값을 가리키며 앞으로 간다.
			q->setLink(r); //방향 반대로 바꿈
		}
		org.setLink(q); //리스트의 헤더 노드가 q가 가리키는 값을 가리키도록 한다.
	}

	void merge(LinkedList* list)
	{
		Node* q = NULL;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) q = p; //q가 마지막 노드를 가리킨다.
		q->setLink(list->getHead()); //q가 list의 첫 번째 노드를 가리키도록 한다.
		list->org.setLink(NULL); //list의 첫 번째 노드가 가리키는 값을 NULL로 설정한다.
	}
};