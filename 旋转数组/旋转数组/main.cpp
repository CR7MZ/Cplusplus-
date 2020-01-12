#include<vector>
#include<iostream>
class solution
{
public:
	void rotate(std::vector<int>& nums, int k) {
		int tmp = 0;
		for (int i = 0; i<k; i++)
		{
			tmp = nums.back();
			nums.pop_back();
			nums.insert(nums.begin(), tmp);
		}
	}
};
int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	solution s;
	s.rotate(v, k);
	for (auto e : v)
	{
		std::cout << e<<" ";
	}
	system("pause");
	return 0;
}