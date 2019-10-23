#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
//};
typedef struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
}TreeNode;
class solution
{
	//用递归进行操作。
	vector<int> ret;
	vector<int> preorderTraversal(TreeNode* root)
	{
		preorder_Traversal(root);
		return ret;
	}
	void preorder_Traversal(TreeNode* T)
	{
		if (T)//如果传进来的节点有数值，进入
		{
			ret.push_back(T->val);//将此节点的值添加到数组中
			preorder_Traversal(T->left);//如果此节点有左孩子 递归调用函数
			preorder_Traversal(T->right);//如果此节点有右孩子 递归调用函数
		}
	}
};
class solution2
{
	//用栈完成前序遍历
	vector<int>preorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur || s.size())//当cur不为空 或者 栈里元素的个数>0
		{
			while (cur)
			{
				s.push(cur->right);//将cur节点的右孩子入栈
				v.push_back(cur->val);//将cur节点的值放进数组中
				cur = cur->left;//cur移向cur的左孩子，继续进行循环
			}
			cur=s.top();//此时栈里只剩各个节点的右孩子，cur指向其，继续进行上面循环
			s.pop();//删除位于栈顶的右孩子
		}
		return v;
	}
};