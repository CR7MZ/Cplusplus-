#include<iostream>
#include<vector>
using namespace std;
int** Get2arry(int m,int n)//����һ����̬�Ķ�ά���顣
{
	int** p = new int*[m];
	//����ÿһ�еĿռ�
	for (int i = 0; i < m; i++)
	{
		p[i] = new int[n];//����ÿһ�еĿռ䡣
	}
	return p;
}
int main()
{
	vector<vector<int>> v;
	int m = 5;
	int n = 5;
	int** a = Get2arry(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j= 0; j<i+1; j++)
		{
			a[i][j] = 0;//ȫ����ֵΪ0
			a[i][0] = 1;//��ÿ�еĵ�һ�и�ֵΪ1
			a[i][i] = 1;//��ÿ�е����һ������ֵΪ1
			if (a[i][j] == 0)
			{
				a[i][j] = a[i - 1][j - 1] + a[i-1][j];//������Ǻ���
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << a[i][j];
		}
		printf("\n");
	}
	delete[] a;
	system("pause");
	return 0;
}