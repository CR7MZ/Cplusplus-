#include<iostream>
#include<string>
using namespace std;
//输入一个字符串，求出该字符串包含的字符集合
//每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
//每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
void solution(char* str)
{
	string s(str);
	int count[256] = { 0 };
	for (auto e : s)
	{
		count[e]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (count[s[i]] == 1)
			cout << s[i];
		else if (count[s[i]]>1)
		{
			cout << s[i];
			count[s[i]] = 0;
		}
	}
}
int main()
{
	char* str = new char;
	cout << "请输入字符串";
	cin >> str;
	solution(str);
	system("pause");
	return 0;
}