#include<iostream>
using namespace std;
#include<vector>
//Ҫ��ʱ�临�Ӷ� O(M + N)���ռ临�Ӷ� O(1)������ M Ϊ������N Ϊ ������
//�ö�ά�����е�һ������С��������һ��������ߣ�����������һ�������±ߡ���ˣ������Ͻǿ�ʼ���ң�
//�Ϳ��Ը��� n �͵�ǰԪ�صĴ�С��ϵ����С�������䣬��ǰԪ�صĲ�������Ϊ���½ǵ�����Ԫ�ء�

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
	cout << "�������Ҫ���ҵ����֣�";
	cin >> n;
	if (IsInside(arr, n,4,5))
	{
		cout << "�ҵ���" << endl;
	}
	else
		cout << "û�ҵ�" << endl;
	system("pause");
	return 0;
}