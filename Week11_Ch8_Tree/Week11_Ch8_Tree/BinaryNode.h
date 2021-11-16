#pragma once
#include <stdio.h>

class BinaryNode
{
protected:
	int			data; //����� �����͸� �����ϴ� int�� ����
	BinaryNode* left; //���� ��带 ����Ű�� ��ü������ left����
	BinaryNode* right; //������ ��带 ����Ű�� ��ü������ right����

public:
	//������ : �����ʹ� 0, ���� ���� NULL�� �ʱ�ȭ�Ѵ�.
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }
	//�Ҹ���
	~BinaryNode() { }

	//�Ű������� ���� ������ ����� �����͸� set�ϴ� �Լ�
	void		setData(int val) { data = val; } 
	//�Ű������� ���� ������ ������ ����� ���� �����͸� set�ϴ� �Լ�
	void		setLeft(BinaryNode* l) { left = l; }
	//�Ű������� ���� ������ ������ ����� ������ �����͸� set�ϴ� �Լ�
	void		setRight(BinaryNode* r) { right = r; }
	//����� �����͸� �������� �Լ�
	int			getData() { return data; }
	//����� ���� ��带 �������� �Լ�
	BinaryNode* getLeft() { return left; }
	//����� ������ ��带 �������� �Լ�
	BinaryNode* getRight() { return right; }
	//�ܸ����(�ڽ��� ���� ���)���� �ƴ��� Ȯ���ϴ� �Լ�
	bool		isLeaf() { return left == NULL && right == NULL; }
};

