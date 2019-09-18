#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		count++;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++count;
	}
	~Date()
	{
		--count;
	}
private:
	int _year;
	int _month;
	int _day;
public:
	static int count;
};
int Date::count = 0;//静态变量初始化必须在类外。
void test()
{
	Date d3(2019, 9, 19);
	Date d4(d3);
	Date d5(2019, 9, 9);
	cout << Date::count << endl;
}
int main()
{
	Date d1(2019, 9, 18);
	test();
	cout << Date::count << endl;
	Date d2(d1);
	cout << Date::count << endl;
	cout << sizeof(Date) << endl;//静态变量是类的属性，不改变类的大小。
	cout << &d1.count << " " << &d2.count << endl;//静态成员变量是所有类对象共享的成员变量。 不属于某个具体的对象
	system("pause");
	return 0;
}