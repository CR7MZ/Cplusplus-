#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//��һ���ַ����еĿո��滻�� "%20"��

void replaceSpace(char *str, int length) {//����1
	string s(str);
	int count = 0;
	for (auto e : s)//ͳ���м����ո�
	{
		if (e == ' ')
			count++;
	}
	string result;
	result.resize(s.size() + count * 2);//����һ���յ��ַ�������Ϊÿ���ո��滻Ϊ%20�������ַ�����СҪ��count*2
	int j = 0;
	for (int i = 0; i<s.size(), j<result.size(); i++, j++)//�����ַ�����ǰ������
	{
		if (s[i] == ' ')//�������ո�result�ַ������%20����ʱresult�ַ������±�+2����������iͬʱ����
		{
			result[j] = '%';
			result[j + 1] = '2';
			result[j + 2] = '0';
			j += 2;
		}
		else{
			result[j] = s[i];
		}
	}
	auto ret = result.c_str();//��Ϊ���Ĳ�����char*���ԣ�Ҫ��string���͵��ַ���תΪC���͡�
	strcpy(str, ret);
}

void changestring(string& s)//����2
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
	//string s("ad dasd asd");
	//changestring(s);
	char s[] = "hello world ca";
	replaceSpace(s, sizeof(s));
	cout <<s << endl;
	system("pause");
	return 0;
}