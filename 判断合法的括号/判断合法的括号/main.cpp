#include<iostream>
#include<string>
#include<stack>
using namespace std;
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

//���ӣ�
//"(()())", 6
//���أ�true
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) //��count������������'('��+1������')'�ͼ�1�����countΪ0ʱ����1����֮����0
	{
		for (auto e:A)
		{
			if (e != '('&&e != ')')
				return false;
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(')
				count++;
		}
		for (int i = 0; i < n; i++)
		{
			if (A[i] == ')')
				count--;
		}
		if (count == 0)
			return true;
		else
			return false;
	}
	bool chkParenthesis2(string A, int n)//��ջ���������'('ѹ��ջ������')'˵������ƥ��ģ���ջ��
	{
		stack<char> s;
		for (int i = 0; i<n; i++)
		{
			if (A[i] == '(')
				s.push(A[i]);
			else{
				if (s.empty())//�����ʱջΪ��˵����û��ƥ��ģ�����false
					return false;
				else
					s.pop();//��֮����ջ
			}
		}
		if (s.empty())//������ַ����������ջΪ�գ�˵��ȫ��ƥ�䡣
			return true;
		else
			return false;
	}
};
int main()
{
	Parenthesis P;
	string s;
	cin >> s;
	cout<<P.chkParenthesis2(s, s.size());
	system("pause");
	return 0;
}