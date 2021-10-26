#pragma once

#include "Node.h"
class LinkedStack
{
	Node* top; //���� �ֱٿ� �� �����͸� ����Ű�� ������ ����
public:
	LinkedStack() { top = NULL; } //������ : top�� NULL�� �����Ͽ� ���� �ʱ�ȭ.
	
	~LinkedStack() { while (!isEmpty()) delete pop(); } //�Ҹ��� : ������ �� ������ pop�Ͽ� ������ ����.
	
	bool isEmpty() { return top == NULL; } //top�� NULL���� �ƴ��� �����Ͽ� ������ ����˻縦 �ϴ� �Լ�.
	
	void push(Node* n) { //���ο� ��� n�� �߰��ϴ� �Լ�
		if (isEmpty()) top = n; //������ ������� top�� n�� �����Ѵ�.
		else { //������ �� ���°� �ƴ϶��
			n->setLink(top); //n�� top�� ����Ű���� �ϰ�
			top = n; //top�� n�� �����Ͽ� n�� top�� �ǵ��� �����Ѵ�.
		}
	}

	Node* pop() {
		if (isEmpty()) return NULL; //������ ������� NULL�� ��ȯ
		Node* n = top; //��� ������ n�� top�� �����Ͽ� top�� ����Ű�� ���� �Ȱ��� ����Ű���� ��.
		top = top->getLink(); //top�� top�� ���� ��° ��带 �����Ͽ� ������ top��带 ����
		return n; //n�� ��ȯ
	}

	Node* peek() { return top; } //top�� ��ȯ�Ѵ�.

	void display() { //���ÿ� �ִ� �����͸� �����ִ� �Լ�
		printf("[LinkedStack]\n");
		for (Node* p = top; p != NULL; p = p->getLink()) //��� �����Ͱ� top���� ���� ��° ��ũ�� ��� ����Ű�� NULL���� �ݺ�
			p->display(); //Student.h Ŭ������ �ִ� display()�Լ� ȣ��
		printf("\n");
	}
};
