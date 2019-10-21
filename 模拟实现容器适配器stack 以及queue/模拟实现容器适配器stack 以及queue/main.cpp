#include<iostream>
using namespace std;
#include<deque>
namespace bite
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack()
		{}

		 void push(const T& data)
		{
			_Con.push_back(data);
		}
		void pop()
		{
			_Con.pop_back();
		}
		size_t size()
		{
			return _Con.size();
		}
		T& top()
		{
			return _Con.back();
		}
		const T& top()const 
		{
			return _Con.back();
		}
		bool empty()const 
		{
			return _Con.empty();
		}
		void clear()
		{
			_Con.clear();
		}
	private:
		Container _Con;
	};

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
		{}
		void push(const T& data)
		{
			con.push_back(data);
		}
		void pop()
		{
			con.pop_front();
		}
		size_t size()
		{
			return con.size();
		}
		T& front()
		{
			return con.front();
		}
		const T& front()const 
		{
			return con.front();
		}
		T& back()
		{
			return con.back();
		}
		const T& back()const 
		{
			return con.back();
		}
		bool empty()
		{
			return con.empty();
		}
		private:
		Container con;
	};
}
#include<vector>
void teststack()
{
	bite::stack<int> s;
    s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	if (s.empty())
		cout <<"yes" << endl;
	else
		cout << "no" << endl;
	cout << s.size() << endl;
	cout << s.top() << endl;
	s.top() = 4;
	cout << s.size() << endl;
	cout << s.top() << endl;
	cout << "以下为s2" << endl;
	bite::stack<int, vector<int>> s2;//stack的底层用vector也是可以的。
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	cout << s2.size() << endl;
	cout << s2.top() << endl;
	s2.pop();
	cout << s2.size() << endl;
	cout << s2.top() << endl;
	if (s2.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	s2.clear();
	cout << s2.size() << endl;
}
#include<list>
void testqueue()
{
	bite::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << "以下为q2" << endl;
	if (q.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	bite::queue<int, list<int>>  q2;//queue的底层也可以用list实现
	q2.push(5);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;
	q2.pop();
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;
	if (q2.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
int main()
{
	//teststack();
	testqueue();
	system("pause");
	return 0;
}