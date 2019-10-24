#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class solution
{
	//用适配器栈：二叉树的中序遍历
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur != nullptr || s.empty())
		{
			while (cur)//cur不为空时，将根节点以及左孩子入栈。
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();//当cur进行到空时，cur回到最后一个左孩子上，也就是栈顶元素
			v.push_back(cur->val);//将cur指向的栈顶元素，入vector中
			s.pop();//删除这个栈顶元素
			cur = cur->right;//当cur有右孩子时，进入前面的循环
		}
		return v;
	}
};