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
	//��������ջ�����������������
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur != nullptr || s.empty())
		{
			while (cur)//cur��Ϊ��ʱ�������ڵ��Լ�������ջ��
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();//��cur���е���ʱ��cur�ص����һ�������ϣ�Ҳ����ջ��Ԫ��
			v.push_back(cur->val);//��curָ���ջ��Ԫ�أ���vector��
			s.pop();//ɾ�����ջ��Ԫ��
			cur = cur->right;//��cur���Һ���ʱ������ǰ���ѭ��
		}
		return v;
	}
};