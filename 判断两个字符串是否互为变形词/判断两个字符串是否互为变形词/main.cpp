#include<iostream>
#include<string>
using namespace std;
bool Is(string s1, string s2)//判断是不是变形词
{
	int count1[256] = { 0 };//字符的范围在0~256，所以定义一个数组来计字符串中一个字符在此字符串中出现的次数。
	int count2[256] = { 0 };
	for (auto e : s1)//对字符串s1进行遍历，分别记录字符串中每个字符出现的次数。
		count1[e]++;
	for (auto w : s2)//对字符串s2进行遍历，分别记录字符串中每个字符出现的次数。
		count2[w]++;
	for (int i = 0; i <= 256; i++)//遍历所有字符。
	{
		if (count1[i] == count2[i])
			continue;
		else
			return false;
	}
	return true;//如果s1中出现的字符种类以及每个字符出现的次数与s2中相同，则是变形词
}
int main()
{
	string s1;
	string s2;
	int n = 0;//字符串的长度。
	int m = 0;
	cin >> n >> m;
	s1.resize(n, '0');//将字符串的有效个数改变到n。
	s2.resize(m, '0');
	cin >> s1;//输入字符串。
	cin >> s2;
	if (Is(s1, s2))//判断是不是变形词
	{
		cout << "true" << endl;
	}
	else
		cout << "false";
	system("pause");
	return 0;
}