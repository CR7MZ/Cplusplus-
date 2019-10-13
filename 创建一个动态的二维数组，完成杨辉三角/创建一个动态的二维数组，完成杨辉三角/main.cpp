#include<iostream>
#include<vector>
using namespace std;
int** Get2arry(int m,int n)//开辟一个动态的二维数组。
{
	int** p = new int*[m];
	//分配每一行的空间
	for (int i = 0; i < m; i++)
	{
		p[i] = new int[n];//分配每一列的空间。
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
			a[i][j] = 0;//全部赋值为0
			a[i][0] = 1;//将每行的第一列赋值为1
			a[i][i] = 1;//将每行的最后一个数赋值为1
			if (a[i][j] == 0)
			{
				a[i][j] = a[i - 1][j - 1] + a[i-1][j];//杨辉三角核心
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