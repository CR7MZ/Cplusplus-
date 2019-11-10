#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//例如：
//A = "abc"; B = "b";
//这里有四种把B插入A的方法：
//在a之前：不是回文数
//在a之后：是回文数
//在b之后：是回文数
//在第二个b之后：不是回文数
int main()
{
	string A;
	string B;
	getline(cin, A);
	getline(cin, B);
	int count = 0;
	string C;
	string D;
	string E;
	for (int i = 0; i < A.size(); i++)//一共有A.size()+1个方法，最后一种方法，也就是将B放在A后，所以最后时限即可
	{
		C = A;//将A存在C中
		D = C.insert(i, B);//将B插入不同位置，得到D
		E = D;//E来保存D翻转之前的字符串
		reverse(D.begin(), D.end());//翻转字符串D
		if (D == E)//如果翻转前的D与翻转后相同，则为回文数
		{
			count++;//记录是回文数的位置次数
		}
	}
	D = A.append(B);//为B插入的最后一个位置
	E = D;
	reverse(D.begin(), D.end());
	if (D == E)
	{
		count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}