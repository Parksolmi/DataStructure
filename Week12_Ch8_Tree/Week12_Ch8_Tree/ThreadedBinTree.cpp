#include "ThreadedBinTree.h"

void main()
{
	ThreadedBinTree tree;

	//           G
	//       C       F
	//     A	   B   D   E
	ThreadedBinNode* n1 = new ThreadedBinNode('A', NULL, NULL, true); //n1�� �����ʹ� A�̴�.
																	  //����, ������ �����Ͱ� ��� NULL�̹Ƿ� �ܸ�����̴�.
																	  //������� ����Ǿ��ִ�.
	ThreadedBinNode* n2 = new ThreadedBinNode('B', NULL, NULL, true); //n2�� �����ʹ� B�̴�.
																	  //����, ������ �����Ͱ� ��� NULL�̹Ƿ� �ܸ�����̴�.
																	  //������� ����Ǿ��ִ�.
	ThreadedBinNode* n3 = new ThreadedBinNode('C', n1, n2, false); //n3�� �����ʹ� C�̰� n1�� n2�� �θ����̴�.
																   //������� ����Ǿ����� �ʴ�.
	ThreadedBinNode* n4 = new ThreadedBinNode('D', NULL, NULL, true); //n4�� �����ʹ� D�̴�.
																	  //����, ������ �����Ͱ� ��� NULL�̹Ƿ� �ܸ�����̴�.
																	  //������� ����Ǿ��ִ�.
	ThreadedBinNode* n5 = new ThreadedBinNode('E', NULL, NULL, false);//n5�� �����ʹ� E�̴�.
																	  //����, ������ �����Ͱ� ��� NULL�̹Ƿ� �ܸ�����̴�.
																	  //������� ����Ǿ����� �ʴ�.
	ThreadedBinNode* n6 = new ThreadedBinNode('F', n4, n5, false); //n6�� �����ʹ� F�̰� n4�� n5�� �θ����̴�.
																   //������� ����Ǿ����� �ʴ�.
	ThreadedBinNode* n7 = new ThreadedBinNode('G', n3, n6, false); //n7�� �����ʹ� G�̰� n3�� n6�� �θ����̴�.
																   //������� ����Ǿ����� �ʴ�.
	tree.setRoot(n7); //��Ʈ ���� n7�̴�.
	// ������ ���� 
	n1->setRight(n3); //n1�� ������ �����Ͱ� n3�� ����Ű���� �����Ѵ�.
	n2->setRight(n7); //n2�� ������ �����Ͱ� n7�� ����Ű���� �����Ѵ�.
	n4->setRight(n6); //n4�� ������ �����Ͱ� n6�� ����Ű���� �����Ѵ�.

	// ���� ��ȸ
	tree.threadedInorder(); //���� ��ȸ ������� ��带 ����Ѵ�.
}