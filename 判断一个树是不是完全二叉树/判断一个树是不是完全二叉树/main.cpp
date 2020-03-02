#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
	int _data;
	TreeNode* left;
	TreeNode* right;
};

//用层序遍历二叉树，每拿到一个节点判断flag是否为1，为1说明之前出现过只有左子树的结点，若此时的tmp有一个子树，那家就不是完全二叉树。
//若flag不为0，若tmp有左右左子树，插入队里其中，若只有右子树，false。只有左子树falg置为1，将左子树插入。
bool BinaryTreeComplate(TreeNode* root)
{
	queue<TreeNode*> q;
	q.push(root);
	int flag = 0;
	while (!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop();
		if (flag)
		{
			if (tmp->left || tmp->right)
				return 0;
			else
				continue;
		}
		if (tmp->left&&tmp->right)
		{
			q.push(tmp->left);
			q.push(tmp->right);
		}
		else if (!tmp->left&&tmp->right)
			return false;
		else
		{
			flag = 1;
			if (tmp->left)
				q.push(tmp->left);
		}
	}
	return true;
}