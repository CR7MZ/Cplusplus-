#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *next;
	TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};
class solution
{
public:
	TreeNode* GetNext(TreeNode* pNode)
	{
		if (pNode->right != nullptr)//����������ʱ������һ���ڵ���������������Ľڵ㡣
		{
			TreeNode* cur = pNode->right;
			while (cur->left!= nullptr)
			{
				cur = cur->left;
			}
			return cur;
		}
		if (pNode->next != nullptr&&pNode->next->left == pNode)//��û��������ʱ���Ҹýڵ��Ǹýڵ㸸�ڵ������������һ���ڵ��Ǹø��ڵ㡣
			return pNode->next;
		if (pNode->next != nullptr)
		{
			TreeNode* tmp = pNode->next;
			while (tmp->next != nullptr&&tmp->next->right == tmp)//��û�����������Ҹýڵ����Ǹø��ڵ������������һֱ�򸸽ڵ�׷�ݣ�ֱ��ĳ���ڵ����丸�ڵ��������������һ���ڵ��Ǹýڵ�ĸ��ڵ㡣
			{
				tmp = tmp->next;
			}
			return tmp->next;
		}
		return NULL;
	}
};