#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};
//将链表中的元素，依次压入栈中，在之后再依次出栈到数组中，则实现反向打印链表。
class solution1
{
	vector<int> BackToFrontPrintList(ListNode* head)
	{
		stack<int> s;
		vector<int> v;
		ListNode* tmp = head;
		while (tmp)
		{
			s.push(tmp->val);
			tmp = tmp->next;
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
		return  v;
	}
};

class solution2
{
	//先将链表的第一个元素放入数组中，在将剩下的元素依次头插到数组的第一个元素前，完成功能。
	vector<int> BackToFrontPrintList(ListNode* head)
	{
		vector<int> v;
		ListNode* tmp = head;
		if (tmp!=nullptr)
		{
			v.push_back(tmp->val);
			while (tmp->next != nullptr)
			{
				v.insert(v.begin(), tmp->next->val);
				tmp = tmp->next;
			}
		}
		return v;
	}
};