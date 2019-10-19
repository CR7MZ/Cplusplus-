#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
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
		vector<vector<int>> ret;//����һ����ά���飬�����������ÿ��ڵ����ֵ��
		queue<TreeNode*> q;//����һ������
		if (root == nullptr)//���������Ĳ���rootΪ��ʱ�����ؿ����顣
			return ret;
		q.push(root);//������ͷ��������
		while (!q.empty())//�����в�Ϊ��ʱ������ѭ��
		{
			vector<int> level;//����һ��һά���飬���ÿ���������нڵ�ֵ
			int size = q.size();//������size��¼����������е����ڵ�ĸ�������ʾ��һ��Ӽ����ڵ㡣
			for (int i = 0; i < q.size(); i++)
			{
				TreeNode* cur = q.front();
				level.push_back(cur->val);//����ͷ��ֵѹ������
				if (cur->left)//�����ʱ��ͷ��������ӣ�ѹ�����
					q.push(cur->left);
				if (cur->right)//�����ʱ��ͷ������Һ��ӣ�ѹ�����
					q.push(cur->right);
				q.pop();//��������ͷɾ����
			}
			ret.push_back(level);//��������һ�����Ľڵ�ֵ���Ž���ά�����С�������һ�����ı�����
		}	
		return ret;
	}
};