#include<iostream>
using namespace std;
//模拟二叉搜索树
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
			father->left = cur;
		else
		    father->right = cur;
		
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
		if (nullptr == cur->left)//有右孩子 或者 叶子结点
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
		else if (nullptr == cur->right)//只有左孩子
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
		else//左右孩子都在
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

	node* find(const T&data)
	{
		node* cur = _root;
		while (cur)
		{
			if (data == cur->_data)
				return cur;
			else if (data < cur->_data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}

	void Inorder()
	{
		_Inorder(_root);
	}
private:
	void _Inorder(node* _root)
	{
		if (_root)
		{
			_Inorder(_root->left);
			cout << _root->_data<<" ";
			_Inorder(_root->right);
		}
	}
private:
	node* _root;
};
int main()
{
	BStree<int> b;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };;
	for (auto e : a)
		b.insert(e);
	b.Inorder();
	system("pause");
	return 0;
}