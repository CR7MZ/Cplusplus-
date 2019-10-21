#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class solution
{
public:
	void FindKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int> q(nums.begin(), nums.end());//讲述vector放在q中，因为是优先级队列且是大堆，所以
		//是从大到小的。
		for (int i = 0; i < k - 1; i++)//只需删除树的头，删除到i<k-1即可。
			q.pop();
		cout << "第K个最大的数为：" << q.top() << endl;//此时的树头为第K个最大的数
	}
};
int main()
{
	vector<int> v{ 3, 2, 1, 5, 6, 4 };
	solution s;
	s.FindKthLargest(v, 2);
	system("pause");
	return 0;
}