#include<iostream>
#include<string>
using namespace std;
//��һ���ַ����еĿո��滻�� "%20"��
void changestring(string& s)
{
	int count = 0;
	for (auto e : s)//�ȱ����ַ�����ͳ��һ���ж��ٸ��ո�
	{
		if (e == ' ')
			count++;
	}
	auto p1 = s.end()-1;//����һ����������ָ���ַ������һ���ַ���'\0'֮ǰ��
	s.resize(s.size() + count * 2);//��Ϊ%20λ3���ַ���������count���ո�ͽ��ַ����ĳ��ȼ�2*count��
	auto p2 = s.end()-1;//�ٶ���һ��������ָ��ӳ�֮����ַ��������һ���ַ���'\0'֮ǰ��
	while (p1!=s.begin())//�����������Ӻ���ǰ������
	{
		if (*p1!=' '&&*p1!='\0')//��*p1Ϊ�ַ�ʱ����*p1��ֵ����*p2
		{
			*p2 = *p1;
		}
		else if (*p1 == ' ')//��*p1���ڿո�ʱ��p2��ʼһ�θ�ֵ'0' '2' '%'
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
	string s("ad dasd asd");
	changestring(s);
	cout <<s << endl;
	system("pause");
	return 0;
}