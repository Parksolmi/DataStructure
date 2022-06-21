#pragma once
#include <stdio.h>

//������ ����Ʈ���� ��带 ���� ���Ŭ����
class ThreadedBinNode
{
protected:
	int			data; //���� Ʈ���� �����͸� ���� ����
	ThreadedBinNode* left; //���� Ʈ���� ���� ��带 ����ų ��ü ������ ����
	ThreadedBinNode* right; //���� Ʈ���� ������ ��带 ����ų ��ü ������ ����
public:
	bool		bThread; //������ ���� ���θ� Ȯ���� ���� ����
	ThreadedBinNode(int val = 0, ThreadedBinNode* l = NULL, ThreadedBinNode* r = NULL, bool bTh = false) //������
		// : ����� �����ʹ� 0����, ���ʰ� ������ ���� ���� NULL��, ������ ������ ��Ÿ���� ������ false�� �ʱ�ȭ�Ѵ�.
		: data(val), left(l), right(r), bThread(bTh) { }

	int	 getData() { return data; } //����� �����͸� get�ؿ��� �Լ�
	void setRight(ThreadedBinNode* r) { right = r; } //�����带 �����ϴ� �Լ� : �ش� ����� ������ ��ũ�� �Ű������� ���� ���� ����Ű���� �Ѵ�.
	ThreadedBinNode* getLeft() { return left; } //���� ��带 get�ϴ� �Լ�
	ThreadedBinNode* getRight() { return right; } //������ ��带 get�ϴ� �Լ�
};