#include<iostream>
using namespace std;
#include<vector>
#include<string>
//https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677

//˼·��
//����һ��string������飬��������ַ����н����Ĳ���������һ��flag���ж�""�������������" ʱflag
//����ȡ�������ٴ�����"ʱ˵������ѽ������������Բ��뵽�����У�

void Func()
{
	vector<string> v;
	string s;
	while (getline(cin, s))
	{
		string tmp = "";//�������������ÿ������
		int flag = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '"')//��������"ʱ��flagȡ�����������ڽ���"�ڷ��ŵĽ���������ٴα�����"˵����������
				flag = ~flag;
			else if (flag == 0 && s[i] == ' ')//����������ո���flagΪ0������1.û�н���"�ڷ��ŵĽ���2.�Ѿ���""�в�������������
			{
				v.push_back(tmp);
				tmp = "";
			}
			else//û�б������ո񣬲��Ҳ�Ϊ"������������tmp��
			{
				tmp += s[i];
			}
		}
		v.push_back(tmp);//�мǣ�ѭ�����������Ĳ�����û�зŽ����顣
		cout << v.size() << endl;
		for (int i = 0; i<v.size(); i++)
			cout << v[i] << endl;
	}
}
int main()
{
	Func();
	return 0;
}