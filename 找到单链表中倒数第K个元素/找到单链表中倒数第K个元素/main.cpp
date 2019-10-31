#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};
ListNode* Create(const vector<int>& v)
{
	ListNode* head = new ListNode;
	head->m_nKey = v[0];
	head->m_pNext = nullptr;
	ListNode* cur = head;
	for (int i = 1; i<v.size(); i++)
	{
		ListNode* tmp = new ListNode;
		tmp->m_nKey = v[i];
		tmp->m_pNext = nullptr;
		cur->m_pNext = tmp;
		cur = tmp;
	}
	return head;
}

//定义两个指针，都指向头结点，先将一个指针向走K次，
//最后两个指针同时往下走当快的那个指针为空时，满的指针则为倒数第K个节点
int Func(ListNode* head, int k)
{
	ListNode* tmpfast = head;
	ListNode* tmpslow = head;
	while (k)
	{
		tmpfast = tmpfast->m_pNext;
		k--;
	}
	while (tmpfast != nullptr)
	{
		tmpfast = tmpfast->m_pNext;
		tmpslow = tmpslow->m_pNext;
	}
	return tmpslow->m_nKey;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
	ListNode* head = Create(v);
	int k;
	cin >> k;
	int result = Func(head, k);
	cout << result << endl;
	system("pause");
	return 0;
}