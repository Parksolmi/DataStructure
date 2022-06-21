#include "ThreadedBinTree.h"

void main()
{
	ThreadedBinTree tree;

	//           G
	//       C       F
	//     A	   B   D   E
	ThreadedBinNode* n1 = new ThreadedBinNode('A', NULL, NULL, true); //n1의 데이터는 A이다.
																	  //왼쪽, 오른쪽 포인터가 모두 NULL이므로 단말노드이다.
																	  //스레드는 연결되어있다.
	ThreadedBinNode* n2 = new ThreadedBinNode('B', NULL, NULL, true); //n2의 데이터는 B이다.
																	  //왼쪽, 오른쪽 포인터가 모두 NULL이므로 단말노드이다.
																	  //스레드는 연결되어있다.
	ThreadedBinNode* n3 = new ThreadedBinNode('C', n1, n2, false); //n3의 데이터는 C이고 n1과 n2의 부모노드이다.
																   //스레드는 연결되어있지 않다.
	ThreadedBinNode* n4 = new ThreadedBinNode('D', NULL, NULL, true); //n4의 데이터는 D이다.
																	  //왼쪽, 오른쪽 포인터가 모두 NULL이므로 단말노드이다.
																	  //스레드는 연결되어있다.
	ThreadedBinNode* n5 = new ThreadedBinNode('E', NULL, NULL, false);//n5의 데이터는 E이다.
																	  //왼쪽, 오른쪽 포인터가 모두 NULL이므로 단말노드이다.
																	  //스레드는 연결되어있지 않다.
	ThreadedBinNode* n6 = new ThreadedBinNode('F', n4, n5, false); //n6의 데이터는 F이고 n4와 n5의 부모노드이다.
																   //스레드는 연결되어있지 않다.
	ThreadedBinNode* n7 = new ThreadedBinNode('G', n3, n6, false); //n7의 데이터는 G이고 n3와 n6의 부모노드이다.
																   //스레드는 연결되어있지 않다.
	tree.setRoot(n7); //루트 노드는 n7이다.
	// 스레드 설정 
	n1->setRight(n3); //n1의 오른쪽 포인터가 n3를 가리키도록 연결한다.
	n2->setRight(n7); //n2의 오른쪽 포인터가 n7을 가리키도록 연결한다.
	n4->setRight(n6); //n4의 오른쪽 포인터가 n6을 가리키도록 연결한다.

	// 중위 순회
	tree.threadedInorder(); //중위 순회 순서대로 노드를 출력한다.
}