#pragma once
#include <iostream>

using namespace std;

class Node {
	Node* link; //���� ��带 ����Ű�� ������ ����
	int data; //����� ������ �ʵ�
public:
	Node(int val = 0) : data(val), link(NULL) {} //������ : ��� �ʱ�ȭ
	Node* getLink() { return link; } //����� link�� ��ȯ�ϴ� �Լ�
	int getData() { return data; } //����� data�� ��ȯ�ϴ� �Լ�
	void setLink(Node* next) { link = next; } //����� ��ũ�� �Ű������� ���� ����� �ּҰ����� set�ϴ� �Լ�
	void display() { cout << " <" << data << ">"; } //����� �����͸� ����ϴ� �Լ�
	bool hasData(int val) { return data = val; } //�����͸� �Ű������� �޾Ƽ� �ش� �����Ͱ� �����ϴ��� ���θ� �˻��ϴ� �Լ�

	//�ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�
	void insertNext(Node* n)
	{
		if (n != NULL) { //���� ���ο� ��� n�� NULL�� �ƴ϶��
			n->link = link; //n�� ��ũ�� ��ũ�� �����Ͽ� ���� ��带 ����Ű�� �ϰ�
			link = n; //��ũ�� n�� �־� n�� ���� �ִ� ��尡 n�� ����Ű�� �Ѵ�.
		}
	}

	//�ڽ��� ���� ��带 ����Ʈ���� �����ϴ� �Լ�
	Node* removeNext() {
		Node* removed = link; //remove�� ���� �ش� ����� ��ũ�� ����Ű�� ����̴�.
		if (removed != NULL) //���� removed�� NULL�� �ƴ϶�� (��, ���� ��尡 �����Ѵٸ�)
		{
			link = removed->link; //����� link�� remove�� ����� ���� ��带 ����Ű���� �Ѵ�.
		}
		return removed; //������ ����� �ּҸ� ��ȯ
						//��ȯ���� ������ ������ ����� �޸𸮰� �������� �ʰ� ��ġ�� �Ҿ������ �ȴ�.
	}

};