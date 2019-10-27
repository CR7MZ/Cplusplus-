#include<iostream>
using namespace std;
typedef struct
{
	int ISBN;
	char BookName[30];
	int Price;
	int numbers;
}TheBook;
typedef struct Node
{
	TheBook data;
	struct Node* next;
}Node;
void Init(Node*& l)
{	
	l = new Node; 
	l->data.numbers = 0;
	l->next = nullptr;
}
bool CheckIsRepeat(Node* l, Node* cur)
{
	Node* crr = l->next;
	for (; crr; crr=crr->next)
	{
		if (crr->data.ISBN == cur->data.ISBN)
		{
			crr->data.numbers++;
			return true;
		}
	}
	return false;
}
void  CreateBooks(Node*& l)
{
	Init(l);
	cout << "请输入你想添加的书籍数量:" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l;
	while (n>0)
	{
		Node* cur;
		Init(cur);
		cout << "输入书的ISBN：" << endl;
		cin >> cur->data.ISBN;
		cout << "输入书的名字：" << endl;
		cin >> cur->data.BookName;
		cout << "输入书的价格：" << endl;
		cin >> cur->data.Price;
		if ((l->next)!=nullptr)
		{
			if (CheckIsRepeat(l, cur))
			{
			}
			else
			{
				cur->data.numbers++;
				tmp->next = cur;
				tmp = cur;
			}
		}
		else if ((l->next) == nullptr)
		{
			cur->data.numbers++;
			tmp->next = cur;
			tmp = cur;
		}
		n--;
	}
}

void show(Node*& l)
{
	cout << "----------------------------------------------" << endl;
	cout << "书号                书名                价格                数量" << endl;
	Node* tmp = l->next;
	for (; tmp ; )
	{
		/*tmp = tmp->next;*/
		if (tmp->data.numbers != 0)
		{
			cout << tmp->data.ISBN << "                   " << tmp->data.BookName << "                  " << tmp->data.Price << "                  " << tmp->data.numbers << endl;
			tmp = tmp->next;
		}
		else if (tmp->data.numbers == 0)
		{
			tmp = tmp->next;
		}
	}
}
void menu()
{
	cout << "****************************" << endl;
	cout << "欢迎进入西安科技大学图书系统" << endl;
	cout << "****************************" << endl;
	cout << "***0.添加书籍*********1.浏览全部书籍************" << endl;
	cout << "***2.查询书籍*********3.借阅书籍    ************" << endl;
	cout << "***4.归还    *********5.退出        ************" << endl;
}
void Find(Node*& l)
{
	cout << "请输入你想查找的书籍：" << endl;
	char arr[30] = "";
	cin >> arr;
	Node* tmp = l->next;
	for (; tmp; tmp = tmp->next)
	{
		if (strcmp(tmp->data.BookName, arr) == 0)
		{
			cout << tmp->data.ISBN << "                   " << tmp->data.BookName << "                  " << tmp->data.Price << "                  " << tmp->data.numbers << endl;
			return;
		}
	}
	cout << "没有此书！！！" << endl;
}
void Borrow(Node*& l)
{
	cout << "请输入ISBN来借书" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l->next;
	while (tmp)
	{
		if (tmp->data.ISBN == n)
		{
			if (tmp->data.numbers == 0)
			{
				cout << "书已借完！！！" << endl;
			}
			/*Node* pos = tmp->next;
			if (pos == nullptr)
			{
				return;
			}
			tmp->next = pos->next;
			free(pos);*/
			else 
			{
				tmp->data.numbers--;
				cout << "已成功借阅，请在30台内归还" << endl;
				cout << endl;
			}
		}
		tmp = tmp->next;
	}
}
void BackBooks(Node*& l)
{
	cout << "请输入你归还的书号" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l->next;
	for (; tmp; tmp = tmp->next)
	{
		if (tmp->data.ISBN == n)
		{
			tmp->data.numbers++;
			cout << "还书成功！！！" << endl;
		}
	}
}
int main()
{
	Node*l;
	int input = 0;
	do
	{
		menu();
		cout << "请输入你的选择" << endl;
		cin >> input;

		switch (input)
		{
		case 0:
			CreateBooks(l);
			break;
		case 1:
			show(l);
			break;
		case 2:
			Find(l);
			break;
		case 3:
			Borrow(l);
			break;
		case 4:
			BackBooks(l);
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (input != 5);
	cout << "谢谢使用,再见！！！" << endl;
	system("pause");
	return 0;
}