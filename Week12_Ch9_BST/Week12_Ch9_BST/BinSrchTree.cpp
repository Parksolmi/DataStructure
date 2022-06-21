#include "BinSrchTree.h"

void main()
{
	//이진 탐색 트리 생성
	BinSrchTree tree;

	// 삽입 연산 테스트
	tree.insert(new BinaryNode(35)); //루트 노드로 삽입된다.
	//루트 노드를 기준으로(루트 노드 아래에 또 노드가 있다면 그 해당 노드를 기준으로) 작은 노드들은 왼쪽으로 큰 노드들은 오른쪽에 삽입 된다.
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));

	printf(" 노드의 개수 = %d\n", tree.getCount()); //이진 탐색 트리의 노드 개수 출력
	printf(" 단말의 개수 = %d\n", tree.getLeafCount()); //이진 탐색 트리의 단말 노드의 개수 출력
	printf(" 트리의 높이 = %d", tree.getHeight()); //이진 탐색 트리의 높이 출력

	tree.inorder(); //중위 순회 실행
	tree.preorder(); //전위 순회 실행
	tree.postorder(); //후위 순회 실행
	tree.levelorder(); //레벨 순회 실행

	tree.search(26); //노드 26 탐색
	tree.search(25); //노드 25 탐색

	// 삭제 연산 테스트
	printf(" 삭제: case 1 ==> 노드  3 삭제");
	tree.remove(3);
	tree.levelorder();
	printf(" 삭제: case 2 ==> 노드 68 삭제");
	tree.remove(68);
	tree.levelorder();
	printf(" 삭제: case 3 ==> 노드 18 삭제");
	tree.remove(18);
	tree.levelorder();
	printf(" 삭제: case 3 ==> 노드 35 삭제 (루트 노드 삭제)");
	tree.remove(35);
	tree.levelorder();

	// 최종 트리 정보 출력
	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
}
