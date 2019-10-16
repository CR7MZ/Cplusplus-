#include<iostream>
using namespace std;
namespace bite
{
	//list是带头结点双向循环链表。
	template<class T>
	struct ListNode
	{
		ListNode(const T& data=T())
		:_next(nullptr)
		,_prev(nullptr)
		, _data(data)
		{}

		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;
	};
	//list迭代器:将节点类型的指针重新封装
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> self;
	public:
		list_iterator(Node* pcur)
			:_cur(pcur)
		{}
		//按照指针的方式进行应用
		T& operator*()
		{
			return _cur->_data;
		}
		T* operator->()
		{
			return &(_cur->_data);
		}
		//移动
		self& operator++()
		{
			_cur = _cur->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			_cur = _cur->_next;
			return tmp;
		}
		self& operator--()
		{
			_cur = _cur->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_cur = _cur->_prev;
			return tmp;
		}
		bool operator!=(const self& s)
		{
			return _cur != s._cur;
		}
		bool operator==(const self& s)
		{
			return _cur == s._cur;
		}
		Node* _cur;
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T> iterator;
	public:
		list()
		{
			createhead();
		}
		list(int n, const T& data)
		{
			createhead();
			for (int i = 0; i < n; i++)
				push_back(data);
		}
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			createhead();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		list(const list<T>& l)
		{
			createhead();
			Node* cur = l._head->_next;
			while (cur != l._head)
			{
				push_back(cur->_data);
				cur = cur->_next;
			}
		}
		list<T>& operator=(const list<T>& L)
		{
			if (this != &L)
			{
				clear();
				Node* cur = L._head->_next;
				while (cur != L._head)
				{
					push_back(cur->_data);
					cur = cur->_next;
				}
			}
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
		}
	public:
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t n = 0;
			while (cur != _head)
			{
				n++;
				cur = cur->_next;
			}
			return n;
		}
		size_t empty()const
		{
			return _head->_next == _head;
		}
		void resize(size_t newsize, const T& data=T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				for (size_t i = oldsize; i < newsize; i++)
					push_back(data);
			}
			else
			{
				for (size_t i = newsize; i < oldsize; i++)
					pop_back();
			}
		}
		T& front()
		{
			return _head->_next->_data;
		}
		const T& front()const 
		{
			return _head->_next->_data;
		}
		T& back()
		{
			return _head->_prev->_data;
		}
		const T& back()const 
		{
			return _head->_prev->_data;
		}
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}
		iterator insert(iterator pos,const T& data)
		{
			Node* newnode = new Node(data);
			Node* cur = pos._cur;

			newnode->_next = cur;
			newnode->_prev = cur->_prev;
			cur->_prev->_next = newnode;
			cur->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			Node* cur = pos._cur;
			if (cur == _head)
				return end();
			Node* ptr = pos._cur->_next;
			cur->_prev->_next = cur->_next;
			cur->_next->_prev = cur->_prev;
			delete cur;
			return iterator(ptr);
		}
		void clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				_head->_next = cur->_next;
				delete cur;
				cur = _head->_next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
		void swap(list<T>& L)
		{
			swap(_head, L._head);
		}
	private:
		void createhead()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	protected:
		Node* _head;
	};
}
#include<vector>
int main()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	cout << L.back() << endl;
	cout << L.front() << endl;
	cout << L.size() << endl;

	bite::list<int> L2(L);
	/*bite::list<int> L3;
	L3 = L;
	vector<int> v = { 1, 2, 3, 4,5 };
	bite::list<int> L4(v.begin(), v.end());
	for (auto e : L4)
		cout << e << " ";
	cout << endl;*/
	L2.pop_back();
	L2.erase(L2.begin());
	L2.resize(1);
	L2.resize(3);
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		it++;
	}

	system("pause");
	return 0;
}