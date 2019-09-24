#include<iostream>
using namespace std;
class solution
{
public:
	int firstUniqchar(string s)
	{
		//字符串范围：0~256
		//1.统计每一个字符出现的次数
		int count[256] = { 0 };
		for (auto e : s)
		{
			count[e]++;
		}
		//2.找到第一个出现一次的字符的下标，并返回。
		for (int i = 0; i < s.size(); ++i)
		{
			if (1 == count[s[i]])
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{
	string s("helloehllsad");
	solution s1;
	int ret=s1.firstUniqchar(s);
	cout << s[ret] << endl;
	system("pause");
	return 0;
}