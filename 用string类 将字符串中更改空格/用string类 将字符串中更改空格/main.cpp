#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//将一个字符串中的空格替换成 "%20"。

void replaceSpace(char *str, int length) {//方法1
	string s(str);
	int count = 0;
	for (auto e : s)//统计有几个空格
	{
		if (e == ' ')
			count++;
	}
	string result;
	result.resize(s.size() + count * 2);//建立一个空的字符串，因为每个空格替换为%20，所以字符串大小要加count*2
	int j = 0;
	for (int i = 0; i<s.size(), j<result.size(); i++, j++)//两个字符串从前向后遍历
	{
		if (s[i] == ' ')//当遇到空格，result字符串后加%20，此时result字符串的下标+2，紧接着与i同时继续
		{
			result[j] = '%';
			result[j + 1] = '2';
			result[j + 2] = '0';
			j += 2;
		}
		else{
			result[j] = s[i];
		}
	}
	auto ret = result.c_str();//因为传的参数是char*所以，要将string类型的字符串转为C类型。
	strcpy(str, ret);
}

void changestring(string& s)//方法2
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
	//string s("ad dasd asd");
	//changestring(s);
	char s[] = "hello world ca";
	replaceSpace(s, sizeof(s));
	cout <<s << endl;
	system("pause");
	return 0;
}