#include<iostream>
#include<string>
using namespace std;
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���

//���ӣ�
//"(()())", 6
//���أ�true
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
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
};
int main()
{
	Parenthesis P;
	string s;
	cin >> s;
	cout<<P.chkParenthesis(s, s.size());
	system("pause");
	return 0;
}