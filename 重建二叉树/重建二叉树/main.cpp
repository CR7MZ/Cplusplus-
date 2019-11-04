#include<iostream>
using namespace std;
#include<vector>
//����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{ 1, 2, 4, 7, 3, 5, 6, 8 }�������������{ 4, 7, 2, 1, 5, 3, 8, 6 }��
//���ؽ�������������
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
      TreeNode* reconstructBinaryTree(vector<int> pre, vector<int> vin)//preǰ��vin����
	{
		int len = vin.size();
		if (len == 0)
			return NULL;
		vector<int> right_pre, right_vin, left_pre, left_vin;
		TreeNode* head = new TreeNode(pre[0]);//�������ڵ㣬���ڵ���ǰ�������ͷԪ�ء�
		int vinlen = 0;
		for (int i = 0; i < len; i++)//������������ҵ���ͷ��㡣ͷ�����߾��Ƕ���������ߣ�ͷ����ұ߾��Ƕ��������ұ�
		{
			if (pre[0] == vin[i])
			{
				vinlen = i;
				break;
			}
		}
		for (int i = 0; i < vinlen; i++)//��������߽��й鲢
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}
		for (int i = vinlen + 1; i < len; i++)//�������ұ߽��й鲢
		{
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}
		//ȡ��ǰ�������������ڵ����ߺ��ұ�����
		//�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
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