#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};
//typedef struct 
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
//}TreeNode;
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
