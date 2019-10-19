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
	priority_queue<int> q1(v.begin(),v.end());//���乹��
	cout << q1.top() << endl;

	//���ȼ�����Ĭ��Ϊ���
	//ԭ���Ǵ�ѻ���С�ѣ�ȡ�������ȼ����е�ģ������б�Ĳ���
	//template <class T, class Container = vector<T>,class Compare = less<typename Container::value_type> > class priority_queue;
	//�ڶ��͵�������������Ĭ��ֵ�����Կ��Բ��ô���
	//��һ�����������ȼ�������ŵ�Ԫ�ص�����
	//�ڶ����������Ӹ����֪�����ȼ����еײ��Ƕѣ�������Ҫ���������У�������vector
	//�������������ڷ��������У�Ҫ�Է����Ԫ�ؽ��бȽϣ���less�������<�������Ǵ�ѡ�����greater�������>�����Ծ���С�ѡ�
	//��less��greaterʱ��Ҫ��<functional>ͷ�ļ���

	priority_queue<int> q2;//����һ���յ����ȼ�����
	q2.push(4);
	q2.push(1);
	q2.push(2);
	q2.push(3);
	cout << q2.top() << endl;

	priority_queue<int,vector<int>,greater<int>> q3;//��ʱ��greater�������ȼ����о���С��
	q3.push(4);
	q3.push(1);
	q3.push(2);
	q3.push(3);
	cout << q3.top() << endl;

	//�����ȼ������з��Զ������͵����ݣ���Ҫ�����Զ���������<��>��
	//��Ҫ���ȼ������Ǵ�ˣ�������<��
	//��Ҫ���ȼ�������С�ˣ�������>��
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