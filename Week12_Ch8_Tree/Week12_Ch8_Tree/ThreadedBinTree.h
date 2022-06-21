#pragma once
#include "ThreadedBinNode.h"

class ThreadedBinTree
{
	ThreadedBinNode* root; //��Ʈ ��带 ����Ű�� ������ ����
public:

	ThreadedBinTree() : root(NULL) { } //������ : ��Ʈ ��带 NULL�� ����
	~ThreadedBinTree() { } //�Ҹ���

	void setRoot(ThreadedBinNode* node) { root = node; } //��Ʈ ��带 �Ű������� ���� ���� set�ϴ� �Լ�
	ThreadedBinNode* getRoot() { return root; } //��Ʈ ��带 get�ؿ��� �Լ�
	bool isEmpty() { return root == NULL; } // ��Ʈ ��尡 ������� �ƴ��� Ȯ���ϴ� �Լ�

	void threadedInorder() { //������ ����� inorder�湮�Լ� : ������ȸ�� �湮�ϰ�, recursion�� ����.
		if (!isEmpty()) { //��Ʈ ��尡 ������� �ʴٸ�
			printf("������ ���� Ʈ��: ");
			ThreadedBinNode* q = root; //��Ʈ ��带 ���ο� ��� ������ q�� �����ϰ�
			while (q->getLeft()) q = q->getLeft(); //q�� ���� ��尡 ���̸�(��, 0�� �ƴϸ�) q�� ���� ��带 get�ؿͼ� q�� �����Ѵ�.
												// == q�� ���� ��尡 ����(0)�� ������ q�� ���� ��带 ��ȯ�Ѵ�.
			do {
				printf("%c ", q->getData()); //q�� ���� ��尡 ����(0)�̸� q�� �����͸� ����Ѵ�.
				q = findSuccessor(q); //q�� �ļ��ڸ� ã�Ƽ� q�� �����Ѵ�.
			} while (q); //q�� ���� ����(0�� �ƴ� ����) �ݺ��Ѵ�.
			printf("\n");
		}
	}

	//���� �ļ��ڸ� ã�� �Լ��� ������ ��带 ã�� �Լ��̴�.
	ThreadedBinNode* findSuccessor(ThreadedBinNode* p) {
		ThreadedBinNode* q = p->getRight(); //�Ű� ������ ���� ��� p�� ������ �ڽ� ��带 q�� �����Ѵ�.

		if (q == NULL || p->bThread) return q; //���� q�� ����ų�, p�� �����尡 ����Ǿ� �ִٸ� q�� ��ȯ�Ѵ�.

		while (q->getLeft() != NULL) q = q->getLeft(); //q�� ���� ��尡 �����Ѵٸ� ���� ��带 ���� �湮�ؾ� �ϹǷ�
													//q�� ���� ��尡 ������� ������ �̸� ��ȯ�Ͽ� q�� �ٽ� �����Ѵ�.
		return q;
	}
};
