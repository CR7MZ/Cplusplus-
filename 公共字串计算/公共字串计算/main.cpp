#include<iostream>
using namespace std;
#include<string>
//https://www.nowcoder.com/questionTerminal/98dc82c094e043ccb7e0570e5342dd1b


void Func()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size()>s2.size())//s1����Ϊ��С���ַ���
			swap(s1, s2);
		string tmp;//������Ĺ����ַ���
		int max = 0;//����������ַ����ĳ���
		for (int i = 0; i<s1.size(); i++)//��s1��ͷ���ַ�������s2���ң��ҵ���s1�ղ��ҵ��ַ���������죬
		{
			for (int j = i; j<s1.size(); j++)
			{
				tmp = s1.substr(i, j - i + 1);
				if (s2.find(tmp) == std::string::npos)
					break;
				if (tmp.size()>max)
					max = tmp.size();//����s2���ҵ����ַ�����С���������֮ǰ��ֵ����ֵ��max
			}
		}
		cout << max << endl;
	}
}
int main()
{
	Func();
	return 0;
}