#pragma once
#include <stdio.h>

//����Ʈ�� ��� Ŭ����
class BinaryNode
{
protected:
	int			data; //����� ������
	BinaryNode* left; //���� ��带 ����Ű�� ������
	BinaryNode* right; //������ ��带 ����Ű�� ������
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) //������ 
		//������=0, ���� ��� ������ = NULL, ������ ��� ������ = NULL�� �ʱ�ȭ
		: data(val), left(l), right(r) { }
	~BinaryNode() { } //�Ҹ���

	void		setData(int val) { data = val; } //�Ű������� ���� ���� ����� �����ͷ� set�ϴ� �Լ�
	void		setLeft(BinaryNode* l) { left = l; } //�Ű������� ���� �����͸� ����� ���� �����ͷ� set�ϴ� �Լ�
	void		setRight(BinaryNode* r) { right = r; } //�Ű������� ���� �����͸� ����� ������ �����ͷ� set�ϴ� �Լ�
	int			getData() { return data; } //����� �����͸� get�ϴ� �Լ�
	BinaryNode* getLeft() { return left; } //����� ���� ��带 get�ϴ� �Լ�
	BinaryNode* getRight() { return right; } //����� ������ ��带 get�ϴ� �Լ�
	bool		isLeaf() { return left == NULL && right == NULL; } //�ܸ�������� �ƴ��� Ȯ���ϴ� �Լ�
};

