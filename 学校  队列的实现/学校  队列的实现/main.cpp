#include<iostream>
using namespace std;
#define MAXSIZE 100
//用顺序的结构实现栈
//以及完成
//1.初始化男队、女队；
//2.依次将跳舞者按照性别分别入男队和女队。
//3.判断队列是否为空；
//4.输出配对的男女舞者信息；
//5.若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。
typedef struct
{
	char name[20];
	char gentel;//'f'是女 'm'是男	
}Person;
typedef struct
{
	Person *base;      //队列的基地址
	int fronter;       //队头指针
	int rear;        //队尾指针
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
	cout << "请输入舞者信息" << endl;
	cout << "请输入姓名：";
	cin >> p.name;
	cout << "请输入性别：";
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
		cout << "配对的男女舞者为：" << endl;
		cout << F.base[F.fronter].name << " " << F.base[F.fronter].gentel << endl;
		DeQueue(F);
		cout << M.base[M.fronter].name << " " << M.base[M.fronter].gentel << endl;
		DeQueue(M);
	}
	if (!QueueEmpty(F))
	{
		cout << "男舞者已全部匹配，等待的女舞者为：";
		while (!QueueEmpty(F))
		{
			cout << F.base[F.fronter].name << " " << F.base[F.fronter].gentel << endl;;
			DeQueue(F);
		}
	}
	else if (!QueueEmpty(M))
	{
		cout << "女舞者已全部匹配，剩下的男舞者为：";
		while (!QueueEmpty(M))
		{
			cout << M.base[M.fronter].name << " " << M.base[M.fronter].gentel << endl;
			DeQueue(M);
		}
	}
	cout << "所有舞者匹配完毕" << endl;
}
int main()
{
	Sqstack Fdancers, Mdancers;
	InitialQueue(Fdancers);
	InitialQueue(Mdancers);
	int n =0;
	cout << "一共有几个跳舞者：" << endl;
	cin >> n;
	while (n>0)
	{
		EnQueue(Fdancers, Mdancers);
		n--;
	}
	if (QueueEmpty(Fdancers))
		cout << "女生队列是空的" << endl;
	else if (QueueEmpty(Mdancers))
		cout << "男生队列是空的" << endl;
	DancersPartner(Fdancers, Mdancers);
	system("pause");
	return 0;
}