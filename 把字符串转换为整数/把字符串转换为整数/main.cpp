#include<iostream>
#include<string>


using namespace std;
class Solution {
public:
	int StrToInt(string str) {
		int res = 0, n = str.size(), symbol = 1;
		if (!n)
			return 0;
		int start;
		for (start = 0; start < n; start++)
		{
			if (str[start] == '-' || str[start] == '+' || ('0' <= str[start] && str[start] <= '9'))
				break;
		}

		if (str[start] == '-')
			symbol = -1;

		for (int i = (str[start] == '-' || str[start] == '+') ? start + 1 : start; i < n; ++i){
			if (!('0' <= str[i] && str[i] <= '9'))
				return 0;
			//res=res*10+str[i]-'0';
			res = (res << 1) + (res << 3) + (str[i] & 0xf);//这里利用位运算提高计算效率 
		}
		return res * symbol; 
	}
};
int main()
{
	Solution s;
	string s1("123");

	int su = s.StrToInt(s1);
	cout << su << endl;
	system("pause");
	return 0;
}