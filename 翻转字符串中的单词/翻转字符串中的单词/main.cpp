#include<iostream>
#include<string>
using namespace std;
string reverseWords(string s)//��������ָ�룬һ���ڵ���ͷһ����������
{
	string::iterator it = s.begin();
	string::iterator it1 = s.begin();
	while (it1 != s.end())
	{
		if (*it1 == ' ')
		{
			reverse(it, it1);
			it = it1 + 1;
		}
		++it1;
	}
	s.push_back(' ');
	reverse(it, it1 + 1);
	return s;
}

int main()
{
	string s("hello world new world");
	cout << reverseWords(s) << endl;
	system("pause");
	return 0;
}
