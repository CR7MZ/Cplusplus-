#include<iostream>
#include<string>
#include<string.h>
using namespace std;
//����1
bool Is(string s1, string s2,int n)//�ж��Ƿ�Ϊ��ת��
{
	int i = n - 1;//iΪѭ���Ĵ�����
	while (i > 0)
	{
		s1 += s1[0];//��s1�ַ����ĵ�һ���ַ����ŵ�s1�ַ������
		s1.erase(s1.begin());//ɾ��s1�ĵ�һ���ַ���
		if (s2.compare(s1) == 0)//�ж�s1��s2�Ƿ���ȡ�����ȷ���true�������i--��
		{
			return true;
		}
		else
			--i;
	}	
	return false;//��ѭ��������Ȼ����ȣ��򷵻�false��
}
int main()
{
	string s1;
	string s2;
	int n = 0, m = 0;
	cin >> n >> m;//m ,nΪ���ַ����ĳ��ȡ�
	s1.resize(n, '0');
	s2.resize(m, '0');
	//getline(cin, s1);
	//getline(cin, s2);
	cin >> s1;//�����ַ���
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

//����2
//bool Is(string s1, string s2)//�ж��Ƿ�Ϊ��ת��
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
//	cin >> n >> m;//m ,nΪ���ַ����ĳ��ȡ�
//	s1.resize(n, '0');
//	s2.resize(m, '0');
//	cin >> s1;//�����ַ���
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