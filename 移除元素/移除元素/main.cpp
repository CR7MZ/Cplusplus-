//https://leetcode-cn.com/problems/remove-element/submissions/
#include<vector>
#include<iostream>
using namespace std;
class solution
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		auto it = nums.begin();
		while (it != nums.end())
		{
			if (*it == val)
			{
				it = nums.erase(it);
				continue;
			}
			it++;
		}
		return nums.size();
	}
};