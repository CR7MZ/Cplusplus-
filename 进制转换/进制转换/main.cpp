#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//����һ��ʮ������M,�Լ���Ҫת���Ľ�����N����ʮ����Mת��ΪN�������֡�
//����������ִ�9������ʮ�����Ʊ�׼�������磺10 ΪA
void Func()
{
	int M, N;
	cin >> M >> N;
	int flag = 1;//�趨MΪ����
	if (M < 0)//���MΪ������flag��Ϊ0����M��Ϊ����
	{
		flag = 0;
		M = -M;
	}
	string s;
	string s1("0123456789ABCDEF");//����¼�����п��ܵ���������������
	while (M)
	{
		s += s1[M%N];//��ÿ�γ����M��Nȡ�࣬���õ��ַ���s�С�
		M /= N;
	}
	if (flag == 0)//���flag==0˵��MΪ��������'-'�ӵ�s�ĺ���
	{
		s += '-';
	}
	reverse(s.begin(), s.end());//��ת�ַ������õ��Ĳ���ת�����N��������
	cout << s << endl;
}
int main()
{
	Func();
	system("pause");
	return 0;
}