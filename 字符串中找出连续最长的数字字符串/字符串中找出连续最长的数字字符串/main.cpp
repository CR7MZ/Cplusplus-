#include<iostream>
#include<string>
using namespace std;
void Func()
{
	string s;//����������ַ���
	string s1;//��������������������ַ���
	cin >> s;
	int max_len = 0;//�����ַ�����󳤶�
	int len = s.size();//�����ַ����ĳ���
	int i = 0;
	while (i < len)
	{
		if (s[i] <= '0' || s[i] >= '9')//�����������ַ�����i++
			i++;
		int now_len = 0;//��¼ÿ�������ַ����ĳ���
		string tmp;//����ÿ�������ַ���
		while (s[i] >= '0'&& s[i]<= '9')
		{	
			tmp = tmp + s[i];
			i++;
			now_len++;
		}
		if (now_len > max_len)//������������ַ�������>��¼������ַ������ȣ�
			//��ʱtmp���ַ�������s1��������������ַ���������Ҳ��ֵ������ַ������ȡ�
		{
			s1=tmp;
			max_len = now_len;
		}
	}
	cout << s1 << endl;
}
int main()
{
	Func();
	system("pause");
	return 0;
}