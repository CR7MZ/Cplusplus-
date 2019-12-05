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

//��������ָ�룬��ָ��ͷ��㣬�Ƚ�һ��ָ������K�Σ�
//�������ָ��ͬʱ�����ߵ�����Ǹ�ָ��Ϊ��ʱ������ָ����Ϊ������K���ڵ�
int Func(ListNode* head, int k)
{
	if (head == nullptr)
		return -1;
	ListNode* tmpfast = head;
	ListNode* tmpslow = head;
	if (k <= 0)
		return -1;
	while (k - 1)//��ָ���ƶ�ʱ
	{
		if (tmpfast != nullptr)
		{
			tmpfast = tmpfast->m_pNext;
			k--;
		}
		if (tmpfast == nullptr)//��ָ�벻���Ƶ������ⲿ�����Ա���ӶԿ�ָ����пղ���
			return -1;
	}
	while (tmpfast->m_pNext != nullptr)
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