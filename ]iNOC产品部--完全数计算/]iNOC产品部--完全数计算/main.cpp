#include<iostream>
using namespace std;
//https://www.nowcoder.com/questionTerminal/7299c12e6abb437c87ad3e712383ff84
int check(int n)//判断是否为完全数
{
	int result = 0;
	for (int i = 1; i<n; i++)
	{
		if (n%i == 0)
			result += i;
	}
	if (result == n)
		return 1;
	return 0;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (check(i))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}