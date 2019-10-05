#include<iostream> 
using namespace std;
#include<string>
class solution
{
public:
	string reverseString(string s)
	{
		if (s.empty())
		{
			return s;
		}
		int start = 0;
		int end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			++start;
			--end;
		}
		return s;
	}
};
int main()
{
	string s("hello");
	solution s1;
	s1.reverseString(s);
	cout << s1.reverseString(s) << endl;
	system("pause");

	return 0;
}