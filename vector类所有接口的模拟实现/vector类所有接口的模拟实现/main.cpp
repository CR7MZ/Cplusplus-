#include<iostream>
using namespace std;
#include<assert.h>
namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
		{}
		vector(int n, const T& data)
		{
			_start = new T[n];
			for (int i = 0; i < n; i++)
			{
				_start[i] = data;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}
		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			int n = 0;
			auto it = first;
			while (it != last)
			{
				++it;
				++n;
			}
			_start = new T[n];
			for (int i = 0; i < n; i++)
			{
				_start[i] = *first++;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}
		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.size();
			_endofstorage = _finish;
		}
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				_start = new T[v.size()];
				for (size_t i = 0; i < v.size(); i++)
				{
					_start[i] = v[i];
				}
				_finish = _start + v.size();
				_endofstorage = _finish;
			}
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				_start = _finish = _endofstorage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
		bool empty()const
		{
			if (_start == _finish)
				return true;
			return false;
		}
		void resize(size_t newsize,const T& data=T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				if (newsize >= capacity())
					reserve(newsize);
				for (; oldsize < newsize; oldsize++)
				{
					_start[oldsize] = data;
				}
			}
			_finish = _start + newsize;
		}
		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			if (newcapacity>oldcapacity)
			{
				T* temp = new T[newcapacity];
				size_t n = size();
				if (_start)
				{
					for (size_t i = 0; i < n; i++)
					{
						temp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = temp;
				_finish = _start + n;
				_endofstorage = _start + newcapacity;
			}
		}
		T& operator[](size_t index)const
		{
			assert(index < size());
			return _start[index];
		}
		T& front()
		{
			return _start[0];
		}
		const T& front()const
		{
			return _start[0];
		}
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back()const
		{
			return *(_finish - 1);
		}
		void push_back(const T& data)
		{
			if (_finish == _endofstorage)
				reserve(capacity() * 2 + 3);
			*_finish++ = data;
		}
		void popback()
		{
			--_finish;
		}
		iterator insert(iterator pos,const T& data)
		{
			if (_finish == _endofstorage)
				reserve(capacity()*2);
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1); 
				it--;
			}
			*pos = data;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			if (pos == end())
				return pos;
			auto it = pos + 1;
			while (it < end())
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}
			private:
		T*_start;
		T*_finish;
		T*_endofstorage;
	};
}
void TestVector()
{
	bite::vector<int> v1;


	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	cout << v3.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	//bite::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : v3)
		e *= 2;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}void TestVector2()
{
	bite::vector<int> v;
	v.push_back(1);  // 3
	v.push_back(2);
	v.push_back(3);
	v.push_back(4); // 9
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.popback();
	cout << v.back() << endl;
	cout << v.size() << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;
}
void TestVector3()
{
	//vector<int> vv;
	bite::vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void TestVector4()
{
	bite::vector<int> v1(5, 10);
	bite::vector<int> v2(v1);
	for (auto e : v2)
		cout << e << " ";
	cout << endl;
	bite::vector<int> v3;
	v3 = v1;
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	//TestVector();
	//TestVector2();
	//TestVector3();
	TestVector4();
	system("pause");
	return 0;
}