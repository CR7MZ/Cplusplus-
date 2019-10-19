#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};
class solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;//定义一个二维数组，用来存放树的每层节点里的值。
		queue<TreeNode*> q;//定义一个队列
		if (root == nullptr)//当传进来的参数root为空时，返回空数组。
			return ret;
		q.push(root);//将树的头结点入队列
		while (!q.empty())//当队列不为空时，进入循环
		{
			vector<int> level;//定义一个一维数组，存放每层树的所有节点值
			int size = q.size();//所以用size记录队列中入队列的树节点的个数，表示这一层接几个节点。
			for (int i = 0; i < q.size(); i++)
			{
				TreeNode* cur = q.front();
				level.push_back(cur->val);//将队头的值压入数组
				if (cur->left)//如果此时的头结点有左孩子，压入队列
					q.push(cur->left);
				if (cur->right)//如果此时的头结点有右孩子，压入队列
					q.push(cur->right);
				q.pop();//将队列中头删除。
			}
			ret.push_back(level);//将保存这一层数的节点值，放进二维数组中。进行下一层树的遍历。
		}	
		return ret;
	}
};