#include<iostream>
using  namespace std;
//https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9

//˼·��
//��Ϊͷ�������1������֪����ڵ�a�����ҽڵ�b������¡����ڵ�Ϊa / 2��b / 2����Ϊ����a��b���ȵ����������a > bʱ
//a /= 2; ��֮b /= 2;ֱ��a==b��Ϊ�������Ƚڵ㡣
class solution
{
public:
	int getLCA(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
				a /= 2;
			if (a < b)
				b /= 2;
		}
		return a;
	}
};
int main()
{
	solution s;
	cout << s.getLCA(4, 9)<<endl;
	system("pause");
	return 0;
}