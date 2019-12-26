#include<iostream>
using namespace std;;
namespace My
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)//const���͵ı������������͵ı������Լ����������͵Ķ��� ����������һ��
			//��Ҫ�ڳ�ʼ���б��λ�ý��г�ʼ��
			, _pcount(nullptr)
		{
			if (ptr)//���û�������Դ��Ϊ�գ����һ������
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
				if (_ptr&&--*_pcount == 0)//����ֵ�Ķ��������Դ�Ͽ���
					//�������ֵ�Ķ��������һ��ʹ�øÿ���Դ�Ķ������ͷžɵ���Դ�������
					//���򣬲����ͷž���Դ����Ϊ���ж������ô���Դ��
				{
					delete _ptr;
					delete _pcount;
				}
				_ptr = sp._ptr;//�븳ֵ�Ķ�������Դ�ͼ���
				_pcount = sp._pcount;
				if (_ptr)//�������Դ��Ϊ�գ�����+1��
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