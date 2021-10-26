#pragma once

#include <stdio.h>

class Node
{
	Node* link; //��� ������ ��ü
	int		data; //������(int��)

public:
	Node(int val = 0) : data(val), link(NULL) { } //������ : data�� 0���� ����, link�� NULL�� ����Ű���� ��
	Node* getLink() { return link; } //��带 get�ϴ� �Լ�
	void setLink(Node* next) { link = next; } //��带 set�ϴ� �Լ�
	void display() { printf(" <%2d>", data); } //ť�� ��� �ִ� ������(int)�� display�ϴ� �Լ�
};
