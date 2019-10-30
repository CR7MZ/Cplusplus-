#include<iostream>
#include<vector>
using namespace std;
//有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
//例如，原数组为[1, 2, 3, 4, 5, 6]，向左移位5个位置即变成了[6, 1, 2, 3, 4, 5], 
//现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。


//给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。
//保证数组中元素互异。
class solution
{
public:
	int FindElement(vector<int> v, int n, int x)//用二分查找
	{
		int start = 0;
		int end = n - 1;
		int mid;
		//由于数组是移位后的，所以之间元素的左右两边一定有一边是有序的。
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (v[mid] == x)
				return mid;
			if (x > v[mid])
			{
				//如果v[start] > v[mid]说明右边是有序的，x>v[end]说明x在mid左边
				if (x > v[end] && v[start] > v[mid])
					end = mid - 1;
				else//如果v[start] < v[mid]说明左边是有序的，x<v[end]说明x在mid右边
					start = mid + 1;
			}
			else//当x < v[mid]
			{
				//如果v[start] < v[mid]说明左边是有序的，x<v[start]说明x在mid右边
				if (x < v[start] && v[start] < v[mid])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
	}
};
int main()
{
	vector<int> v{ 6, 1, 2, 3, 4, 5 };
	solution s;
	cout<<s.FindElement(v, v.size(), v.front());
	system("pause");
	return 0;
}