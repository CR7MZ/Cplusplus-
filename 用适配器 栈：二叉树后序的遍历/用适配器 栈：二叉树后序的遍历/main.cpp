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
	//用栈 进行二叉树的后序遍历
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;//pre是用来判断有节点是否被访问过
		while (cur || !s.empty())
		{ 
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			if (!(cur->right) || pre == cur->right)//如果右节点为空，或者pre指向cur的右节点，表示这个右节点已经遍历过了
			{
				s.pop();
				v.push_back(cur->val);
				pre = cur;
				cur = nullptr;
			}
			else//如果上述两个条件都不符合，则cur指到右节点pre指向空
			{
				cur = cur->right;
				pre = nullptr;
			}
		}
		return v;
	}
};