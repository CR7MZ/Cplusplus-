#include<iostream>
using namespace std;
#include<string>
#include<vector>
//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 
//1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" < "doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

bool Func1(const vector<string>& v)//根据字符串的字典序排序，注意根据字典序排序，意思是根据字符串大小进行比较
{
	int flag = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].compare(v[i + 1]) <0)
			flag = 1;
		else
			flag = -1;
	}
	if (flag == 1)
		return true;
	else if (flag == -1)
		return false;
}
bool Func2(const vector<string>& v)//根据字符串的长度排序
{
	int flag = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].size() < v[i + 1].size())
			flag = 1;
		else
			flag = -1;
	}
	if (flag == 1)
		return true;
	else if (flag == -1)
		return false;
}
int main()
{
	int n = 0;
	cin >> n;
	if (n>100)
		return -1;
	vector<string> v;
	while (n)
	{
		string s;
		cin >> s;
		for (int i = 0; i<s.size(); i++)
		{
			if (!(s[i] >= 'a'&&s[i] <= 'z'))
				return -1;
		}
		if (s.size() >= 100)
			return -1;
		v.push_back(s);
		n--;
	}
	if (Func1(v) && Func2(v))
		cout << "both" << endl;
	else if (Func1(v))
		cout << "lexicographically" << endl;
	else if (Func2(v))
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	system("pause");
	return 0;
}