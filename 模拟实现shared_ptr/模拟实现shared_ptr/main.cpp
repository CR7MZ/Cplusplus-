#include<iostream>
using namespace std;;
namespace My
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)//const类型的变量、引用类型的变量、以及包含类类型的对象 这三个变量一般
			//需要在初始化列表的位置进行初始化
			, _pcount(nullptr)
		{
			if (ptr)//若用户给的资源不为空，则记一个数。
				_pcount = new int(1);
		}
		~shared_ptr()
		{
			if (_ptr && (--*_pcount == 0))
			{
				delete _ptr;
				delete _pcount;
			}
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			if (_ptr)
				++*_pcount;
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				if (_ptr&&--*_pcount == 0)//被赋值的对象与旧资源断开，
					//如果被赋值的对象是最后一个使用该块资源的对象，则释放旧的资源与计数。
					//否则，不用释放旧资源，因为还有对象在用此资源。
				{
					delete _ptr;
					delete _pcount;
				}
				_ptr = sp._ptr;//与赋值的对象共享资源和计数
				_pcount = sp._pcount;
				if (_ptr)//如果新资源不为空，计数+1；
					++*_pcount;
			}
			return *this;
		}

		int show__pcount()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;
	};
}
int main()
{
	My::shared_ptr<int> sp1(new int);
	cout << sp1.show__pcount() << endl;
	My::shared_ptr<int> sp2(sp1);
	cout << sp1.show__pcount() << endl;
	cout << sp2.show__pcount() << endl;
	cout << endl;
	My::shared_ptr<int> sp3(new int);
	cout << sp3.show__pcount() << endl;
	sp2 = sp3;
	cout << sp1.show__pcount() << endl;
	cout << sp3.show__pcount() << endl;
	system("pause");
	return 0;
}