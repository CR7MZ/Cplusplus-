#include<iostream>
#include<vector>
using namespace std;
//题目：https://www.nowcoder.com/questionTerminal/769d45d455fe40b385ba32f97e7bcded

bool Isleap(int year)//判断是否为闰年
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
int main()
{
	int year;
	int mon;
	int day;
	while (cin >> year >> mon >> day)
	{
		vector<vector<int>> v(13);//定义一个二维数组，里面放的是每个月对应的天数
		int flag = 0;
		for (int i = 0; i<v.size(); i++)
		{
			if (i == 2)//如果是2月，为28天
			{
				v[i].resize(28, 0);
				flag = 1;
				continue;
			}
			if (i == 8)//7、8月份都是31天
			{
				flag = 1;
			}
			if (flag == 0)//flag为0，表示本月30天
			{
				v[i].resize(30, 0);
				flag = 1;//正常情况下，下个月应该是大月31天，将flag换为1
				continue;
			}
			if (flag == 1)//flag为1时，本月31天
			{
				v[i].resize(31, 0);
				flag = 0;//正常情况下，下个月应该是小月30天，将flag换为0
				continue;
			}
		}
		if (year <= 0 || mon <= 0 || mon > 12 || day <= 0 || day > v[mon].size())//判断输入是否合法
			return -1;
		int mi = 0;//本年已经过了多少天
		for (int i = 1; i < mon; i++)
		{
			mi += v[i].size();
		}
		if (Isleap(year))//如果是闰年 ，总天数+1
			mi = mi + day + 1;
		else
			mi = mi + day;
		cout << mi << endl;;
	}
	return 0;
}