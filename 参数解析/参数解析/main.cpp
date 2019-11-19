#include<iostream>
using namespace std;
#include<vector>
#include<string>
//https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677

//思路：
//定义一个string类的数组，来保存从字符串中解析的参数，定义一个flag来判定""情况，当遍历到" 时flag
//进行取反，当再次遇到"时说明这段已解析结束，可以插入到数组中，

void Func()
{
	vector<string> v;
	string s;
	while (getline(cin, s))
	{
		string tmp = "";//来保存遍历出的每个参数
		int flag = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '"')//当遍历到"时，flag取反，代表正在进行"内符号的解析，如果再次遍历到"说明解析结束
				flag = ~flag;
			else if (flag == 0 && s[i] == ' ')//如果遍历到空格，且flag为0（代表1.没有进行"内符号的解析2.已经将""中参数解析结束）
			{
				v.push_back(tmp);
				tmp = "";
			}
			else//没有遍历到空格，并且不为"，将参数存入tmp中
			{
				tmp += s[i];
			}
		}
		v.push_back(tmp);//切记，循环结束后，最后的参数还没有放进数组。
		cout << v.size() << endl;
		for (int i = 0; i<v.size(); i++)
			cout << v[i] << endl;
	}
}
int main()
{
	Func();
	return 0;
}