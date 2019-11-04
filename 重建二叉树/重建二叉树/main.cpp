#include<iostream>
using namespace std;
#include<vector>
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，
//则重建二叉树并返回
struct TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr),right(nullptr){}
};
class solution
{
public:
      TreeNode* reconstructBinaryTree(vector<int> pre, vector<int> vin)//pre前序，vin中序
	{
		int len = vin.size();
		if (len == 0)
			return NULL;
		vector<int> right_pre, right_vin, left_pre, left_vin;
		TreeNode* head = new TreeNode(pre[0]);//创建根节点，根节点是前序遍历的头元素。
		int vinlen = 0;
		for (int i = 0; i < len; i++)//在中序遍历中找到，头结点。头结点左边就是二叉树的左边，头结点右边就是二叉树的右边
		{
			if (pre[0] == vin[i])
			{
				vinlen = i;
				break;
			}
		}
		for (int i = 0; i < vinlen; i++)//对树的左边进行归并
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (int i = vinlen + 1; i < len; i++)//对树的右边进行归并
		{
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		//取出前序和中序遍历根节点的左边和右边子树
		//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
		head->left = reconstructBinaryTree(left_pre, left_vin);
		head->right = reconstructBinaryTree(right_pre, right_vin);
		return head;
	}
};
int main()
{
	int arr[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> pre(arr,arr+sizeof(arr)/sizeof(arr[0]));
	int arr2[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> vin(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
	solution s;
	TreeNode* head;
	head=s.reconstructBinaryTree(pre, vin);
	system("pause");
	return 0;
}