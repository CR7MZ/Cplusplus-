#include<iostream>
using namespace std;
//https://www.nowcoder.com/profile/144108282/codeBookDetail?submissionId=61411225

//����ֻ��Ҫ��m�Ƶ�n��j��i֮�伴�ɣ�����ֻ����m����j���ɡ�
//���ӣ�
//16:10000   ����jΪ1��iΪ3.
//7:111
//����ֻ��7����1���ɣ�Ȼ��������򣬾ͽ�m����n��
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