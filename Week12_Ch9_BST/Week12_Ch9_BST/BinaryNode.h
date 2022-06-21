#pragma once
#include <stdio.h>

//이진트리 노드 클래스
class BinaryNode
{
protected:
	int			data; //노드의 데이터
	BinaryNode* left; //왼쪽 노드를 가리키는 포인터
	BinaryNode* right; //오른쪽 노드를 가리키는 포인터
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) //생성자 
		//데이터=0, 왼쪽 노드 포인터 = NULL, 오른쪽 노드 포인터 = NULL로 초기화
		: data(val), left(l), right(r) { }
	~BinaryNode() { } //소멸자

	void		setData(int val) { data = val; } //매개변수로 받은 값을 노드의 데이터로 set하는 함수
	void		setLeft(BinaryNode* l) { left = l; } //매개변수로 받은 포인터를 노드의 왼쪽 포인터로 set하는 함수
	void		setRight(BinaryNode* r) { right = r; } //매개변수로 받은 포인터를 노드의 오른쪽 포인터로 set하는 함수
	int			getData() { return data; } //노드의 데이터를 get하는 함수
	BinaryNode* getLeft() { return left; } //노드의 왼쪽 노드를 get하는 함수
	BinaryNode* getRight() { return right; } //노드의 오른쪽 노드를 get하는 함수
	bool		isLeaf() { return left == NULL && right == NULL; } //단말노드인지 아닌지 확인하는 함수
};

