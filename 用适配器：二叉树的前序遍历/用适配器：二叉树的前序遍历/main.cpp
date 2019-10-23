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
