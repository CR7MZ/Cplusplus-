#include<iostream>
#include<stack>
using namespace std;
//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) --将元素 x 推入栈中。
//pop() --删除栈顶的元素。
//top() --获取栈顶元素。
//getMin() --检索栈中的最小元素。
class Minstack
{
public:
	void pop()
	{
		if (Min.top() == elem.top())
			Min.pop();
		elem.pop();
	}
	void push(int x)
	{
		elem.push(x);//将正常数据入正常栈。
		if (Min.empty() || x < Min.top())//如果最小栈中为空，则入最小栈，或者当谁的值X比最小栈的栈顶元素小，入栈。
			Min.push(x);
	}
	int top()
	{
		return elem.top();//数据栈的栈顶
	}
	int GetMin()
	{
		return Min.top();//提取最小栈栈顶元素，为最小值
	}
private:
	stack<int> elem;//放数据的栈
	stack<int> Min;//放最小值的栈
};
void test()
{
	Minstack M;
	M.push(2);
	M.push(5);
	M.push(1);
	M.push(3);
	cout <<"elem栈顶元素为："<< M.top() << endl;
	cout <<"最小栈："<< M.GetMin() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}