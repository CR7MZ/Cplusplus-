#include<iostream>
using namespace std;
//https://www.nowcoder.com/profile/144108282/codeBookDetail?submissionId=61411225

//我们只需要将m移到n的j与i之间即可，所以只需让m左移j即可。
//例子：
//16:10000   假设j为1，i为3.
//7:111
//所以只需7左移1即可，然后再相异或，就将m插入n中
class BinInsert
{
public:
	int binInsert(int n,int m,int j,int i)
	{
		m <<= j;
		return m^n;
	}
};
int main()
{
	BinInsert b;
	int n, m, j, i;
	cin >> n >> m >> j >> i;
	cout << b.binInsert(n, m, j, i) << endl;;
	system("pause");
	return 0;
}