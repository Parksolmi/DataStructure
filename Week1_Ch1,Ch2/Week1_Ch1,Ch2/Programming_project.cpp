#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

//1부터 n까지의 합을 구하는 프로그래밍
//시간 복잡도 분석해보기

//방법A
int sumAlgorithmA(int n)
{
	int sum = 0; //수의 합을 저장하는 변수
	sum = n * (n + 1) / 2;

	return sum;
}

//방법B
int sumAlgorithmB(int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

//방법C
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
	clock_t start, finish; //시작시간과 끝난 시간을 저장할 변수
	double durationA, durationB, durationC; //실행 시간 측정 결과를 저장할 변수
	int num = 100000; //임의의 숫자

	//합의 결과 출력
	cout << "< 합의 결과 >" << endl;
	cout << "알고리즘 A : " << sumAlgorithmA(num) <<endl;
	cout << "알고리즘 B : " << sumAlgorithmA(num) <<endl;
	cout << "알고리즘 C : " << sumAlgorithmA(num) <<endl;

	//sumAlgorithmA
	start = clock(); //시작
	sumAlgorithmA(num); //실행 시간을 측정하고자 하는 코드
	finish = clock(); //끝
	durationA = (double)(finish - start) / CLOCKS_PER_SEC;

	//sumAlgorithmB
	start = clock(); //시작
	sumAlgorithmB(num); //실행 시간을 측정하고자 하는 코드
	finish = clock(); //끝
	durationB = (double)(finish - start) / CLOCKS_PER_SEC;

	//sumAlgorithmC
	start = clock(); //시작
	sumAlgorithmC(num); //실행 시간을 측정하고자 하는 코드
	finish = clock(); //끝
	durationC = (double)(finish - start) / CLOCKS_PER_SEC;

	//실행시간 결과 출력
	cout << endl;
	cout << "< 실행 시간 결과 >" << endl;
	cout << "알고리즘 A : " << durationA << "초 입니다." << endl; 
	cout << "알고리즘 B : " << durationB << "초 입니다." << endl; 
	cout << "알고리즘 C : " << durationC << "초 입니다." << endl; 
}