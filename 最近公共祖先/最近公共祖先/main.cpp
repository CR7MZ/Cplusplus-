#include<iostream>
using  namespace std;
//https://www.nowcoder.com/questionTerminal/70e00e490b454006976c1fdf47f155d9

//思路：
//因为头结点编号是1，所以知道左节点a、和右节点b的情况下。父节点为a / 2、b / 2，因为存在a、b不等的情况，所以a > b时
//a /= 2; 反之b /= 2;直到a==b则为公共祖先节点。
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