#include<iostream>
#include<string>
using namespace std;
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
int main()
{
	string s;
	getline(cin, s);//����һ�����ַ�����'.'Ҳ����
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