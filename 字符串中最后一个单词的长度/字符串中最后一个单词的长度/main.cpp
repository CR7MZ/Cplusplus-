#include<iostream>
using namespace std;
#include<string>
#if 0
int main()
{
	string a;
	while (getline(cin, a))//如果直接cin>>输入会造成遇见空格字符(' ')就会直接结束，
		//导致后面内容无法输入，所以要用getline(cin,a))。
	{
		size_t pos = a.rfind(' ');//从字符串后面查找，知道第一个空格，返回空格的位置。
		cout << a.size() - 1 - pos << endl;//计算出空格后面字符串的长度。
	}	
	system("pause");
	return 0;
}
#endif
int main()
{
	string s;
	while (getline(cin, s))
	{
		size_t pos = s.rfind(' ');
		pos += 1;//记录Pos下一位的坐。
		string ss = s.substr(pos);//截取从pos位到'\0'的字符串。
		cout << ss.size() << endl;//输出截取后字符串的长度
	}
	system("pause");
	return 0;
}