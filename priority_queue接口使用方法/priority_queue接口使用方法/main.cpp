#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
		{}
	bool operator<(const Date& d)const 
	{
		return this->_day < d._day;
	}
	bool operator>(const Date& d)const 
	{
		return this->_day>d._day;
	}
	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
int main()
{
	vector<int> v{ 0, 5, 2, 3, 8 };
	priority_queue<int> q1(v.begin(),v.end());//区间构造
	cout << q1.top() << endl;

	//优先级队列默认为大堆
	//原因：是大堆或者小堆，取决于优先级队列的模板参数列表的参数
	//template <class T, class Container = vector<T>,class Compare = less<typename Container::value_type> > class priority_queue;
	//第二和第三个参数带有默认值，所以可以不用传。
	//第一个参数：优先级队列里放的元素的类型
	//第二个参数：从概念得知，优先级队列底层是堆，而堆又要放在数组中，所以用vector
	//第三个参数：在放入数组中，要对放入的元素进行比较，用less代表的是<，所以是大堆。若用greater代表的是>，所以就是小堆。
	//用less或greater时，要用<functional>头文件。

	priority_queue<int> q2;//构造一个空的优先级队列
	q2.push(4);
	q2.push(1);
	q2.push(2);
	q2.push(3);
	cout << q2.top() << endl;

	priority_queue<int,vector<int>,greater<int>> q3;//此时用greater所以优先级队列就是小堆
	q3.push(4);
	q3.push(1);
	q3.push(2);
	q3.push(3);
	cout << q3.top() << endl;

	//在优先级队列中放自定义类型的数据，需要重载自定义类型中<和>。
	//若要优先级队列是大端，则重载<。
	//若要优先级队列是小端，则重载>。
	priority_queue<Date> q4;
	q4.push(Date(2019, 10, 18));
	q4.push(Date(2019, 10, 19));
	q4.push(Date(2019, 10, 20));
	cout << q4.top() << endl;

	priority_queue<Date,vector<Date>,greater<Date>> q5;
	q5.push(Date(2019, 10, 18));
	q5.push(Date(2019, 10, 17));
	q5.push(Date(2019, 10, 16));
	cout << q5.top() << endl;
	system("pause");
	return 0;
}