#include<iostream>
#include<string>
using namespace std;
bool Isright(char ch)//判断输入的字符串是否合法
{
	return (ch >= '0'&&ch <= '9')
		|| (ch >= 'a'&&ch <= 'z')
		|| (ch >= 'A'&&ch <= 'Z');
}
bool IssPalindrome(string s)//判断是不是回文字符串
{
	for (auto& ch : s)//将小写变为大写
	{
		if (ch >= 'a'&&ch <= 'z')
			ch -= 32;
	}
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		while (begin < end&&!Isright(s[begin]))//判断字符串内有没有非字符，若有进入循环，跳过此位置。
			++begin;
		while (begin < end&&!Isright(s[end]))//判断字符串内有没有非字符，若有进入循环，跳过此位置。
			--end;
		if (s[begin] != s[end])
		{
			return false;
		}
		else
		{
			++begin;
			--end;
		}
	}
	return true;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		if (IssPalindrome(s))
		{
			cout << "是回文字符串" << endl;
			break;
		}
		else
		{
			cout << "不是回文字符串" << endl;
			break;
		}

	}
	system("pause");
	return 0;
}
