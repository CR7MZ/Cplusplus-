#include<iostream>
#include<string>
using namespace std;
//����һ���ַ�����������ַ����������ַ�����
//ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
//ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
void solution(char* str)
{
	string s(str);
	int count[256] = { 0 };
	for (auto e : s)
	{
		count[e]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (count[s[i]] == 1)
			cout << s[i];
		else if (count[s[i]]>1)
		{
			cout << s[i];
			count[s[i]] = 0;
		}
	}
}
int main()
{
	char* str = new char;
	cout << "�������ַ���";
	cin >> str;
	solution(str);
	system("pause");
	return 0;
}