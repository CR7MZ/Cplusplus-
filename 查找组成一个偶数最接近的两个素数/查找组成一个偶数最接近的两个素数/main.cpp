#include<iostream>
using namespace std;
//https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
bool check(int x)//�ж��ǲ�������
{
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;
}
void Func()
{
	int n = 0;
	while (cin >> n)
	{
		if (n <= 2)
			return ;
		for (int i = n / 2; i > 2; i--)//���м俪ʼ�ң���һ������i���ڶ�������n-i,���Բ������ж���������Ƿ�Ϊn
			//ֱ���ж��Ƿ�Ϊ�������������
		{
			if (check(i) && check(n - i))
			{
				cout << i << endl;
				cout << n - i << endl;
				break;
			}
		}
	}
}
int main()
{
	Func();
	system("pause");
	return 0;
}