#include<iostream>
#include<string>
using namespace std;
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

//例子：
//"(()())", 6
//返回：true
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