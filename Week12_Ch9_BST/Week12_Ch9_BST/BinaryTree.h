#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

//���� Ʈ�� Ŭ����
class BinaryTree
{
protected:
	BinaryNode* root; //��Ʈ ��带 �����ϴ� ������ ���� 
public:

	BinaryTree() : root(NULL) { } //������ : ��Ʈ ��带 NULL�� �ʱ�ȭ
	~BinaryTree() { } //�Ҹ���

	void setRoot(BinaryNode* node) { root = node; } //��Ʈ ��带 �Ű������� ���� ���� set�ϴ� �Լ�
	BinaryNode* getRoot() { return root; } //��Ʈ ��带 ��ȯ�ϴ� �Լ�
	bool isEmpty() { return root == NULL; } //��Ʈ ��尡 ������� Ȯ���ϴ� �Լ�

	int	getCount() { return isEmpty() ? 0 : getCount(root); } //��Ʈ��尡 ����ٸ� 0�� �ƴ϶�� ��������� getCount�Լ��� ȣ���Ͽ� ����� ������ ��ȯ�Ѵ�..
	int	getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); } //��Ʈ ��尡 ����ٸ� 0�� �ƴ϶�� getLeafCount�Լ��� ȣ���Ͽ� �ܸ������ ������ ��ȯ�Ѵ�.
	int	getHeight() { return isEmpty() ? 0 : getHeight(root); } //��Ʈ ��尡 ����ٸ� 0�� �ƴ϶�� getHeight�Լ��� ȣ���Ͽ� ���̸� ��ȯ�Ѵ�.
	void inorder() { printf("\n   inorder: "); inorder(root); } //������ȯ ������� ��� ���� ����Ѵ�.
	void preorder() { printf("\n  preorder: "); preorder(root); } //������ȯ ������� ��� ���� ����Ѵ�.
	void postorder() { printf("\n postorder: "); postorder(root); } //���� ��ȯ ������� ��� ���� ����Ѵ�.

	//���� ��ȸ �Լ�
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) { //��Ʈ ��尡 ������� �ʴٸ�
			CircularQueue q;
			q.enqueue(root); //����ť�� q�� ��Ʈ ��带 �����Ѵ�.
			while (!q.isEmpty()) { //���� ť�� ������� ������ �ݺ����� �ݺ��Ѵ�.
				BinaryNode* n = q.dequeue(); //q�� �ִ� �����͸� ������ n�� �����Ѵ�.
				if (n != NULL) { //n�� ������� �ʴٸ�
					printf(" [%2d]", n->getData()); //n�� ���� ����Ѵ�(�湮)
					q.enqueue(n->getLeft()); //q�� n�� ���� ��� ���� �����Ѵ�.
					q.enqueue(n->getRight()); //q�� n�� ������ ��� ���� �����Ѵ�.
				}
			}
		}
		printf("\n");
	}

	//���� Ʈ���� ��� ������ ���ϴ� �Լ�
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0; //�Ű� ������ ���� ��尡 ����ٸ� 0�� ��ȯ
		return 1 + getCount(node->getLeft()) + getCount(node->getRight()); // 1�� ���ϰ� ���� ����� getCount���� 
																		// ������ ����� getCount���� ��� ��ģ �� �� ���� ��ȯ
	
	}
	//���� Ʈ���� �ܸ������ ������ ���ϴ� �Լ�
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0; //�Ű� ������ ���� ��尡 ����ٸ� 0�� ��ȯ
		if (node->isLeaf()) return 1; // �ش� ��尡 �ܸ������ 1�� ��ȯ
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight()); //�� ���� ��쿡�� ���� ����� �ܸ� ��� ����
																					//������ ����� �ܸ���� ���� ���� ����� ��ȯ
	}
	//���� Ʈ���� ���̸� ���ϴ� �Լ�
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0; //��尡 ����ٸ� 0�� ��ȯ
		int	hLeft = getHeight(node->getLeft()); //���� ����� ���̸� ���ؼ� hLeft ������ �����Ѵ�.
												//���̸� ���� ���� getHeight�Լ��� recursive call�Ͽ� ���Ѵ�.
		int	hRight = getHeight(node->getRight()); //������ ����� ���̸� ���ؼ� hRight ������ �����Ѵ�.(���ϴ� ����� ���ʰ� ����)
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1; //������ ���̿� �������� ���̸� ���ؼ� �� ���� ���� +1�� �� ���� ��ȯ�Ѵ�.
	}

	//calcSize�Լ� �����ε�
	// Ʈ���� ����� �����͵��� ��ģ ���� ��ȯ�ϴ� �Լ�
	int	calcSize() { return calcSize(root); }
	// ����� ������ ���� ���� ����ϴ� �Լ�
	int calcSize(BinaryNode* node) {
		if (node == NULL) return 0; //���� ��尡 ����ִٸ� 0�� ��ȯ�Ѵ�.
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight()); //����� ������ ���� �ش� ����� ���� ������ �����͸� ���� ��,
																						// ������ ������ �����͸� ���� ���� ���� ���� ����� ��ȯ�Ѵ�. 
	}

	//evaluate�Լ��� �����ε�
	// Ʈ���� ���� ��� ���� ��ȯ�ϴ� �Լ�
	int evaluate() { return evaluate(root); }
	// ���� ��� �Լ�
	int evaluate(BinaryNode* node) {
		if (node == NULL) return 0; //��尡 ����ٸ� 0�� ��ȯ
		if (node->isLeaf()) return node->getData(); //��尡 �ܸ������ �����͸� ��ȯ
		else { //�ܸ���尡 �ƴ϶��
			int op1 = evaluate(node->getLeft()); //�ش� ����� ���� ����� ���� ��� ���� op1�� ����
			int op2 = evaluate(node->getRight()); //�ش� ����� ������ ����� ���� ��� ���� op2�� ����
			switch (node->getData()) { //���Ŀ� ���� ��� case
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
		if (node != NULL) { //��尡 ������� ���� ��
			if (node->getLeft() != NULL) inorder(node->getLeft()); //����� ���� ��尡 ������� �ʴٸ� ���� ����� ������ȸ ����
			printf(" [%2d]", node->getData()); //����� ������ ���(�湮)
			if (node->getRight() != NULL) inorder(node->getRight()); //����� ������ ��尡 ������� �ʴٸ� ������ ����� ������ȸ ����
		}
	}

	//������ȸ
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%2d]", node->getData());  //����� ������ ���(�湮)
			if (node->getLeft() != NULL) preorder(node->getLeft()); //����� ���� ��尡 ������� �ʴٸ� ���� ����� ������ȸ ����
			if (node->getRight() != NULL) preorder(node->getRight()); //����� ������ ��尡 ������� �ʴٸ� ������ ����� ������ȸ ����
		}
	}

	//������ȸ
	void postorder(BinaryNode* node) {
		if (node != NULL) { 
			if (node->getLeft() != NULL) postorder(node->getLeft()); //����� ���� ��尡 ������� �ʴٸ� ���� ����� ������ȸ ����
			if (node->getRight() != NULL) postorder(node->getRight()); //����� ������ ��尡 ������� �ʴٸ� ������ ����� ������ȸ ����
			printf(" [%2d]", node->getData()); //����� ������ ���(�湮)
		}
	}
};

