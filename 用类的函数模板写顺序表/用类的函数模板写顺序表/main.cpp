#include<iostream>
using namespace std;
#include<assert.h>
template<class T>
class Seqlist
{
public:
	Seqlist(size_t capacity = 10)
	:_arry(new T[capacity])
	, _size(0)
	, _capacity(capacity)
	{}
	~Seqlist()
	{
		if (_arry)
		{
			delete[] _arry;
			_arry = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
	void PushSeqlist(const T& a);
	void PopSeqlist()
	{
		--_size;
	}
	size_t size()const
	{
		return _size;
	}
	size_t capacity()const
	{
		return _capacity;
	}
	bool empty()const
	{
		return 0 == _size;
	}
	const T& operator [](size_t index)const
	{
		assert(index < _size);
		return _arry[index];
	}
	void PrintSeqlist()
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout <<" "<<_arry[i];
		}
	}
private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			T* arry = new T[2 * _capacity];
			for (size_t i = 0; i < _size; i++)
			{
				arry[i] = _arry[i];
			}
			delete[] _arry;
			_arry = arry;
			_capacity = _capacity * 2;
		}
	}
	private:
	T* _arry;
	size_t _capacity;
	size_t _size;
};
template <class T>
void Seqlist<T>::PushSeqlist(const T& a)
{
	CheckCapacity();
	_arry[_size++] = a;
}
void TestSeqlist()
{
	Seqlist<int> s1;
	s1.PushSeqlist(1);
	s1.PushSeqlist(2);
	s1.PushSeqlist(3);
	s1.PushSeqlist(4);
	s1.PushSeqlist(5);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1[0] << endl;
	s1.PrintSeqlist();
}
int main()
{
	TestSeqlist();
	system("pause");
	return 0;
}