#include "BinaryTree.h"

void main()
{
	BinaryTree tree; //����Ʈ�� ����

	//���� Ʈ���� ��� ����
	BinaryNode* d = new BinaryNode('D', NULL, NULL); //�ܸ����(b�� �ڽ�(����) ���)
	BinaryNode* e = new BinaryNode('E', NULL, NULL); //�ܸ����(b�� �ڽ�(������) ���)
	BinaryNode* b = new BinaryNode('B', d, e); //��� d�� e�� �θ��� , ��� A�� �ڽ�(����) ���
	BinaryNode* f = new BinaryNode('F', NULL, NULL); //�ܸ����(c�� �ڽ�(����) ���)
	BinaryNode* c = new BinaryNode('C', f, NULL); //��� f�� �θ��f, ��� A�� �ڽ�(������) ���
	BinaryNode* a = new BinaryNode('A', b, c); //��� b�� c�� �θ���

	tree.setRoot(a); //��� a�� ��Ʈ�� ����
	printf(" ����� ���� = %d\n", tree.getCount()); //����� ���� ���
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount()); //�ܸ� ����� ���� ���
	printf(" Ʈ���� ���� = %d\n", tree.getHeight()); //Ʈ���� ���� ���
	tree.inorder(); //������ȸ ����
	tree.preorder(); //������ȸ ����
	tree.postorder(); //������ȸ ����
	tree.levelorder(); //������ȸ ����

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
	printf(" ��� ��� = %d\n", tree2.evaluate());


	BinaryTree tree3;
	BinaryNode* m4 = new BinaryNode(200, NULL, NULL);
	BinaryNode* m5 = new BinaryNode(500, NULL, NULL);
	BinaryNode* m3 = new BinaryNode(100, m4, m5);
	BinaryNode* m2 = new BinaryNode(50, NULL, NULL);
	BinaryNode* m1 = new BinaryNode(0, m2, m3);
	tree3.setRoot(m1);
	printf(" ���丮 �뷮 ��� ��� = %d KB\n", tree3.calcSize());
}