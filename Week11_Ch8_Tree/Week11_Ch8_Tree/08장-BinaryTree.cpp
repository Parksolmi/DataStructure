#include "BinaryTree.h"

void main()
{
	BinaryTree tree; //이진트리 생성

	//이진 트리에 노드 삽입
	BinaryNode* d = new BinaryNode('D', NULL, NULL); //단말노드(b의 자식(왼쪽) 노드)
	BinaryNode* e = new BinaryNode('E', NULL, NULL); //단말노드(b의 자식(오른쪽) 노드)
	BinaryNode* b = new BinaryNode('B', d, e); //노드 d와 e의 부모노드 , 노드 A의 자식(왼쪽) 노드
	BinaryNode* f = new BinaryNode('F', NULL, NULL); //단말노드(c의 자식(왼쪽) 노드)
	BinaryNode* c = new BinaryNode('C', f, NULL); //노드 f의 부모늗, 노드 A의 자식(오른쪽) 노드
	BinaryNode* a = new BinaryNode('A', b, c); //노드 b와 c의 부모노드

	tree.setRoot(a); //노드 a를 루트로 설정
	printf(" 노드의 개수 = %d\n", tree.getCount()); //노드의 개수 출력
	printf(" 단말의 개수 = %d\n", tree.getLeafCount()); //단말 노드의 개수 출력
	printf(" 트리의 높이 = %d\n", tree.getHeight()); //트리의 높이 출력
	tree.inorder(); //중위순회 시행
	tree.preorder(); //전위순회 시행
	tree.postorder(); //후위순회 시행
	tree.levelorder(); //레벨순회 시행

	BinaryTree tree2;
	//           +
	//       *       -
	//     3	   2   5   6
	BinaryNode* n1 = new BinaryNode(3, NULL, NULL);
	BinaryNode* n2 = new BinaryNode(2, NULL, NULL);
	BinaryNode* n3 = new BinaryNode('*', n1, n2);
	BinaryNode* n4 = new BinaryNode(5, NULL, NULL);
	BinaryNode* n5 = new BinaryNode(6, NULL, NULL);
	BinaryNode* n6 = new BinaryNode('-', n4, n5);
	BinaryNode* n7 = new BinaryNode('+', n3, n6);
	tree2.setRoot(n7);
	printf(" 계산 결과 = %d\n", tree2.evaluate());


	BinaryTree tree3;
	BinaryNode* m4 = new BinaryNode(200, NULL, NULL);
	BinaryNode* m5 = new BinaryNode(500, NULL, NULL);
	BinaryNode* m3 = new BinaryNode(100, m4, m5);
	BinaryNode* m2 = new BinaryNode(50, NULL, NULL);
	BinaryNode* m1 = new BinaryNode(0, m2, m3);
	tree3.setRoot(m1);
	printf(" 디렉토리 용량 계산 결과 = %d KB\n", tree3.calcSize());
}