#include "ArrayStack.h"

bool CheckMatching(char* filename) {

	FILE* fp;
	fopen_s(&fp, filename, "r");

	if (fp == NULL)
		error((char*)"Error: 파일 존재하지 않습니다.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char	ch;

	bool smallQuatation = false; //작은 따옴표 안에 문자를 무시할 조건 변수
	bool doubleQuatation = false; //큰 따옴표 안에 문자를 무시할 조건 변수

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') nLine++;
		nChar++;

		//작은따옴표 무시
		if (ch == 39)
		{
			smallQuatation = !smallQuatation;
		}

		//큰따옴표 무시
		if (ch == 34)
		{
			doubleQuatation = !doubleQuatation;
		}
		
		//주석 무시
		if (ch == 47) // 아스키 코드 : (/=47)
		{
			nChar++;
			ch = getc(fp); //다음 문자
			
			if (ch == 47) //한줄 주석일 때(/ = 47)
			{
				while (ch != '\n')
				{
					nChar++;
					ch = getc(fp);
				}
			}

			else if (ch == 42) // 아스키 코드 : (* = 42)
			{
				while (true)
				{
					nChar++;
					ch = getc(fp); //다음 문자
					if (ch == 42)
					{
						nChar++;
						ch = getc(fp); //다음 문자
						if (ch == 47)
						{
							break;
						}
					}
					if (ch == '\n') //줄바꿈
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
	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("  Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf("  OK: 괄호닫기정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();

}

int main()
{
	CheckMatching((char*)"ArrayStack.h");
	CheckMatching((char*)"CheckBracketMain.cpp");
	CheckMatching((char*)"pp135-1-3.txt");
	CheckMatching((char*)"pp135-1-4.txt");
}