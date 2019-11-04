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
		if (pNode->right != nullptr)//当有右子树时，其下一个节点是右子树中最左的节点。
		{
			TreeNode* cur = pNode->right;
			while (cur->left!= nullptr)
			{
				cur = cur->left;
			}
			return cur;
		}
		if (pNode->next != nullptr&&pNode->next->left == pNode)//当没有右子树时，且该节点是该节点父节点的左子树，下一个节点是该父节点。
			return pNode->next;
		if (pNode->next != nullptr)
		{
			TreeNode* tmp = pNode->next;
			while (tmp->next != nullptr&&tmp->next->right == tmp)//当没有右子树，且该节点在是该父节点的右子树，则一直向父节点追溯，直到某个节点是其父节点的左子树，则下一个节点是该节点的父节点。
			{
				tmp = tmp->next;
			}
			return tmp->next;
		}
		return NULL;
	}
};