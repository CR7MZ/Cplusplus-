#include<iostream>
#include<string>
using namespace std;
/*给定一个字符串和一个整数 k，
你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
如果剩余少于 k 个字符，则将剩余的所有全部反转。
如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。*/
string reverse(string s,int k)
{
	int i = 0;
	if (s.size() <= k)//如果字符串大小小于K，则全部翻转。
	{
		reverse(s.begin(), s.end());
	}
	else//当字符串大于K
	{
		while (2 * (i + 1)*k <= s.size())//若2k小于字符串大小。
		{
			reverse((s.begin()+i*k*2), s.begin() +i*k*2+ k);//前k个字符翻转。若字符串大小大于2*k小于2*i*k，退出循环。
			i++;
		}
		if (s.size() - 2 * k*i <= k)//若剩下的字符串小于等于k，则剩余的全部翻转。
			reverse((s.begin() + 2 * k*i), s.end());
		else//若剩余字符串大小大于k且小于2k，则翻转剩余前k个字符串。
			reverse((s.begin() + 2 * k*i), (s.begin() + 2 * k*i + k));
	}
	return s;
}
int main()
{
	string s;
	getline(cin, s);
	int k = 0;
	cin >> k;
	string s1 = reverse(s, k);
	cout << s1 << endl;
	system("pause");
	return 0;
}