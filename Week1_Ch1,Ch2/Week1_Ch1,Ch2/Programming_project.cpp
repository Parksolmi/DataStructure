#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

//1���� n������ ���� ���ϴ� ���α׷���
//�ð� ���⵵ �м��غ���

//���A
int sumAlgorithmA(int n)
{
	int sum = 0; //���� ���� �����ϴ� ����
	sum = n * (n + 1) / 2;

	return sum;
}

//���B
int sumAlgorithmB(int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

//���C
int sumAlgorithmC(int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum += 1;
		}
	}

	return sum;
}

void main(void)
{
	clock_t start, finish; //���۽ð��� ���� �ð��� ������ ����
	double durationA, durationB, durationC; //���� �ð� ���� ����� ������ ����
	int num = 100000; //������ ����

	//���� ��� ���
	cout << "< ���� ��� >" << endl;
	cout << "�˰��� A : " << sumAlgorithmA(num) <<endl;
	cout << "�˰��� B : " << sumAlgorithmA(num) <<endl;
	cout << "�˰��� C : " << sumAlgorithmA(num) <<endl;

	//sumAlgorithmA
	start = clock(); //����
	sumAlgorithmA(num); //���� �ð��� �����ϰ��� �ϴ� �ڵ�
	finish = clock(); //��
	durationA = (double)(finish - start) / CLOCKS_PER_SEC;

	//sumAlgorithmB
	start = clock(); //����
	sumAlgorithmB(num); //���� �ð��� �����ϰ��� �ϴ� �ڵ�
	finish = clock(); //��
	durationB = (double)(finish - start) / CLOCKS_PER_SEC;

	//sumAlgorithmC
	start = clock(); //����
	sumAlgorithmC(num); //���� �ð��� �����ϰ��� �ϴ� �ڵ�
	finish = clock(); //��
	durationC = (double)(finish - start) / CLOCKS_PER_SEC;

	//����ð� ��� ���
	cout << endl;
	cout << "< ���� �ð� ��� >" << endl;
	cout << "�˰��� A : " << durationA << "�� �Դϴ�." << endl; 
	cout << "�˰��� B : " << durationB << "�� �Դϴ�." << endl; 
	cout << "�˰��� C : " << durationC << "�� �Դϴ�." << endl; 
}