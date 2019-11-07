#include<iostream>
#include<string>
using namespace std;
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
int main()
{
	string s;
	getline(cin, s);//输入一整行字符串，'.'也可以
	reverse(s.begin(), s.end());
	auto first = s.begin();
	while (first != s.end())
	{
		auto end = first;
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		reverse(first, end);
		if (end != s.end())
		{
			first = end + 1;
		}
		else
		{
			first = end;
		}
	}
	cout << s;
	system("pause");
	return 0;
}