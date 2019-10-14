#include<iostream>
#include<string>
using namespace std;
//将一个字符串中的空格替换成 "%20"。
void changestring(string& s)
{
	int count = 0;
	for (auto e : s)//先遍历字符串，统计一共有多少个空格。
	{
		if (e == ' ')
			count++;
	}
	auto p1 = s.end()-1;//定义一个迭代器，指向字符串最后一个字符（'\0'之前）
	s.resize(s.size() + count * 2);//因为%20位3个字符，所以有count个空格就将字符串的长度加2*count。
	auto p2 = s.end()-1;//再定义一个迭代器指向加长之后的字符串的最后一个字符（'\0'之前）
	while (p1!=s.begin())//两个迭代器从后向前遍历。
	{
		if (*p1!=' '&&*p1!='\0')//当*p1为字符时，将*p1的值赋给*p2
		{
			*p2 = *p1;
		}
		else if (*p1 == ' ')//当*p1等于空格时，p2开始一次赋值'0' '2' '%'
		{
			*p2-- = '0';
			//p2--;
			*p2--  = '2';
			//p2--;
			*p2 = '%';
		}
		p1--;
		p2--;
	}
}
int main()
{
	string s("ad dasd asd");
	changestring(s);
	cout <<s << endl;
	system("pause");
	return 0;
}