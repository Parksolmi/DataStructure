#pragma once

#include "Node2.h"		
class LinkedQueue
{
	Node* front; //���� ���� �� ��带 ����Ű�� ������ ���� 
	Node* rear; //���� ���߿� �� ��带 ����Ű�� ������ ����
public:
	LinkedQueue() : front(NULL), rear(NULL) { } //������ : front�� rear��� NULL���� ����Ű�� �Ͽ� ť�� �ʱ�ȭ�Ѵ�.
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); } //�Ҹ��� : ť�� ������ �� ������ dequeue()�� �����͸� ������.
	bool isEmpty() { return front == NULL; } //front�� NULL�� ����Ű���� Ȯ���Ͽ� ����˻��ϴ� �Լ�

	// ���� ����
	void enqueue(Node* n) {
		if (isEmpty()) front = rear = n; //��������� front�� rear��� ���ԵǴ� �����͸� ����Ű�� �Ѵ�.
		else { //������� ������
			rear->setLink(n); //rear�� ����Ű�� ���� �Ű������� ���� ��� n���� set�ϰ�
			rear = n; //rear�� n�� �����Ͽ� n�� rear�� �����Ѵ�.
		}
	}
	// ���� ����
	Node* dequeue() {
		if (isEmpty()) return NULL; //ť�� ����ٸ� NULL�� ��ȯ�Ѵ�.
		Node* temp = front; //��� temp�� front�� �����ϰ�
		front = front->getLink(); //front�� front�� ����Ű�� �����͸� �����Ѵ�.(�� ���� �����͸� ����Ű���� �Ѵ�)
		if (front == NULL) rear = NULL; //���� front�� NULL�� ����Ų�ٸ� rear�� NULL�� ����Ű���� �Ͽ� ������¸� �����.
		return temp; //��� temp��ȯ(��, front�� ���� ����Ű�� ���� ��ȯ�ϴ� ��)
	}
	Node* peek() { return front; }  //��带 �������� �ʰ� �׳� front ���� �����Ͽ� �����ش�.

	void display() { //ť�� �ִ� �����͸� ��� �����ִ� �Լ�
		printf("[ť ����] : ");
		for (Node* p = front; p != NULL; p = p->getLink()) //��� ������ p�� front���� ���� ��带 ��� ����Ű�鼭 
															// NULL�� �� ������ �ݺ�
			p->display(); //Node.h�� �ִ� display�Լ��� ȣ��
		printf("\n");
	}
};
