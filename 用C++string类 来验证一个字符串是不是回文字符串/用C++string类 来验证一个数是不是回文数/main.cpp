#include<iostream>
#include<string>
using namespace std;
bool Isright(char ch)//�ж�������ַ����Ƿ�Ϸ�
{
	return (ch >= '0'&&ch <= '9')
		|| (ch >= 'a'&&ch <= 'z')
		|| (ch >= 'A'&&ch <= 'Z');
}
bool IssPalindrome(string s)//�ж��ǲ��ǻ����ַ���
{
	for (auto& ch : s)//��Сд��Ϊ��д
	{
		if (ch >= 'a'&&ch <= 'z')
			ch -= 32;
	}
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		while (begin < end&&!Isright(s[begin]))//�ж��ַ�������û�з��ַ������н���ѭ����������λ�á�
			++begin;
		while (begin < end&&!Isright(s[end]))//�ж��ַ�������û�з��ַ������н���ѭ����������λ�á�
			--end;
		if (s[begin] != s[end])
		{
			return false;
		}
		else
		{
			++begin;
			--end;
		}
	}
	return true;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		if (IssPalindrome(s))
		{
			cout << "�ǻ����ַ���" << endl;
			break;
		}
		else
		{
			cout << "���ǻ����ַ���" << endl;
			break;
		}

	}
	system("pause");
	return 0;
}
