#include<iostream>
using namespace std;
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
//����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1��
//���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
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