#include<iostream>
#include<string>
#include<stack>
using namespace std;
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

//例子：
//"(()())", 6
//返回：true
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) //用count来计数，遇到'('就+1，遇到')'就减1；最后count为0时返回1，反之返回0
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
	bool chkParenthesis2(string A, int n)//用栈解决，遇到'('压入栈，遇到')'说明遇到匹配的，出栈。
	{
		stack<char> s;
		for (int i = 0; i<n; i++)
		{
			if (A[i] == '(')
				s.push(A[i]);
			else{
				if (s.empty())//如果此时栈为空说明，没有匹配的，返回false
					return false;
				else
					s.pop();//反之，出栈
			}
		}
		if (s.empty())//如果将字符串遍历完后，栈为空，说明全部匹配。
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