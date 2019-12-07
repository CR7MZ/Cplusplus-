#include<iostream>
using namespace std;
#include<string>
//输入一个字符串，当遇到第一个与之前的遍历过得字符串中重复的字符，输出之前的字符串。
//例子：abcab-->abc；abcccba--->abc

//解析：建立一个空字符串result，遍历字符串s，将字符串s中的每个字符输入到result中，每次加到result中时，
//将此时要加入到result中的字符与现有的result中每个元素比较，如果有重复，则直接输出答案。

bool adjust(char x,const string& result)//判断result有没有与要输入的字符 相同的字符
{
	for (auto e : result)
	{
		if (e == x)
		{
			return false;
		}
	}
	return true;
}
void Func()
{
	string s;
	cin >> s;
	string result;//空字符串
	result.resize(s.size());
	for (int i = 0; i < s.size(); i++)//遍历输入的字符串
	{
		if (adjust(s[i], result))//如果result中没有此时要加入的字符时，则加入
		{
			result[i] = s[i];
		}
		else//如果result中有此时要加入的字符，则跳出循环，输出答案。
		{
			break;
		}
	}
	cout << result << endl;
}
int main()
{
	Func();
	system("pause");
	return 0;
}