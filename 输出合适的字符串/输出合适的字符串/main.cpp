#include<iostream>
using namespace std;
#include<string>
//����һ���ַ�������������һ����֮ǰ�ı��������ַ������ظ����ַ������֮ǰ���ַ�����
//���ӣ�abcab-->abc��abcccba--->abc

//����������һ�����ַ���result�������ַ���s�����ַ���s�е�ÿ���ַ����뵽result�У�ÿ�μӵ�result��ʱ��
//����ʱҪ���뵽result�е��ַ������е�result��ÿ��Ԫ�رȽϣ�������ظ�����ֱ������𰸡�

bool adjust(char x,const string& result)//�ж�result��û����Ҫ������ַ� ��ͬ���ַ�
{
	for (auto e : result)
	{
		if (e == x)
		{
			return false;
		}
	}
	return true;
}
void Func()
{
	string s;
	cin >> s;
	string result;//���ַ���
	result.resize(s.size());
	for (int i = 0; i < s.size(); i++)//����������ַ���
	{
		if (adjust(s[i], result))//���result��û�д�ʱҪ������ַ�ʱ�������
		{
			result[i] = s[i];
		}
		else//���result���д�ʱҪ������ַ���������ѭ��������𰸡�
		{
			break;
		}
	}
	cout << result << endl;
}
int main()
{
	Func();
	system("pause");
	return 0;
}