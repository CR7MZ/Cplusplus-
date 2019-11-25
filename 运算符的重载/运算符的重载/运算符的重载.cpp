#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year || _year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		return false;
	}
	bool operator==(const Date& d)//恒等于
	{
		return _year == d._year&&_month == d._month
			&&_day == d._day;
	}
	bool operator!=(const Date& d)//不等于
	{
		return !(*this == d);
	}
	Date& operator++()//前置++
	{
		_day += 1;
		return *this;
	}
	Date operator++(int)//后置++,因为此函数在栈上定义了临时变量，所以不能用引用来做返回值。
	{
		Date tmp(*this);
		_day += 1;
		return tmp;
	}
	Date& operator--()//前置--
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)//后置--。
	{
		Date tmp(*this);
		_day -= 1;
		return tmp;
	}
	bool operator>=(const Date& d)
	{
		if (_year > d._year || _year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day || _year == d._year&&
			_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	bool operator<(const Date& d)
	{
		if (_year < d._year || _year == d._year&&_month < d._month ||
			_year == d._year&&_month == d._month&&_day < d._day)
		{
			return true;
		}
		return false;
	}
	bool operator<=(const Date& d)
	{
		if (_year < d._year || _year == d._year&&_month < d._month ||
			_year == d._year&&_month == d._month&&_day < d._day || _year == d._year
			&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	void PrintfDate()
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
	Date d2(2019, 9, 14);
	Date d3(2019, 9, 18);
	Date d4(2019, 9, 19);
	d2.operator>(d1);
	d2.operator==(d1);
	d2.operator!=(d1);
	d2 = ++d3;
	//d2.PrintfDate();
	Date d7(2019, 9, 19);
	Date d8(2019, 9, 16);
	Date d9(0, 0, 0);
	d9=d7.operator--(0);
	d9.PrintfDate();
	/*cout << d8.operator>=(d7) << endl;
	cout << d8.operator<(d7) << endl;*/
	/*cout << d2.operator!=(d1)<<endl;
	cout << d2.operator>(d1) << endl;
	cout << d2.operator==(d1) << endl;
	cout << (d2==d1)<< endl;*/
	system("pause");
	return 0;
}