#include<iostream>
using namespace std;
#include<string>
#include<vector>
//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 
//1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ����������磺
//"car" < "cats" < "koala" < "doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

bool Func1(const vector<string>& v)//�����ַ������ֵ�������ע������ֵ���������˼�Ǹ����ַ�����С���бȽ�
{
	int flag = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].compare(v[i + 1]) <0)
			flag = 1;
		else
			flag = -1;
	}
	if (flag == 1)
		return true;
	else if (flag == -1)
		return false;
}
bool Func2(const vector<string>& v)//�����ַ����ĳ�������
{
	int flag = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].size() < v[i + 1].size())
			flag = 1;
		else
			flag = -1;
	}
	if (flag == 1)
		return true;
	else if (flag == -1)
		return false;
}
int main()
{
	int n = 0;
	cin >> n;
	if (n>100)
		return -1;
	vector<string> v;
	while (n)
	{
		string s;
		cin >> s;
		for (int i = 0; i<s.size(); i++)
		{
			if (!(s[i] >= 'a'&&s[i] <= 'z'))
				return -1;
		}
		if (s.size() >= 100)
			return -1;
		v.push_back(s);
		n--;
	}
	if (Func1(v) && Func2(v))
		cout << "both" << endl;
	else if (Func1(v))
		cout << "lexicographically" << endl;
	else if (Func2(v))
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	system("pause");
	return 0;
}