#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year, int month, int day)//构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)//构造拷贝
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)//赋值运算符的重载。
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	void printdate()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 9, 15);
	Date d2(2019, 9, 12);

	d1.operator=(d2);
	Date d3(d1);
	d3.printdate();
	system("pause");
	return 0;
}