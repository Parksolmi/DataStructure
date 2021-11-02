#pragma once
#include "Node.h"

class LinkedList {
	Node org; //��� ��� (������X)

public :
	LinkedList() : org(0) {} //������
	~LinkedList() { clear(); } //�Ҹ��� : ��ü ����Ʈ�� clear��
	void clear() { while (!isEmpty()) delete remove(0); } //����Ʈ�� ���� ���°� �� ������ 0�� ��ġ�� ��带 remove�ϴ� �Լ�
	Node* getHead() { return org.getLink(); } //��� ����� ��ũ�� ��ȯ�ϴ� �Լ�
	bool isEmpty() { return getHead() == NULL; } //���� ���¸� �˻��ϴ� �Լ�
												 //��� ����� ��ũ�� NULL�̸� ��尡 �ϳ��� ���ٴ� ���̹Ƿ� ��������̴�.

	//pos��° �׸��� ��ȯ�ϴ� �Լ�
	Node* getEntry(int pos) {
		Node* n = &org; //org(��� ���)�� �ּҰ��� ��� ������ n�� ����
		for (int i = -1; i < pos; i++, n = n->getLink()) { //0��° ��带 ����Ͽ� i�� -1���� �ݺ����� ����
														   //n�� n�� ��ũ�� �����Ͽ� ����ؼ� ���� ��带 ����Ű���� �Ѵ�.
			if (n == NULL) break;
		}
		return n; //pos��° �׸��� ����Ű�� n�� ��ȯ
	}

	//����Ʈ�� � ��ġ�� �׸� �����ϴ� �Լ�
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1); //���� ��带 ã�ƿͼ� prev�� ����Ű���� �Ѵ�
		if (prev != NULL) {  //prev�� ������� �ʴٸ�
			prev->insertNext(n); //prev�� next�� ��� n�� ����
		}
	}

	//����Ʈ�� � ��ġ�� �׸��� �����ϴ� �Լ�
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1); //���� ��带 ã�ƿͼ� prev�� ����Ű���� �Ѵ�
		return prev->removeNext(); //prev�� ���� ��带 �����Ѵ�.
	}

	//Ž�� �Լ�
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) //��� ������ p�� ù ��°���� ��(NULL)����
															   //��� ���� ��带 ����Ű�鼭 �ݺ����� ������.
			if (p->hasData(val)) return p; //��� ������ p�� �����Ͱ� val���� Ȯ���Ͽ� true�̸� ���p�� ��ȯ�Ѵ�.
		return NULL; //�ش� ������(val)�� �������� ������ NULL�� ��ȯ�Ѵ�.
	}

	//����Ʈ�� pos��° ��带 �ٸ� ���� ��ü
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1); //���� ��带 ã�ƿͼ� prev�� ����Ű���� �Ѵ�
		if (prev != NULL) { 
			delete prev->removeNext(); //prev�� ���� ��带 �����ϰ�
			prev->insertNext(n); //prev�� ���� ��忡 n�� �����Ѵ�.
		}
	}

	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) //����Ʈ�� ó��(getHead())���� ��(NULL)���� �ݺ����� ���鼭
			count++; //count���� ������Ų��
		return count; //count�� ��ȯ�Ͽ� size�� �˷��ش�.
	}

	void display() {
		cout << "[��ü �׸� �� = " << size() << "]";
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		cout << endl;
	}

	//(��������1)����Ʈ�� ���� ��� ���ϴ� �Լ�
	int calcSum() {
		int sum = 0; //���� �����ϴ� ����
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			sum += p->getData(); //����� �����͸� �����ͼ� sum�� ���Ѵ�
		}

		return sum; //sum�� ��ȯ
	}

	//(��������2)����Ʈ�� �ش� �����Ͱ� �� �� �����ϴ��� �˻��ϴ� �Լ�
	int countNode(int val) {
		int count = 0; //���� �����ϴ� ����
		for (Node* p = getHead(); p != NULL; p = p->getLink())
		{
			//�ش� ���� val�� ���� ������ count���� ����
			if (p->getData() == val) count++; 
		}

		return count;
	}
};
