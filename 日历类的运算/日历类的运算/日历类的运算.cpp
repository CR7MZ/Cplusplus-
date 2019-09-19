#include<iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
public:
	Date(int year, int month, int day)//�ж����������Ƿ�Ƿ���
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!(year > 0 && month > 0 && month < 13 &&day>0&& day <= GetMonthDay(year, month)))
		{
			_year = 1999;
			_month = 1;
			_day = 1;
		}
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days)//�Ӻź������أ���������
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}
		Date tmp(*this);
		tmp._day += days;
		int MonthDays = 0;
		while (tmp._day>(MonthDays = tmp.GetMonthDay(tmp._year, tmp._month)))
		{
			tmp._day -= MonthDays;
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;
	}
	Date operator-(int days)//���ź������أ���������
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date tmp(*this);
		tmp._day -= days;
		int MonthDay = 0;
		while (tmp._day <= 0)
		{
			tmp._month--;
			if (tmp._month <= 0)
			{
				tmp._year -= 1;
				tmp._month = 12;
			}
			tmp._day += tmp.GetMonthDay(tmp._year, tmp._month);
		}
		return tmp;
	}
	bool operator>(const Date& d)const  //���ش���
	{
		if (_year > d._year || _year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		return false;
	}
	bool operator==(const Date& d)const//���غ����
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
	bool operator!=(const Date& d)const//���ز�����
	{
		return !(*this == d);
	}
	Date operator++(int)
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	int operator-(const Date& d)//���ؼ��ţ������������������
	{
		Date min(*this);
		Date max(d);
		if (*this > d)
		{
			swap(min, max);
		}
		int count = 0;
		while (min != max)
		{
			count++;
			min++;
		}
		return count;
	}

private:
	int GetMonthDay(int year, int month)//ÿ���µ�����
	{
		int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			arr[2] += 1;
		}
		return arr[month];
	}

	bool IsLeapYear(int year)//�ж��Ƿ�Ϊ����
	{
		if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2019, 9, 19);
	Date d2(2019, 6, 11);
	cout << d-d2 << endl;
	system("pause");
	return 0;
}