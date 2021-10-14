#include <iostream>
#include <iomanip>

using namespace std;

int** alloc2DInt(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		return NULL;
	}

	int** mat = new int* [rows]; //행의 수 만큼 1차원 배열 선언
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[cols]; //1차원 배열의 한 칸마다 다시 1차원 배열이 들어가는 구조
	}
	return mat;
}

void free2DInt(int** mat, int rows, int cols = 0)
{
	if (mat != NULL)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i]; //하나씩 다 반납
		}
		delete[] mat; //마지막 1차원 배열 반납
	}
}

void set2DRandom(int** mat, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = rand() % 100; //0부터 99까지 랜덤 숫자 넣기
		}
	}
}

void print2DInt(int** mat, int rows, int cols)
{
	cout << "행의 수" << rows << "열의 수" << cols << endl;
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
	int** mat; //2차원 배열 변수
	int rows, cols;

	cout << "행과 열의 크기를 입력하시오 : ";
	cin >> rows >> cols;
	
	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);

}