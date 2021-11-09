#pragma once
#pragma once

#include "Node.h"
class LinkedList
{
	Node	org;	// ��� ��� (��� �����Ͱ� �ƴ�)

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
		printf("%s [�ܼ����Ḯ��Ʈ �׸� �� = %2d] : ", str, size());
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
			r = q; //r�� q�� ���󰣴�.
			q = p; //q�� p�� ���󰣴�.
			p = p->getLink(); //p�� ��� ���� ���� ����Ű�� ������ ����.
			q->setLink(r); //���� �ݴ�� �ٲ�
		}
		org.setLink(q); //����Ʈ�� ��� ��尡 q�� ����Ű�� ���� ����Ű���� �Ѵ�.
	}

	void merge(LinkedList* list)
	{
		Node* q = NULL;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) q = p; //q�� ������ ��带 ����Ų��.
		q->setLink(list->getHead()); //q�� list�� ù ��° ��带 ����Ű���� �Ѵ�.
		list->org.setLink(NULL); //list�� ù ��° ��尡 ����Ű�� ���� NULL�� �����Ѵ�.
	}
};