#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
	int _data;
	TreeNode* left;
	TreeNode* right;
};

//�ò��������������ÿ�õ�һ���ڵ��ж�flag�Ƿ�Ϊ1��Ϊ1˵��֮ǰ���ֹ�ֻ���������Ľ�㣬����ʱ��tmp��һ���������ǼҾͲ�����ȫ��������
//��flag��Ϊ0����tmp������������������������У���ֻ����������false��ֻ��������falg��Ϊ1�������������롣
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