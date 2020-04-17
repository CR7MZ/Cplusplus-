#include<iostream>
#include<string>
using namespace std;
//https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())//将短字符串放到a中
			swap(a, b);
		string maxstr;//存储最长公共子串
		for (int i = 0; i < a.size(); i++)//从a中遍历，依次截取字符串，放到b中找
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (b.find(temp) == std::string::npos)//找不到
					break;
				else if (maxstr.size() < temp.size())
					maxstr = temp;
			}
		}
		cout << maxstr << endl;
	}
	return 0;
}