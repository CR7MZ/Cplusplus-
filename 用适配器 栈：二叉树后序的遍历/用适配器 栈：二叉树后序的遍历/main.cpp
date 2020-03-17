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
	//��ջ ���ж������ĺ������
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;//pre�������ж��нڵ��Ƿ񱻷��ʹ�
		while (cur || !s.empty())
		{ 
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			if (!(cur->right) || pre == cur->right)//����ҽڵ�Ϊ�գ�����preָ��cur���ҽڵ㣬��ʾ����ҽڵ��Ѿ���������
			{
				s.pop();
				v.push_back(cur->val);
				pre = cur;
				cur = nullptr;
			}
			else//����������������������ϣ���curָ���ҽڵ�preָ���
			{
				cur = cur->right;
				pre = nullptr;
			}
		}
		return v;
	}
};