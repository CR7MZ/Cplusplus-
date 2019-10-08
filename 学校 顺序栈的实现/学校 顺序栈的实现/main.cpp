#include<iostream>
using namespace std;
typedef char ElemType;
#define MAXSIZE 100
typedef struct
{
	ElemType *base;      //ջ��
	ElemType *top; //ջ��
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
		cout << "ջ��" << endl;
		return 1;
	}
	else
		return 0;
}
void push(Sqstack &s,ElemType x)//��ջ
{

	*s.top = x;
	s.top++;
}
int pop(Sqstack &s,ElemType &x)//��ջ
{
	if (IsEmpty(s))
		return 0;
	x=*(--s.top);
	return 1;
}
int getpop(Sqstack &s)//�õ�ջ����Ԫ�أ�ջ��ָ�벻����
{
	if (s.base == s.top)
		return 0;
	return *(s.top - 1);
}
int main()
{
	Sqstack s;
	InitStack(s);//��ʼ��ջ
	int i = 0;
	ElemType q;
	cout << "�����룺";
	for (i = 0; i < 5; i++)
	{
		cin >> q;
		push(s, q);//��ջ
	}
	IsEmpty(s);
	q = getpop(s);//���ջ��Ԫ��
	cout <<"ջ��Ԫ��Ϊ��"<< q<<endl;
	for (i = 0; i < 5; i++)
	{
		pop(s, q);//��ջ
		cout << q << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}