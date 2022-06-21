#pragma once
#include "BinaryTree.h"

//이진 탐색 트리 클래스
class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { } //생성자 
	~BinSrchTree(void) { } //소멸자

	//이진 트리 탐색 연산 함수
	BinaryNode* search(int key) { //탐색할 값인 key값을 매개변수로 받는다 
		BinaryNode* node = search(root, key); //트리에서 key값을 찾아 node에 저장한다.

		if (node != NULL) //노드가 비어있지 않다면 탐색성공
			printf("탐색 성공: 키값이 %d인 노드 = 0x%x\n", node->getData(), node);
		else //노드가 비어있다면 탐색 실패
			printf("탐색 실패: 키값이 %d인 노드 없음\n", key);
		return node; //search한 결과인 노드를 반환
	}
	//노드와 key를 매개변수로 전달하여 key값을 데이터로 가진 node를 찾는다.
	BinaryNode* search(BinaryNode* n, int key) {
		if (n == NULL) return NULL; //노드가 비었다면 NULL을 반환한다.

		if (key == n->getData()) //key가 노드의 데이터 값과 같다면 그 노드를 반환한다.
			return n;
		else if (key < n->getData()) //key가 노드의 데이터 값보다 작다면
			return search(n->getLeft(), key); //왼쪽 노드를 search한다.
		else //key가 노드의 데이터 값보다 크다면
			return search(n->getRight(), key); //오른쪽 노드를 search한다.
	}

	//이진 탐색 트리의 삽입 연산
	void insert(BinaryNode* n) {
		if (n == NULL) return; //노드가 비었다면 NULL을 반환
		if (isEmpty()) //루트가 비었다면
			root = n; //루트에 매개변수로 받은 노드 n을 삽입한다.
		else //루트가 비어있지 않다면
			insert(root, n); //루트의 트리에 n을 삽입하기 위해 insert함수를 호출한다.
	}
	void insert(BinaryNode* r, BinaryNode* n) {
		if (n->getData() == r->getData()) //노드 n이 루트의 데이터 값과 같다면
			return; //해당 데이터가 트리에 삽입되어 있으므로 함수를 종료한다.
		else if (n->getData() < r->getData()) { //노드 n의 데이터가 루트의 데이터보다 작을 때
			if (r->getLeft() == NULL) //루트의 왼쪽 노드가 비었다면
				r->setLeft(n); //왼쪽 노드에 삽입
			else //왼쪽 노드가 비어있지 않다면
				insert(r->getLeft(), n); //왼쪽 노드를 루트로 둔 트리에 다시 노드 n을 삽입하기 위해 함수를 재귀적으로 호출한다.
		}
		else { //노드 n의 데이터가 루트의 데이터보다 클 때
			if (r->getRight() == NULL) //루트의 오른쪽 노드가 비었다면
				r->setRight(n); //오른쪽 노드에 삽입
			else //루트의 오른쪽 노드가 비어있지 않다면
				insert(r->getRight(), n); //오른쪽 노드를 루트로 둔 트리에 다시 노드 n을 삽입하기 위해 함수를 재귀적으로 호출한다.
		}
	}

	//이진 탐색 트리의 삭제 연산
	void remove(int data) {
		if (isEmpty()) return; //루트가 비었다면 함수 종료

		BinaryNode* parent = NULL; //새로운 이진트리 노드 포인터인 parent생성한다.
		BinaryNode* node = root; //새로운 이진 트리 노드 포인터인 node에 root를 삽입한다.
		while (node != NULL && node->getData() != data) { //node가 비어있지 않거나 노드의 데이터가 매개변수로 받은 (삭제할)데이터와 같다면
			parent = node; //parent에 node를 삽입한다.
			node = (data < node->getData()) //삭제할 데이터가 node의 데이터 값보다 작다면 node의 왼쪽 노드를 아니라면 오른쪽 노도를 반환하여 그 node에 저장한다.
				? node->getLeft()
				: node->getRight();
		}

		//while문 종료 후에
		if (node == NULL) { //node가 비었다면
			printf(" Error: key is not in the tree!\n"); //메세지를 출력한 후 함수를 종료한다.
			return;
		}
		else remove(parent, node); //node가 비어있지 않다면 삭제할 노드의 부모노드와 삭제할 노드를 매개변수로 넘겨서 해당 노드를 삭제한다.
	}
	void remove(BinaryNode* parent, BinaryNode* node) {

		// case 1
		if (node->isLeaf()) { //노드가 단말노드일 때 (왼쪽노드와 오른쪽 노드 둘 다 비어있음)
			if (parent == NULL) root = NULL; //parent노드가 비었다면 루트 노드를 NULL로 설정한다.
			else { //부모 노드가 비어있지 않을 때
				if (parent->getLeft() == node) //부모 노드의 왼쪽 노드가 삭제할 노드와 같다면
					parent->setLeft(NULL); //부모 노드의 왼쪽 노드를 NULL로 set하여 연결 고리를 끊어 삭제한다.
				else //아니라면
					parent->setRight(NULL); //오른쪽 노드를 삭제한다.
			}
		}
		// case 2
		else if (node->getLeft() == NULL || node->getRight() == NULL) { //노드의 왼쪽 노드가 비었거나 오른쪽 노드가 비었을 때
			BinaryNode* child = (node->getLeft() != NULL)  //노드의 왼쪽 노드가 비어있지 않다면 
				? node->getLeft() //왼쪽 노드를
				: node->getRight(); //아니라면 오른쪽 노드를 반환하여 child 노드 포인터에 저장한다
			if (node == root) //삭제할 노드가 루트와 같다면
				root = child; //루트에 삭제할 노드의 자식 노드인 child를 삽입한다.
			else { //삭제할 노드가 루트와 다를 때
				if (parent->getLeft() == node) //부모 노드의 왼쪽 노드가 삭제할 노드와 같다면
					parent->setLeft(child); //왼쪽 노드를 child로 set한다.
				else //아니라면
					parent->setRight(child); //오른쪽 노드를 child로 set한다.
			}
		}
		// case 3
		else { //그 외의 경우에는
			BinaryNode* succp = node; //삭제할 노드를 새로운 변수 succp에 저장한다.
			BinaryNode* succ = node->getRight(); //새로운 변수 succ에 삭제할 노드의 오른쪽 노드를 삽입한다.
			while (succ->getLeft() != NULL) { //succ의 왼쪽 노드가 비어있을 때까지
				succp = succ; //succp에 succ를 삽입한다.
				succ = succ->getLeft(); //succ는 계속해서 자신의 왼쪽 노드를 가져와 저장한다.
			}

			if (succp->getLeft() == succ) //succp의 왼쪽 노드가 succ와 같은 경우
				succp->setLeft(succ->getRight()); //succp의 왼쪽 노드를 succ의 오른쪽 노드로 set한다
			else //succp의 왼쪽 노드가 succ와 같지 않은 경우
				succp->setRight(succ->getRight()); //succp의 오른쪽 노드를 succ의 오른쪽 노드로 set한다.

			node->setData(succ->getData()); //삭제할 노드의 데이터를 succ의 데이터로 set하고 

			node = succ; //삭제할 노드에 succ를 삽입한다.
		}
		delete node; //삭제할 노드인 node의 메모리를 반환한다.
	}
};

