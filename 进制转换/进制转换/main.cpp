#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//给定一个十进制数M,以及需要转换的进制数N，将十进制M转化为N进制数字。
//如果进制数字大9，则用十六进制标准来，例如：10 为A
void Func()
{
	int M, N;
	cin >> M >> N;
	int flag = 1;//设定M为正数
	if (M < 0)//如果M为负数，flag置为0，将M换为正数
	{
		flag = 0;
		M = -M;
	}
	string s;
	string s1("0123456789ABCDEF");//来记录所有有可能的余数（进制数）
	while (M)
	{
		s += s1[M%N];//将每次除后的M与N取余，放置到字符串s中。
		M /= N;
	}
	if (flag == 0)//如果flag==0说明M为负数，经'-'加到s的后面
	{
		s += '-';
	}
	reverse(s.begin(), s.end());//翻转字符串，得到的才是转换后的N进制数。
	cout << s << endl;
}
int main()
{
	Func();
	system("pause");
	return 0;
}