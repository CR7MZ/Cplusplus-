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
int Date::count = 0;//��̬������ʼ�����������⡣
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
	cout << sizeof(Date) << endl;//��̬������������ԣ����ı���Ĵ�С��
	cout << &d1.count << " " << &d2.count << endl;//��̬��Ա�����������������ĳ�Ա������ ������ĳ������Ķ���
	system("pause");
	return 0;
}