#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class solution
{
public:
	bool IsPopOrder(vector<int>pushV, vector<int>popV)
	{
		stack<int> s;
		int outindex = 0;
		int inindex = 0;
		while (outindex<popV.size())
		{
			while (s.empty() || s.top() != popV[outindex])//��ջΪ�գ�����ջ��Ԫ�غ͵������е�һ��Ԫ�ز����ʱ��ѹջ��
			{
				if (inindex < pushV.size())//���������еķ�Χ��ѹջ��
					s.push(pushV[inindex++]);
				else
					return false;//���ջ��Ϊ����ջ��Ԫ�غ���Ե�������Ԫ�ز����ʱ���Լ����������Ѿ�ѹջ��ʱ�����ǵ������С�
			}
			s.pop();//��ջ��Ԫ�غ͵������е����Ԫ�����ʱ��ɾ��ջ�����Ƚ�ջ��һ��Ԫ�ء�
			outindex++;//�ҵ�����������һ��Ԫ�ء�
		}
		return true;
	}
};
