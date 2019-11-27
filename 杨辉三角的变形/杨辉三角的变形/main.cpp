#include<iostream>
using namespace std;
#include<vector>
//https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
void Func()
{
	int n = 0;
	while (cin >> n)
	{
		vector<vector<int>> v(n);//建立一个二维数组
		for (int i = 0; i<n; i++)
		{
			v[i].resize(2 * n - 1, 0);//每行初始化为2*n-1列，因为一行最多为2*n-1列
		}
		v[0][(2 * n - 1) / 2] = 1;//第一行的中间初始化为1
		for (int i = 1; i<n; i++)//将每行的边界，初始化为1
		{
			v[i][((2 * n - 1) / 2) - i] = 1;
			v[i][((2 * n - 1) / 2) + i] = 1;
		}
		for (int i = 1; i<n; i++)//建立杨辉三角
		{
			for (int j = 1; j<(2 * n - 2); j++)
			{

				v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
			}
		}
		int k = 0;
		for (k = 0; k < (2 * n - 1); k++)//遍历最后一行内容，如果能被2整除，输出位置坐标+1。
		{
			if (v[n - 1][k] % 2 == 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}
		if (k == 2 * n - 2)//如果遍历结束，都没有则输出-1
			cout << "-1" << endl;
	}
}
int main()
{
	Func();
	system("pause");
	return 0;
}