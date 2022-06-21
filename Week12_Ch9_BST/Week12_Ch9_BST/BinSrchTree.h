#pragma once
#include "BinaryTree.h"

//���� Ž�� Ʈ�� Ŭ����
class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { } //������ 
	~BinSrchTree(void) { } //�Ҹ���

	//���� Ʈ�� Ž�� ���� �Լ�
	BinaryNode* search(int key) { //Ž���� ���� key���� �Ű������� �޴´� 
		BinaryNode* node = search(root, key); //Ʈ������ key���� ã�� node�� �����Ѵ�.

		if (node != NULL) //��尡 ������� �ʴٸ� Ž������
			printf("Ž�� ����: Ű���� %d�� ��� = 0x%x\n", node->getData(), node);
		else //��尡 ����ִٸ� Ž�� ����
			printf("Ž�� ����: Ű���� %d�� ��� ����\n", key);
		return node; //search�� ����� ��带 ��ȯ
	}
	//���� key�� �Ű������� �����Ͽ� key���� �����ͷ� ���� node�� ã�´�.
	BinaryNode* search(BinaryNode* n, int key) {
		if (n == NULL) return NULL; //��尡 ����ٸ� NULL�� ��ȯ�Ѵ�.

		if (key == n->getData()) //key�� ����� ������ ���� ���ٸ� �� ��带 ��ȯ�Ѵ�.
			return n;
		else if (key < n->getData()) //key�� ����� ������ ������ �۴ٸ�
			return search(n->getLeft(), key); //���� ��带 search�Ѵ�.
		else //key�� ����� ������ ������ ũ�ٸ�
			return search(n->getRight(), key); //������ ��带 search�Ѵ�.
	}

	//���� Ž�� Ʈ���� ���� ����
	void insert(BinaryNode* n) {
		if (n == NULL) return; //��尡 ����ٸ� NULL�� ��ȯ
		if (isEmpty()) //��Ʈ�� ����ٸ�
			root = n; //��Ʈ�� �Ű������� ���� ��� n�� �����Ѵ�.
		else //��Ʈ�� ������� �ʴٸ�
			insert(root, n); //��Ʈ�� Ʈ���� n�� �����ϱ� ���� insert�Լ��� ȣ���Ѵ�.
	}
	void insert(BinaryNode* r, BinaryNode* n) {
		if (n->getData() == r->getData()) //��� n�� ��Ʈ�� ������ ���� ���ٸ�
			return; //�ش� �����Ͱ� Ʈ���� ���ԵǾ� �����Ƿ� �Լ��� �����Ѵ�.
		else if (n->getData() < r->getData()) { //��� n�� �����Ͱ� ��Ʈ�� �����ͺ��� ���� ��
			if (r->getLeft() == NULL) //��Ʈ�� ���� ��尡 ����ٸ�
				r->setLeft(n); //���� ��忡 ����
			else //���� ��尡 ������� �ʴٸ�
				insert(r->getLeft(), n); //���� ��带 ��Ʈ�� �� Ʈ���� �ٽ� ��� n�� �����ϱ� ���� �Լ��� ��������� ȣ���Ѵ�.
		}
		else { //��� n�� �����Ͱ� ��Ʈ�� �����ͺ��� Ŭ ��
			if (r->getRight() == NULL) //��Ʈ�� ������ ��尡 ����ٸ�
				r->setRight(n); //������ ��忡 ����
			else //��Ʈ�� ������ ��尡 ������� �ʴٸ�
				insert(r->getRight(), n); //������ ��带 ��Ʈ�� �� Ʈ���� �ٽ� ��� n�� �����ϱ� ���� �Լ��� ��������� ȣ���Ѵ�.
		}
	}

	//���� Ž�� Ʈ���� ���� ����
	void remove(int data) {
		if (isEmpty()) return; //��Ʈ�� ����ٸ� �Լ� ����

		BinaryNode* parent = NULL; //���ο� ����Ʈ�� ��� �������� parent�����Ѵ�.
		BinaryNode* node = root; //���ο� ���� Ʈ�� ��� �������� node�� root�� �����Ѵ�.
		while (node != NULL && node->getData() != data) { //node�� ������� �ʰų� ����� �����Ͱ� �Ű������� ���� (������)�����Ϳ� ���ٸ�
			parent = node; //parent�� node�� �����Ѵ�.
			node = (data < node->getData()) //������ �����Ͱ� node�� ������ ������ �۴ٸ� node�� ���� ��带 �ƴ϶�� ������ �뵵�� ��ȯ�Ͽ� �� node�� �����Ѵ�.
				? node->getLeft()
				: node->getRight();
		}

		//while�� ���� �Ŀ�
		if (node == NULL) { //node�� ����ٸ�
			printf(" Error: key is not in the tree!\n"); //�޼����� ����� �� �Լ��� �����Ѵ�.
			return;
		}
		else remove(parent, node); //node�� ������� �ʴٸ� ������ ����� �θ���� ������ ��带 �Ű������� �Ѱܼ� �ش� ��带 �����Ѵ�.
	}
	void remove(BinaryNode* parent, BinaryNode* node) {

		// case 1
		if (node->isLeaf()) { //��尡 �ܸ������ �� (���ʳ��� ������ ��� �� �� �������)
			if (parent == NULL) root = NULL; //parent��尡 ����ٸ� ��Ʈ ��带 NULL�� �����Ѵ�.
			else { //�θ� ��尡 ������� ���� ��
				if (parent->getLeft() == node) //�θ� ����� ���� ��尡 ������ ���� ���ٸ�
					parent->setLeft(NULL); //�θ� ����� ���� ��带 NULL�� set�Ͽ� ���� ���� ���� �����Ѵ�.
				else //�ƴ϶��
					parent->setRight(NULL); //������ ��带 �����Ѵ�.
			}
		}
		// case 2
		else if (node->getLeft() == NULL || node->getRight() == NULL) { //����� ���� ��尡 ����ų� ������ ��尡 ����� ��
			BinaryNode* child = (node->getLeft() != NULL)  //����� ���� ��尡 ������� �ʴٸ� 
				? node->getLeft() //���� ��带
				: node->getRight(); //�ƴ϶�� ������ ��带 ��ȯ�Ͽ� child ��� �����Ϳ� �����Ѵ�
			if (node == root) //������ ��尡 ��Ʈ�� ���ٸ�
				root = child; //��Ʈ�� ������ ����� �ڽ� ����� child�� �����Ѵ�.
			else { //������ ��尡 ��Ʈ�� �ٸ� ��
				if (parent->getLeft() == node) //�θ� ����� ���� ��尡 ������ ���� ���ٸ�
					parent->setLeft(child); //���� ��带 child�� set�Ѵ�.
				else //�ƴ϶��
					parent->setRight(child); //������ ��带 child�� set�Ѵ�.
			}
		}
		// case 3
		else { //�� ���� ��쿡��
			BinaryNode* succp = node; //������ ��带 ���ο� ���� succp�� �����Ѵ�.
			BinaryNode* succ = node->getRight(); //���ο� ���� succ�� ������ ����� ������ ��带 �����Ѵ�.
			while (succ->getLeft() != NULL) { //succ�� ���� ��尡 ������� ������
				succp = succ; //succp�� succ�� �����Ѵ�.
				succ = succ->getLeft(); //succ�� ����ؼ� �ڽ��� ���� ��带 ������ �����Ѵ�.
			}

			if (succp->getLeft() == succ) //succp�� ���� ��尡 succ�� ���� ���
				succp->setLeft(succ->getRight()); //succp�� ���� ��带 succ�� ������ ���� set�Ѵ�
			else //succp�� ���� ��尡 succ�� ���� ���� ���
				succp->setRight(succ->getRight()); //succp�� ������ ��带 succ�� ������ ���� set�Ѵ�.

			node->setData(succ->getData()); //������ ����� �����͸� succ�� �����ͷ� set�ϰ� 

			node = succ; //������ ��忡 succ�� �����Ѵ�.
		}
		delete node; //������ ����� node�� �޸𸮸� ��ȯ�Ѵ�.
	}
};

