#include<iostream>
using namespace std;
typedef char ElemType;
#define MAXSIZE 100
typedef struct
{
	ElemType *base;      //栈底
	ElemType *top; //栈顶
	int sizestack;
}Sqstack;
void InitStack(Sqstack &s)
{
	s.base = new ElemType[MAXSIZE];
	s.top = s.base;
	s.sizestack = MAXSIZE;
}
void check(Sqstack& s)
{
	if ((s.top - s.base) >= s.sizestack)
	{
		s.sizestack *= 2;
	}
}
int IsEmpty(Sqstack s)
{
	if (s.base == s.top)
	{
		cout << "栈空" << endl;
		return 1;
	}
	else
		return 0;
}
void push(Sqstack &s,ElemType x)//入栈
{

	*s.top = x;
	s.top++;
}
int pop(Sqstack &s,ElemType &x)//出栈
{
	if (IsEmpty(s))
		return 0;
	x=*(--s.top);
	return 1;
}
int getpop(Sqstack &s)//得到栈顶的元素，栈顶指针不动。
{
	if (s.base == s.top)
		return 0;
	return *(s.top - 1);
}
int main()
{
	Sqstack s;
	InitStack(s);//初始化栈
	int i = 0;
	ElemType q;
	cout << "请输入：";
	for (i = 0; i < 5; i++)
	{
		cin >> q;
		push(s, q);//入栈
	}
	IsEmpty(s);
	q = getpop(s);//输出栈顶元素
	cout <<"栈顶元素为："<< q<<endl;
	for (i = 0; i < 5; i++)
	{
		pop(s, q);//出栈
		cout << q << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}