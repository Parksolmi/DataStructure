#include "CircularQueue.h"

int main()
{
	CircularQueue que; //CircularQueue.h에 있는 CircularQueue클래스의 객체를 선언하여 원형큐 자료구조를 생성한다.

	//for문으로 큐에 1번째 인덱스부터 9번째 인덱스까지 1~9까지 수 데이터를 삽입한다.
	for (int i = 1; i < 10; i++)
	{
		que.enqueue(i);
	}

	que.display(); //display함수를 이용하여 큐에 삽입되어 있는 데이터를 모두 보여준다.
	que.dequeue(); //dequeue함수를 이용하여 큐의 맨 앞의 데이터를 삭제한다.
	que.dequeue();
	que.dequeue();
	que.display(); //dequeue함수로 3개의 앞에 있는 항목을 삭제했기 때문에 
				   //4번째 인덱스부터 9번째 인덱스까지 4~9까지의 숫자가 남아있다.
				   //display함수를 이용하여 큐에 남아있는 데이터를 모두 보여준다.
}