#include<iostream>
using namespace std;
#include<vector>
//要求时间复杂度 O(M + N)，空间复杂度 O(1)。其中 M 为行数，N 为 列数。
//该二维数组中的一个数，小于它的数一定在其左边，大于它的数一定在其下边。因此，从右上角开始查找，
//就可以根据 n 和当前元素的大小关系来缩小查找区间，当前元素的查找区间为左下角的所有元素。

bool  IsInside(int arr[4][5],int n,int M,int N)
{
	int row = 0;
	int col = N - 1;
	if (M == 0 || N == 0 || arr == nullptr)
		return false;

	while (row < M&&col >= 0)
	{
		if (arr[row][col] == n)
			return true;
		else if (arr[row][col] > n)
			col--;
		else
			row++;
	}
	return false;
}
int main()
{
	int arr[4][5] = {1,4,7,11,15,
	                 2,5,8,12,19,
	                 3,6,9,16,22,
	                10,13,14,17,24};	
	int n = 0;
	cout << "请输入必要查找的数字：";
	cin >> n;
	if (IsInside(arr, n,4,5))
	{
		cout << "找到了" << endl;
	}
	else
		cout << "没找到" << endl;
	system("pause");
	return 0;
}