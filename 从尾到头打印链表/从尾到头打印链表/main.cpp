#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};
//�������е�Ԫ�أ�����ѹ��ջ�У���֮�������γ�ջ�������У���ʵ�ַ����ӡ����
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
	//�Ƚ�����ĵ�һ��Ԫ�ط��������У��ڽ�ʣ�µ�Ԫ������ͷ�嵽����ĵ�һ��Ԫ��ǰ����ɹ��ܡ�
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