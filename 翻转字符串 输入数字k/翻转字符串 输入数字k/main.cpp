#include<iostream>
#include<string>
using namespace std;
/*����һ���ַ�����һ������ k��
����Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰk���ַ����з�ת��
���ʣ������ k ���ַ�����ʣ�������ȫ����ת��
�����С�� 2k �����ڻ���� k ���ַ�����תǰ k ���ַ�������ʣ����ַ�����ԭ����*/
string reverse(string s,int k)
{
	int i = 0;
	if (s.size() <= k)//����ַ�����СС��K����ȫ����ת��
	{
		reverse(s.begin(), s.end());
	}
	else//���ַ�������K
	{
		while (2 * (i + 1)*k <= s.size())//��2kС���ַ�����С��
		{
			reverse((s.begin()+i*k*2), s.begin() +i*k*2+ k);//ǰk���ַ���ת�����ַ�����С����2*kС��2*i*k���˳�ѭ����
			i++;
		}
		if (s.size() - 2 * k*i <= k)//��ʣ�µ��ַ���С�ڵ���k����ʣ���ȫ����ת��
			reverse((s.begin() + 2 * k*i), s.end());
		else//��ʣ���ַ�����С����k��С��2k����תʣ��ǰk���ַ�����
			reverse((s.begin() + 2 * k*i), (s.begin() + 2 * k*i + k));
	}
	return s;
}
int main()
{
	string s;
	getline(cin, s);
	int k = 0;
	cin >> k;
	string s1 = reverse(s, k);
	cout << s1 << endl;
	system("pause");
	return 0;
}