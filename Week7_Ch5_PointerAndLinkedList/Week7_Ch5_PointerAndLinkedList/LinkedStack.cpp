#include "LinkedStack.h"

int main()
{
	LinkedStack stack; //스택 생성
	stack.push(new Node(2015130007, (char*)"홍길동", (char*)"컴퓨터공학과")); //데이터 push
	stack.push(new Node(2015130100, (char*)"이순신", (char*)"기계공학과")); //데이터 push
	stack.push(new Node(2015130135, (char*)"황희", (char*)"법학과")); //데이터 push
	stack.display(); //스택에 있는 데이터를 보여준다.

	Node* node = stack.pop(); //스택의 맨 위에 있는 데이터를 pop하여 node에 저장한다.
	printf("[Pop항목]\n");
	node->display(); //node를 display한다.
	printf("\n");
	delete node; //node를 지운다.
	stack.display(); //스택에 남은 데이터를 display한다.
}