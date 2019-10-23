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
	//�õݹ���в�����
	vector<int> ret;
	vector<int> preorderTraversal(TreeNode* root)
	{
		preorder_Traversal(root);
		return ret;
	}
	void preorder_Traversal(TreeNode* T)
	{
		if (T)//����������Ľڵ�����ֵ������
		{
			ret.push_back(T->val);//���˽ڵ��ֵ��ӵ�������
			preorder_Traversal(T->left);//����˽ڵ������� �ݹ���ú���
			preorder_Traversal(T->right);//����˽ڵ����Һ��� �ݹ���ú���
		}
	}
};
class solution2
{
	//��ջ���ǰ�����
	vector<int>preorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur || s.size())//��cur��Ϊ�� ���� ջ��Ԫ�صĸ���>0
		{
			while (cur)
			{
				s.push(cur->right);//��cur�ڵ���Һ�����ջ
				v.push_back(cur->val);//��cur�ڵ��ֵ�Ž�������
				cur = cur->left;//cur����cur�����ӣ���������ѭ��
			}
			cur=s.top();//��ʱջ��ֻʣ�����ڵ���Һ��ӣ�curָ���䣬������������ѭ��
			s.pop();//ɾ��λ��ջ�����Һ���
		}
		return v;
	}
};