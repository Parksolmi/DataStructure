#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

class BinaryTree
{
	BinaryNode* root;
public:

	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	int	getCount() { return isEmpty() ? 0 : getCount(root); }
	int	getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int	getHeight() { return isEmpty() ? 0 : getHeight(root); }
	void inorder() { printf("\n   inorder: "); inorder(root); }
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void postorder() { printf("\n postorder: "); postorder(root); }
	//������ȸ
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) { //Ʈ���� ������� �ʴٸ�
			CircularQueue q;
			q.enqueue(root); //root�� ����ť�� �����Ѵ�.
			while (!q.isEmpty()) { //����ť�� ������� �ʴٸ�
				BinaryNode* n = q.dequeue(); //ť���� element�� �ϳ� ������ ��忡 �����Ѵ�.
				if (n != NULL) { //n�� ������� �ʴٸ�
					printf(" [%c] ", n->getData()); //n�� �����͸� ���(�湮)
					q.enqueue(n->getLeft()); //n�� ���� ��带 ����ť�� �����Ѵ�.
					q.enqueue(n->getRight()); //n�� ������ ��带 ����ť�� �����Ѵ�.
				}
			}
		}
		printf("\n");
	}

	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int	hLeft = getHeight(node->getLeft());
		int	hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	int	calcSize() { return calcSize(root); }
	int calcSize(BinaryNode* node) {
		if (node == NULL) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}

	int evaluate() { return evaluate(root); }
	// ���� ��� �Լ�
	int evaluate(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isLeaf()) return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
			}
			return 0;
		}
	}


private:
	// Ʈ���� ��ȸ
	//������ȸ
	void inorder(BinaryNode* node) {
		if (node != NULL) { //��尡 NULL�� �ƴ� ��
			//���� ��尡 �����Ѵٸ� ���� ����� ������ȸ�� ����
			if (node->getLeft() != NULL) inorder(node->getLeft());
			//���� ��尡 �������� ������ ������ ���(�湮)
			printf(" [%c] ", node->getData());
			//������ ��尡 �����Ѵٸ� ������ ����� ������ȸ ����
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	//������ȸ
	void preorder(BinaryNode* node) {
		if (node != NULL) { //��尡 NULL�� �ƴ� ��
			//����� �����͸� ���(�湮)
			printf(" [%c] ", node->getData());
			//���� ��尡 �����ϸ� ���� ����� ������ȸ�� ����
			if (node->getLeft() != NULL) preorder(node->getLeft());
			//������ ��尡 �����ϸ� ������ ����� ������ȸ�� ����
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	//������ȸ
	void postorder(BinaryNode* node) {
		if (node != NULL) { //��尡 NULL�� �ƴ� ��
			//���� ��尡 �����ϸ� ���� ����� ������ȸ�� ����
			if (node->getLeft() != NULL) postorder(node->getLeft());
			//������ ��尡 �����ϸ� ������ ����� ������ȸ ����
			if (node->getRight() != NULL) postorder(node->getRight());
			//����� �����͸� ���(�湮)
			printf(" [%c] ", node->getData());
		}
	}
};

