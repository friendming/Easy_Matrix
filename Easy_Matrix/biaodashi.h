#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*�ƶϷ��ż�����ȹ�ϵ����
*1��ʾ>,0��ʾ=,-1��ʾ<
*c1ջ�ڵ������c2ջ������
*/
int Judge(char c1, char c2)
{
	int a1, a2;
	if ('+' == c1 || '-' == c1) a1 = 3;
	if ('*' == c1 || '/' == c1)a1 = 5;
	if ('(' == c1) a1 = 1;
	if (')' == c1) a1 = 7;
	if ('#' == c1) a1 = 0;

	if ('+' == c2 || '-' == c2)a2 = 2;
	if ('*' == c2 || '/' == c2)a2 = 4;
	if ('(' == c2) a2 = 6;
	if (')' == c2) a2 = 1;
	if ('#' == c2) a2 = 0;
	if (a1>a2) return 1;
	if (a1 == a2) return 0;
	if (a1<a2) return -1;
}
//�������㺯��
double run(char c, double d1, double d2)
{
	switch (c)
	{
	case '+':
		return d1 + d2;
		break;
	case '-':
		return d1 - d2;
		break;
	case'*':
		return d1 * d2;
		break;
	case '/':
		return d1 / d2;
		break;
	default:
		return 0.0;
		break;
	}
}
int main()
{
	char opp[] = "+-*/()#";
	char* op = opp;
	string str;
	cin >> str;
	//�����ʽ�ַ���str����'#'������ʶ��
	str.append(1, '#');
	stack<char> OPTR;//�����ջ
	stack<double> OPND;//������ջ
	int a = -1;
	//�Ƚ�#������ջ
	OPTR.push('#');
	while (true)
	{
		int b = a + 1;
		a = str.find_first_of(op, a + 1);
		if (a == string::npos) break;
		if (a != b)
		{
			string ss(str, b, a - b);
			double d = atof(ss.c_str());
			//��������ջ
			OPND.push(d);
		}
		//��������ȼ����^
		int ju = Judge(OPTR.top(), str[a]);
		if (-1 == ju)//ջ�����ȼ���ֱ����ջ
		{
			OPTR.push(str[a]);
		}
		if (0 == ju)//ջ�������ȼ�������ջ
		{
			OPTR.pop();
		}
		if (1 == ju)//ջ�����ȼ���,��ջ��������
		{
			double d1 = OPND.top();
			OPND.pop();
			double d2 = OPND.top();
			OPND.pop();

			//d1 = run(OPTR.top(), d2, d1);

			//��������ջ
			OPND.push(d1);
			OPTR.pop();
			a--;
		}
	}
	//ɾ�����ʽ����'#'������ʶ��
	str.erase(str.length() - 1, 1);
	cout << str << " = " << OPND.top() << endl;
}