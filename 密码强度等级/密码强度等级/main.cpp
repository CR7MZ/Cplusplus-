#include<iostream>
using namespace std;
#include<string>
#include<vector>
//��Ŀ ��https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361

//˼·����Ϊһ�������д�дСд��ĸ�����֡��Լ��������š����Զ����ĸ�char���͵����飬
//�ֱ�Ŵ�дСд��ĸ�����֡��Լ��������ţ�������������ֱ�װÿ�����ֵĵ÷֡������ܼ���
int Get(const string& str)
{
	int a1 = 0;//���볤�ȷ���
	vector<char> num, symbol, big, small;
	if (str.size() <= 4)
		a1 = 5;
	else if (str.size() >= 8)
		a1 = 25;
	else
		a1 = 10;
	for (int i = 0; i < str.size(); i++)//�����ַ���
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
			small.push_back(str[i]);
		else if (str[i] >= 'A'&&str[i] <= 'Z')
			big.push_back(str[i]);
		else if (str[i] >= '0'&&str[i] <= '9')
			num.push_back(str[i]);
		else
			symbol.push_back(str[i]);
	}
	int a2 = 0;//��¼��ĸ����
	if (small.size() == 0 && big.size() == 0)
		a2 = 0;
	else if (small.size() != 0 && big.size() != 0)
		a2 = 20;
	else
		a2 = 10;
	int a3 = 0;//��¼���ַ���
	if (num.size() == 0)
		a3 = 0;
	else if (num.size() == 1)
		a3 = 10;
	else
		a3 = 20;
	int a4 = 0;//��¼���ŷ���
	if (symbol.size() == 0)
		a4 = 0;
	else if (symbol.size() == 1)
		a4 = 10;
	else
		a4 = 25;
	int a5 = 0;//��¼��������
	if ((big.size() > 0 || small.size() > 0) && num.size() > 0)
		a5 = 2;
	if ((big.size() > 0 || small.size() > 0) && num.size() > 0 && symbol.size() > 0)
		a5 = 3;
	else if (big.size() > 0 && small.size() > 0 && num.size() > 0 && symbol.size() > 0)
		a5 = 5;

	int sum = a1 + a2 + a3 + a4 + a5;
	return sum;
}
int main()
{
	string s;
	cin >> s; 
	int sum = 0;
	sum=Get(s);
	switch (sum / 10)
	{
	case 9:cout << "VERY_SECURE" << endl; break;
	case 8:cout << "SECURE" << endl; break;
	case 7:cout << "VERY_STRONG" << endl; break;
	case 6:cout << "STRONG" << endl; break;
	case 5:cout << "AVERAGE" << endl; break;
	default:
	{
		if (sum >= 25)cout << "WEAK" << endl;
		else cout << "VERY_WEAK" << endl;
	}
	}
		/*if (sum >= 90)
			cout << "VERY_SECURE" << endl;
		if (sum >= 80 && sum<90)
			cout << "SECURE" << endl;
		if (sum >= 70 && sum < 80)
			cout << "VERY_STRONG" << endl;
		if (sum >= 60 && sum < 70)
			cout << "STRONG" << endl;
		if (sum >= 50 && sum < 60)
			cout << "AVERAGE" << endl;
		if (sum >= 25 && sum < 50)
			cout << "WEAK" << endl;
		if (sum >= 0 && sum < 25)
			cout << "VERY_WEAK" << endl;*/
	system("pause");
	return 0;
}