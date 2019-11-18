#include<iostream>
using namespace std;
//https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
bool check(int x)//判断是不是素数
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
		for (int i = n / 2; i > 2; i--)//从中间开始找，第一个数是i，第二个数是n-i,所以并不用判断两个相加是否为n
			//直接判断是否为素数，即可输出
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