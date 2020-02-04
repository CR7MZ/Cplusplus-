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
			while (s.empty() || s.top() != popV[outindex])//当栈为空，或者栈顶元素和弹出序列第一个元素不相等时，压栈。
			{
				if (inindex < pushV.size())//在输入序列的范围内压栈。
					s.push(pushV[inindex++]);
				else
					return false;//如果栈不为空且栈顶元素和相对弹出序列元素不相等时，以及输入序列已经压栈完时，则不是弹出序列。
			}
			s.pop();//当栈顶元素和弹出序列的相对元素相等时，删除栈顶，比较栈下一个元素。
			outindex++;//找到弹出序列下一个元素。
		}
		return true;
	}
};
