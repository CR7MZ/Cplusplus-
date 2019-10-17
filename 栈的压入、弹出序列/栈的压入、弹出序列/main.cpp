#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，
//序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）
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
void test()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };//压入序列
	vector<int> v2{ 4, 3, 5, 1, 2 };//弹出序列
	solution s;
	if (s.IsPopOrder(v1, v2))
		cout << "是弹出序列" << endl;
	else
		cout << "不是弹出序列" << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}