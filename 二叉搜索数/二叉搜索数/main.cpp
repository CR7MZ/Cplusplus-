#include<iostream>
using namespace std;

//ģ�����������
template<class T>
struct BStreenode
{
	BStreenode(const T& data = T())
		:left(nullptr)
		,right(nullptr)
		, _data(data)
	{}
	BStreenode<T>* left;
	BStreenode<T>* right;
	T _data;
};

template<class T>
class BStree
{
	typedef BStreenode<T> node;
public:
	BStree()
		:_root(nullptr)
	{}
	bool insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new node(data);
			return true;
		}

		node* cur = _root;
		node* father = nullptr;
		while (cur)
		{
			father = cur;
			if (data < cur->_data)
				cur = cur->left;
			else if (data>cur->_data)
				cur = cur->right;
			else
				return false;
		}

		cur = new node(data);
		if (data < father->_data)
			cur = father->left;
		else if (data>father->_data)
			cur = cur->right;
		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _root)
			return false;
		node* cur = _root;
		node* father = nullptr;
		while (cur)
		{
			if (data == cur->_data)
				break;
			else if (data<cur->_data)
			{
				father = cur;
				cur = cur->left;
			}
			else
			{
				father = cur;
				cur = cur->right;
			}
		}
		if (nullptr == cur)
			return false;

		node* denode = cur;
		if (nullptr == cur->left)//���Һ��� ���� Ҷ�ӽ��
		{
			if (cur == _root)
				_root = cur->right;
			else
			{
				if (cur == father->left)
					father->left = cur->right;
				else
					father->right = cur->right;
			}
		}
		else if (nullptr == cur->right)//ֻ������
		{
			if (nullptr == father)
				_root = cur->left;
			else
			{
				if (cur == father->left)
					father->left = cur->left;
				else
					father->right = cur->left;
			}
		}
		else//���Һ��Ӷ���
		{
			node* del = cur->right;
			father = cur;
			while (del->left)
			{
				father = del;
				del = del->left;
			}
			cur->_data = del->_data;

			if (del == father->left)
				father->left = del->right;
			else
				father->right = del->right;

			denode = del;
		}
		delete denode;
		return true;
	}
private:
	node* _root;
};