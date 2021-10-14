#include <iostream>
#include <iomanip>

using namespace std;

int** alloc2DInt(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		return NULL;
	}

	int** mat = new int* [rows]; //���� �� ��ŭ 1���� �迭 ����
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[cols]; //1���� �迭�� �� ĭ���� �ٽ� 1���� �迭�� ���� ����
	}
	return mat;
}

void free2DInt(int** mat, int rows, int cols = 0)
{
	if (mat != NULL)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i]; //�ϳ��� �� �ݳ�
		}
		delete[] mat; //������ 1���� �迭 �ݳ�
	}
}

void set2DRandom(int** mat, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = rand() % 100; //0���� 99���� ���� ���� �ֱ�
		}
	}
}

void print2DInt(int** mat, int rows, int cols)
{
	cout << "���� ��" << rows << "���� ��" << cols << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << mat[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int** mat; //2���� �迭 ����
	int rows, cols;

	cout << "��� ���� ũ�⸦ �Է��Ͻÿ� : ";
	cin >> rows >> cols;
	
	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);

}