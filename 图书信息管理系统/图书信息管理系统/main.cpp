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
	cout << "������������ӵ��鼮����:" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l;
	while (n>0)
	{
		Node* cur;
		Init(cur);
		cout << "�������ISBN��" << endl;
		cin >> cur->data.ISBN;
		cout << "����������֣�" << endl;
		cin >> cur->data.BookName;
		cout << "������ļ۸�" << endl;
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
	cout << "���                ����                �۸�                ����" << endl;
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
	cout << "��ӭ���������Ƽ���ѧͼ��ϵͳ" << endl;
	cout << "****************************" << endl;
	cout << "***0.����鼮*********1.���ȫ���鼮************" << endl;
	cout << "***2.��ѯ�鼮*********3.�����鼮    ************" << endl;
	cout << "***4.�黹    *********5.�˳�        ************" << endl;
}
void Find(Node*& l)
{
	cout << "������������ҵ��鼮��" << endl;
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
	cout << "û�д��飡����" << endl;
}
void Borrow(Node*& l)
{
	cout << "������ISBN������" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l->next;
	while (tmp)
	{
		if (tmp->data.ISBN == n)
		{
			if (tmp->data.numbers == 0)
			{
				cout << "���ѽ��꣡����" << endl;
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
				cout << "�ѳɹ����ģ�����30̨�ڹ黹" << endl;
				cout << endl;
			}
		}
		tmp = tmp->next;
	}
}
void BackBooks(Node*& l)
{
	cout << "��������黹�����" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l->next;
	for (; tmp; tmp = tmp->next)
	{
		if (tmp->data.ISBN == n)
		{
			tmp->data.numbers++;
			cout << "����ɹ�������" << endl;
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
		cout << "���������ѡ��" << endl;
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
	cout << "ллʹ��,�ټ�������" << endl;
	system("pause");
	return 0;
}