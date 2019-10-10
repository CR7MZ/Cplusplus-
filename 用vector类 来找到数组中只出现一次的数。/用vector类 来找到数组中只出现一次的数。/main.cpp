#include<iostream>
#include<vector>
using namespace std;
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//前提：不用开辟其他空间。
class solution
{
public:
	int singleNumber(vector<int>& v)
	{
		int result = 0;//运用异或运算符，让数组的元素都异或。
		for (auto e : v)
			result ^= e;
		return result;
	}
};
int main()
{
	vector<int> v{ 2, 1, 2 };
	solution s;
	int result = 0;
	result=s.singleNumber(v);
	cout << "只出现一次的数是："<<result << endl;
	system("pause");
	return 0;
}