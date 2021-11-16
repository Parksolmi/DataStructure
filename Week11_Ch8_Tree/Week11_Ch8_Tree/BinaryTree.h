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
	//레벨순회
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) { //트리가 비어있지 않다면
			CircularQueue q;
			q.enqueue(root); //root를 원형큐에 삽입한다.
			while (!q.isEmpty()) { //원형큐가 비어있지 않다면
				BinaryNode* n = q.dequeue(); //큐에서 element를 하나 꺼내서 노드에 저장한다.
				if (n != NULL) { //n이 비어있지 않다면
					printf(" [%c] ", n->getData()); //n의 데이터를 출력(방문)
					q.enqueue(n->getLeft()); //n의 왼쪽 노드를 원형큐에 삽입한다.
					q.enqueue(n->getRight()); //n의 오른쪽 노드를 원형큐에 삽입한다.
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
	// 수식 계산 함수
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
	// 트리의 순회
	//중위순회
	void inorder(BinaryNode* node) {
		if (node != NULL) { //노드가 NULL이 아닐 때
			//왼쪽 노드가 존재한다면 왼쪽 노드의 중위순회를 실행
			if (node->getLeft() != NULL) inorder(node->getLeft());
			//왼쪽 노드가 존재하지 않으면 데이터 출력(방문)
			printf(" [%c] ", node->getData());
			//오른쪽 노드가 존재한다면 오른쪽 노드의 중위순회 실행
			if (node->getRight() != NULL) inorder(node->getRight());
		}
	}
	//전위순회
	void preorder(BinaryNode* node) {
		if (node != NULL) { //노드가 NULL이 아닐 때
			//노드의 데이터를 출력(방문)
			printf(" [%c] ", node->getData());
			//왼쪽 노드가 존재하면 왼쪽 노드의 전위순회를 실행
			if (node->getLeft() != NULL) preorder(node->getLeft());
			//오른쪽 노드가 존재하면 오른쪽 노드의 전위순회를 실행
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	//후위순회
	void postorder(BinaryNode* node) {
		if (node != NULL) { //노드가 NULL이 아닐 때
			//왼쪽 노드가 존재하면 왼쪽 노드의 후위순회를 실행
			if (node->getLeft() != NULL) postorder(node->getLeft());
			//오른쪽 노드가 존재하면 오른쪽 노드의 후위순회 실행
			if (node->getRight() != NULL) postorder(node->getRight());
			//노드의 데이터를 출력(방문)
			printf(" [%c] ", node->getData());
		}
	}
};

