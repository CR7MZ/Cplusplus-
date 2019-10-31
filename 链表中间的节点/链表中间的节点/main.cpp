#include<iostream>
#include<vector>
using namespace std;
//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
struct ListNode
{
	int val;
	ListNode* next;
};
ListNode* Create(const vector<int>& v)
{
	ListNode* head = new ListNode;
	head->val = v[0];
	head->next = nullptr;
	ListNode* cur = head;
	for (int i = 1; i<v.size(); i++)
	{
		ListNode* tmp = new ListNode;
		tmp->val = v[i];
		tmp->next = nullptr;
		cur->next = tmp;
		cur = tmp;
	}
	return head;
}
class solution
{
public:
	int MiddleNode(ListNode* head)
	{
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && (fast->next != nullptr))
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow->val;
	}
};
int main()
{
	int arr[] = { 1, 2, 3, 4, 5,6 };
	vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
	ListNode* head = Create(v);
	solution s;
	cout<<s.MiddleNode(head)<<endl;
	system("pause");
	return 0;
}