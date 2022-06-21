#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

//이진 트리 클래스
class BinaryTree
{
protected:
	BinaryNode* root; //루트 노드를 저장하는 포인터 변수 
public:

	BinaryTree() : root(NULL) { } //생성자 : 루트 노드를 NULL로 초기화
	~BinaryTree() { } //소멸자

	void setRoot(BinaryNode* node) { root = node; } //루트 노드를 매개변수로 받은 노드로 set하는 함수
	BinaryNode* getRoot() { return root; } //루트 노드를 반환하는 함수
	bool isEmpty() { return root == NULL; } //루트 노드가 비었는지 확인하는 함수

	int	getCount() { return isEmpty() ? 0 : getCount(root); } //루트노드가 비었다면 0을 아니라면 재귀적으로 getCount함수를 호출하여 노드의 개수를 반환한다..
	int	getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); } //루트 노드가 비었다면 0을 아니라면 getLeafCount함수를 호출하여 단말노드의 개수를 반환한다.
	int	getHeight() { return isEmpty() ? 0 : getHeight(root); } //루트 노드가 비었다면 0을 아니라면 getHeight함수를 호출하여 높이를 반환한다.
	void inorder() { printf("\n   inorder: "); inorder(root); } //중위순환 순서대로 노드 값을 출력한다.
	void preorder() { printf("\n  preorder: "); preorder(root); } //전위순환 순서대로 노드 값을 출력한다.
	void postorder() { printf("\n postorder: "); postorder(root); } //후위 순환 순서대로 노드 값을 출력한다.

	//레벨 순회 함수
	void levelorder() {
		printf("\nlevelorder: ");
		if (!isEmpty()) { //루트 노드가 비어있지 않다면
			CircularQueue q;
			q.enqueue(root); //원형큐인 q에 루트 노드를 삽입한다.
			while (!q.isEmpty()) { //원형 큐가 비어있을 때까지 반복문을 반복한다.
				BinaryNode* n = q.dequeue(); //q에 있는 데이터를 빼내서 n에 저장한다.
				if (n != NULL) { //n이 비어있지 않다면
					printf(" [%2d]", n->getData()); //n의 값을 출력한다(방문)
					q.enqueue(n->getLeft()); //q에 n의 왼쪽 노드 값을 삽입한다.
					q.enqueue(n->getRight()); //q에 n의 오른쪽 노드 값을 삽입한다.
				}
			}
		}
		printf("\n");
	}

	//이진 트리의 노드 개수를 구하는 함수
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0; //매개 변수로 받은 노드가 비었다면 0을 반환
		return 1 + getCount(node->getLeft()) + getCount(node->getRight()); // 1을 더하고 왼쪽 노드의 getCount값과 
																		// 오른쪽 노드의 getCount값을 모두 합친 후 총 합을 반환
	
	}
	//이진 트리의 단말노드의 개수를 구하는 함수
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0; //매개 변수로 받은 노드가 비었다면 0을 반환
		if (node->isLeaf()) return 1; // 해당 노드가 단말노드라면 1을 반환
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight()); //그 외의 경우에는 왼쪽 노드의 단말 노드 값과
																					//오른쪽 노드의 단말노드 값을 합한 결과를 반환
	}
	//이진 트리의 높이를 구하는 함수
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0; //노드가 비었다면 0을 반환
		int	hLeft = getHeight(node->getLeft()); //왼쪽 노드의 높이를 구해서 hLeft 변수에 저장한다.
												//높이를 구할 때는 getHeight함수를 recursive call하여 구한다.
		int	hRight = getHeight(node->getRight()); //오른쪽 노드의 높이를 구해서 hRight 변수에 저장한다.(구하는 방식은 왼쪽과 같다)
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1; //왼쪽의 높이와 오른쪽의 높이를 비교해서 더 높은 값에 +1을 한 값을 반환한다.
	}

	//calcSize함수 오버로딩
	// 트리의 노드의 데이터들을 합친 값을 반환하는 함수
	int	calcSize() { return calcSize(root); }
	// 노드의 데이터 값의 합을 계산하는 함수
	int calcSize(BinaryNode* node) {
		if (node == NULL) return 0; //만약 노드가 비어있다면 0을 반환한다.
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight()); //노드의 데이터 값에 해당 노드의 왼쪽 노드들의 데이터를 합한 값,
																						// 오른쪽 노드들의 데이터를 합한 값을 전부 합쳐 결과를 반환한다. 
	}

	//evaluate함수의 오버로딩
	// 트리의 수식 계산 값을 반환하는 함수
	int evaluate() { return evaluate(root); }
	// 수식 계산 함수
	int evaluate(BinaryNode* node) {
		if (node == NULL) return 0; //노드가 비었다면 0을 반환
		if (node->isLeaf()) return node->getData(); //노드가 단말노드라면 데이터를 반환
		else { //단말노드가 아니라면
			int op1 = evaluate(node->getLeft()); //해당 노드의 왼쪽 노드의 수식 계산 값을 op1에 저장
			int op2 = evaluate(node->getRight()); //해당 노드의 오른쪽 노드의 수식 계산 값을 op2에 저장
			switch (node->getData()) { //수식에 따른 계산 case
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
		if (node != NULL) { //노드가 비어있지 않을 때
			if (node->getLeft() != NULL) inorder(node->getLeft()); //노드의 왼쪽 노드가 비어있지 않다면 왼쪽 노드의 중위순회 실행
			printf(" [%2d]", node->getData()); //노드의 데이터 출력(방문)
			if (node->getRight() != NULL) inorder(node->getRight()); //노드의 오른쪽 노드가 비어있지 않다면 오른쪽 노드의 중위순회 실행
		}
	}

	//전위순회
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%2d]", node->getData());  //노드의 데이터 출력(방문)
			if (node->getLeft() != NULL) preorder(node->getLeft()); //노드의 왼쪽 노드가 비어있지 않다면 왼쪽 노드의 전위순회 실행
			if (node->getRight() != NULL) preorder(node->getRight()); //노드의 오른쪽 노드가 비어있지 않다면 오른쪽 노드의 전위순회 실행
		}
	}

	//후위순회
	void postorder(BinaryNode* node) {
		if (node != NULL) { 
			if (node->getLeft() != NULL) postorder(node->getLeft()); //노드의 왼쪽 노드가 비어있지 않다면 왼쪽 노드의 후위순회 실행
			if (node->getRight() != NULL) postorder(node->getRight()); //노드의 오른쪽 노드가 비어있지 않다면 오른쪽 노드의 후위순회 실행
			printf(" [%2d]", node->getData()); //노드의 데이터 출력(방문)
		}
	}
};

