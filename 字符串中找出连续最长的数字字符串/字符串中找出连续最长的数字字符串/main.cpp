#include<iostream>
#include<string>
using namespace std;
void Func()
{
	string s;//接受输入的字符串
	string s1;//用来保存最终最长的数字字符串
	cin >> s;
	int max_len = 0;//数字字符串最大长度
	int len = s.size();//输入字符串的长度
	int i = 0;
	while (i < len)
	{
		if (s[i] <= '0' || s[i] >= '9')//若不是数字字符串，i++
			i++;
		int now_len = 0;//记录每组数字字符串的长度
		string tmp;//保存每组数字字符串
		while (s[i] >= '0'&& s[i]<= '9')
		{	
			tmp = tmp + s[i];
			i++;
			now_len++;
		}
		if (now_len > max_len)//如果本组数字字符串长度>记录的最大字符串长度，
			//此时tmp中字符串赋给s1最终输出的数字字符串，长度也赋值给最大字符串长度。
		{
			s1=tmp;
			max_len = now_len;
		}
	}
	cout << s1 << endl;
}
int main()
{
	Func();
	system("pause");
	return 0;
}