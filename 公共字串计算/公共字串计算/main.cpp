#include<iostream>
using namespace std;
#include<string>
//https://www.nowcoder.com/questionTerminal/98dc82c094e043ccb7e0570e5342dd1b


void Func()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size()>s2.size())//s1必须为最小的字符串
			swap(s1, s2);
		string tmp;//保存最长的公共字符串
		int max = 0;//保存最长公共字符串的长度
		for (int i = 0; i<s1.size(); i++)//从s1开头找字符串，在s2中找，找到了s1刚才找的字符串向后延伸，
		{
			for (int j = i; j<s1.size(); j++)
			{
				tmp = s1.substr(i, j - i + 1);
				if (s2.find(tmp) == std::string::npos)
					break;
				if (tmp.size()>max)
					max = tmp.size();//将在s2中找到的字符串大小，如果大于之前的值，则赋值给max
			}
		}
		cout << max << endl;
	}
}
int main()
{
	Func();
	return 0;
}