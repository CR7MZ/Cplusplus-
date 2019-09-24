#include<iostream>
using namespace std;
class solution
{
public:
	int firstUniqchar(string s)
	{
		//�ַ�����Χ��0~256
		//1.ͳ��ÿһ���ַ����ֵĴ���
		int count[256] = { 0 };
		for (auto e : s)
		{
			count[e]++;
		}
		//2.�ҵ���һ������һ�ε��ַ����±꣬�����ء�
		for (int i = 0; i < s.size(); ++i)
		{
			if (1 == count[s[i]])
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{
	string s("helloehllsad");
	solution s1;
	int ret=s1.firstUniqchar(s);
	cout << s[ret] << endl;
	system("pause");
	return 0;
}