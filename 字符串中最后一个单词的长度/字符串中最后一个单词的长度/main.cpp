#include<iostream>
using namespace std;
#include<string>
#if 0
int main()
{
	string a;
	while (getline(cin, a))//���ֱ��cin>>�������������ո��ַ�(' ')�ͻ�ֱ�ӽ�����
		//���º��������޷����룬����Ҫ��getline(cin,a))��
	{
		size_t pos = a.rfind(' ');//���ַ���������ң�֪����һ���ո񣬷��ؿո��λ�á�
		cout << a.size() - 1 - pos << endl;//������ո�����ַ����ĳ��ȡ�
	}	
	system("pause");
	return 0;
}
#endif
int main()
{
	string s;
	while (getline(cin, s))
	{
		size_t pos = s.rfind(' ');
		pos += 1;//��¼Pos��һλ������
		string ss = s.substr(pos);//��ȡ��posλ��'\0'���ַ�����
		cout << ss.size() << endl;//�����ȡ���ַ����ĳ���
	}
	system("pause");
	return 0;
}