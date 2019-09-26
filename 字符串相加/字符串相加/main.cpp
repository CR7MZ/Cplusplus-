#include<iostream>
using namespace std;
#include<string>
//如果两个数太大，可以用字符串类型的数字来计算
class solution
{
public:
	string addStrings(string num1, string num2)
	{
		int Lsize = num1.size();
		int Rsize = num2.size();
		if (Lsize < Rsize)
		{
			num1.swap(num2);
			swap(Lsize, Rsize);
		}
		//用string类的构造函数，并且把它的长度变为最长的字符串加1，且都初始化为0字符，用来保存结果。
		string strRet(Lsize + 1, '0');
		char offset = 0;//进位
		for (int L = num1.size() - 1, R = num2.size()-1; L >= 0; L--, R--)
		{
			char cRet = num1[L] - '0';//从个位开始两个数相加。字符'9'减去字符'0'变为数字9。
			if (R >= 0)
			{
				cRet += num2[R]-'0';
			}
			cRet += offset;//加上之前相加的进位。
			offset = 0;//进位清零
			if (cRet >= 10)
			{
				offset = 1;//如果这一位相加后大于等于10进位
				cRet -= 10;
			}
			strRet[L + 1] += cRet;//计算后的这一位给到之前定义的字符串，进行保存。
		}
		if (offset == 1)
		{
			strRet[0] += 1;//计算完最高位，有可能再进位，若offset为1则进一位
		}
		else
			strRet.erase(strRet.begin());//如果最高位加完，没有进位的话，删去字符串首地址。
		return strRet;
	}
};
int main()
{
	string num1("111");
	string num2("900");
	solution s;
	//s.addStrings(num1, num2);
	string a(s.addStrings(num1, num2));
	cout << a<< endl;
	system("pause");
	return 0;
}