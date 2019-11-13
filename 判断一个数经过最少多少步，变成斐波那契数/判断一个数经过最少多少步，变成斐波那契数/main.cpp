#include<iostream>
using namespace std;
//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
//给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，
//现在给你一个数N求最少需要多少步可以变为Fibonacci数。
int Fib(int n)
{
	if (n <= 1)
		return n;
	return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	int N;
	cin >> N;
	int i = 0;
	while (1)
	{
		if (Fib(i) == N)
		{
			cout << "0" << endl;
			break;
		}
		if (Fib(i) < N&&Fib(i+1) > N)
		{
			if (N - Fib(i) < Fib(i + 1) - N)
			{
				cout << N - Fib(i) << endl;
				break;
			}
			else if (N - Fib(i) < Fib(i + 1) - N)
			{
				cout << Fib(i + 1) - N << endl;
				break;
			}
			else
			{
				cout << Fib(i + 1) - N << endl;
				break;
			}
		}
		i++;
	}
	system("pause");
	return 0;
}