#include<iostream>
using namespace std;
#include<vector>

//牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。
//牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 
//牛牛想知道他最少可以把这个数组分为几段排序子序列.

//题目解释：将一个由若干个有序子数组组成的乱序数组，分解开，得出有几个有序数组。

//方法：计算波峰值数，最后加一就得出答案
int main()
{
	int num = 0;
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < num; i++)//将输入的数放入数组中
	{
		cin >> v[i];
	}

	int count = 0;
	for (int i = 1; i < num - 1; i ++ )//遍历数组
	{
		if ((v[i]>v[i + 1] && v[i] > v[i - 1]) || (v[i] < v[i + 1] && v[i] < v[i - 1]))
			//找到找到波峰（最大）或者波谷（最小）的那个数字，count++。
			//原因：当找到峰值时，说明峰值的左右两边可以分为两个有序子序列。
		{
			count++;
			if (i != num - 3)//当i==num-3，若i继续++则会造成越界。
			{
				i++;
			}
		}
	}
	count += 1;//因为count记录的是峰值，一个峰值会分为两个有序子序列，所以count应该+1；
	cout << count;
	system("pause");
	return 0;
}