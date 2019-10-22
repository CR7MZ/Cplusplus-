#include<iostream>
using namespace std;
#define MAXSIZE 100
//��˳��Ľṹʵ��ջ
//�Լ����
//1.��ʼ���жӡ�Ů�ӣ�
//2.���ν������߰����Ա�ֱ����жӺ�Ů�ӡ�
//3.�ж϶����Ƿ�Ϊ�գ�
//4.�����Ե���Ů������Ϣ��
//5.�����ӳ�ʼ��������ͬ����ϳ�����һ����δ����ߵȴ���һ��������
typedef struct
{
	char name[20];
	char gentel;//'f'��Ů 'm'����	
}Person;
typedef struct
{
	Person *base;      //���еĻ���ַ
	int fronter;       //��ͷָ��
	int rear;        //��βָ��
}Sqstack;
void InitialQueue(Sqstack& s)
{
	s.base = new Person[MAXSIZE];
	s.fronter = 0;
	s.rear = 0;
}
void EnQueue(Sqstack& F,Sqstack& M)
{
	Person p;
	cout << "������������Ϣ" << endl;
	cout << "������������";
	cin >> p.name;
	cout << "�������Ա�";
	cin >> p.gentel;
	if (p.gentel == 'f')
	{
		F.base[F.rear] = p;
		F.rear += 1;
	}
	else if (p.gentel == 'm')
	{
		M.base[M.rear] = p;
		M.rear += 1;
	}
}
bool QueueEmpty(Sqstack& s)
{
	if (s.fronter == s.rear)
		return true;
	return false;
}
void DeQueue(Sqstack& s)
{
	if (QueueEmpty(s))
		return;
	/*for (int i = 0; i < s.rear - 1; i++)
	{
		s.base[i] = s.base[i + 1];
	}*/
	s.fronter++;
}
void GetHead(Sqstack& s,Person& P)
{
	P = s.base[s.fronter];
}
void DancersPartner(Sqstack& F, Sqstack& M)
{
	while ((!QueueEmpty(F)) &&(! QueueEmpty(M)))
	{
		cout << "��Ե���Ů����Ϊ��" << endl;
		cout << F.base[F.fronter].name << " " << F.base[F.fronter].gentel << endl;
		DeQueue(F);
		cout << M.base[M.fronter].name << " " << M.base[M.fronter].gentel << endl;
		DeQueue(M);
	}
	if (!QueueEmpty(F))
	{
		cout << "��������ȫ��ƥ�䣬�ȴ���Ů����Ϊ��";
		while (!QueueEmpty(F))
		{
			cout << F.base[F.fronter].name << " " << F.base[F.fronter].gentel << endl;;
			DeQueue(F);
		}
	}
	else if (!QueueEmpty(M))
	{
		cout << "Ů������ȫ��ƥ�䣬ʣ�µ�������Ϊ��";
		while (!QueueEmpty(M))
		{
			cout << M.base[M.fronter].name << " " << M.base[M.fronter].gentel << endl;
			DeQueue(M);
		}
	}
	cout << "��������ƥ�����" << endl;
}
int main()
{
	Sqstack Fdancers, Mdancers;
	InitialQueue(Fdancers);
	InitialQueue(Mdancers);
	int n =0;
	cout << "һ���м��������ߣ�" << endl;
	cin >> n;
	while (n>0)
	{
		EnQueue(Fdancers, Mdancers);
		n--;
	}
	if (QueueEmpty(Fdancers))
		cout << "Ů�������ǿյ�" << endl;
	else if (QueueEmpty(Mdancers))
		cout << "���������ǿյ�" << endl;
	DancersPartner(Fdancers, Mdancers);
	system("pause");
	return 0;
}