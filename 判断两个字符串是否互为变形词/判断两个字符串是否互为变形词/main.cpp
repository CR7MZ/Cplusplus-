#include<iostream>
#include<string>
using namespace std;
bool Is(string s1, string s2)//�ж��ǲ��Ǳ��δ�
{
	int count1[256] = { 0 };//�ַ��ķ�Χ��0~256�����Զ���һ�����������ַ�����һ���ַ��ڴ��ַ����г��ֵĴ�����
	int count2[256] = { 0 };
	for (auto e : s1)//���ַ���s1���б������ֱ��¼�ַ�����ÿ���ַ����ֵĴ�����
		count1[e]++;
	for (auto w : s2)//���ַ���s2���б������ֱ��¼�ַ�����ÿ���ַ����ֵĴ�����
		count2[w]++;
	for (int i = 0; i <= 256; i++)//���������ַ���
	{
		if (count1[i] == count2[i])
			continue;
		else
			return false;
	}
	return true;//���s1�г��ֵ��ַ������Լ�ÿ���ַ����ֵĴ�����s2����ͬ�����Ǳ��δ�
}
int main()
{
	string s1;
	string s2;
	int n = 0;//�ַ����ĳ��ȡ�
	int m = 0;
	cin >> n >> m;
	s1.resize(n, '0');//���ַ�������Ч�����ı䵽n��
	s2.resize(m, '0');
	cin >> s1;//�����ַ�����
	cin >> s2;
	if (Is(s1, s2))//�ж��ǲ��Ǳ��δ�
	{
		cout << "true" << endl;
	}
	else
		cout << "false";
	system("pause");
	return 0;
}