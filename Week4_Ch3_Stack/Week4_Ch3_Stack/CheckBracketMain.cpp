#include "ArrayStack.h"

bool CheckMatching(char* filename) {

	FILE* fp;
	fopen_s(&fp, filename, "r");

	if (fp == NULL)
		error((char*)"Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char	ch;

	bool smallQuatation = false; //���� ����ǥ �ȿ� ���ڸ� ������ ���� ����
	bool doubleQuatation = false; //ū ����ǥ �ȿ� ���ڸ� ������ ���� ����

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') nLine++;
		nChar++;

		//��������ǥ ����
		if (ch == 39)
		{
			smallQuatation = !smallQuatation;
		}

		//ū����ǥ ����
		if (ch == 34)
		{
			doubleQuatation = !doubleQuatation;
		}
		
		//�ּ� ����
		if (ch == 47) // �ƽ�Ű �ڵ� : (/=47)
		{
			nChar++;
			ch = getc(fp); //���� ����
			
			if (ch == 47) //���� �ּ��� ��(/ = 47)
			{
				while (ch != '\n')
				{
					nChar++;
					ch = getc(fp);
				}
			}

			else if (ch == 42) // �ƽ�Ű �ڵ� : (* = 42)
			{
				while (true)
				{
					nChar++;
					ch = getc(fp); //���� ����
					if (ch == 42)
					{
						nChar++;
						ch = getc(fp); //���� ����
						if (ch == 47)
						{
							break;
						}
					}
					if (ch == '\n') //�ٹٲ�
						nLine++;
				}
			}
		}


		if ((ch == '[' || ch == '(' || ch == '{') && smallQuatation==false && doubleQuatation==false)
			stack.push(ch);
		else if ((ch == ']' || ch == ')' || ch == '}') && smallQuatation == false && doubleQuatation == false)
		{
			int prev = stack.pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.isEmpty())
		printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty();

}

int main()
{
	CheckMatching((char*)"ArrayStack.h");
	CheckMatching((char*)"CheckBracketMain.cpp");
	CheckMatching((char*)"pp135-1-3.txt");
	CheckMatching((char*)"pp135-1-4.txt");
}