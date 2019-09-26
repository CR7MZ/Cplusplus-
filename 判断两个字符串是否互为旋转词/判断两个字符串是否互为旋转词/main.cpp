#include<iostream>
#include<string>
#include<string.h>
using namespace std;
//方法1
bool Is(string s1, string s2,int n)//判断是否为旋转词
{
	int i = n - 1;//i为循环的次数。
	while (i > 0)
	{
		s1 += s1[0];//将s1字符串的第一个字符，放到s1字符串最后。
		s1.erase(s1.begin());//删除s1的第一个字符。
		if (s2.compare(s1) == 0)//判断s1和s2是否相等。若相等返回true，不相等i--。
		{
			return true;
		}
		else
			--i;
	}	
	return false;//若循环结束依然不相等，则返回false。
}
int main()
{
	string s1;
	string s2;
	int n = 0, m = 0;
	cin >> n >> m;//m ,n为两字符串的长度。
	s1.resize(n, '0');
	s2.resize(m, '0');
	//getline(cin, s1);
	//getline(cin, s2);
	cin >> s1;//输入字符串
	cin >> s2;
	if (Is(s1, s2,n))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" <<endl;
	}
	system("pause");
	return 0;
}

//方法2
//bool Is(string s1, string s2)//判断是否为旋转词
//{
//	s1 += s1;
//	if (strstr(s1.c_str(), s2.c_str()))
//	{
//		return true;
//	}
//	else
//		return false;
//}
//int main()
//{
//	string s1;
//	string s2;
//	int n = 0, m = 0;
//	cin >> n >> m;//m ,n为两字符串的长度。
//	s1.resize(n, '0');
//	s2.resize(m, '0');
//	cin >> s1;//输入字符串
//	cin >> s2;
//	if (Is(s1, s2))
//	{
//		cout << "YES" << endl;
//	}
//	else
//	{
//		cout << "NO" << endl;
//	}
//	system("pause");
//	return 0;
//}