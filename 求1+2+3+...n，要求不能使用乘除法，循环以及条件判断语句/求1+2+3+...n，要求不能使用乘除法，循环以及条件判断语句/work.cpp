#include<iostream>//利用静态变量性质,静态成员变量所有对象共享,以及静态成员函数只能访问静态成员变量
using namespace std;
class Solution
{
public:
	class CSum
	{
	public:
		CSum()
		{
			count++;
			sum += count;
		}
		static void Reset()
		{
			count = 0;
			sum = 0;
		}
		static int GetSum()
		{
			return sum;
		}
	private:
		static int count;
		static int sum;
	};
	int sum_solution()
	{
		CSum::Reset();
		CSum total[2];
		return CSum::GetSum();
	}
};
int Solution::CSum::count = 0;
int Solution::CSum::sum = 0;
int main()
{
	Solution S;
	cout<<S.sum_solution()<<endl;
	system("pause");
	return 0;
}
