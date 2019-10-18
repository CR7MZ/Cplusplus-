#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
//根据逆波兰表示法，求表达式的值。
//有效的运算符包括 + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

//逆波兰表达式：RPN
//就是后缀表达式：a b + ; （a+b---->转化为后缀表达式：a b +）
class solution
{
public:
	int IsRPN(vector<string>& tokens)
	{
		stack<int> s;//定义一个栈
		for (size_t i = 0; i < tokens.size(); i++)//遍历输入的字符串数组
		{
			string& str = tokens[i];//定义一个字符串的对象，来保存遍历到的操作符字符串。
			if (!(str == "+" || str == "-" || str == "*" || str == "/"))//找出字符串数组中，数字字符串。
				s.push(atoi(tokens[i].c_str()));//将字符串数组中的数字字符串转化为整型数字。同时压栈
			else//如果找出的是操作符
			{
				int right = s.top();//第一个栈顶元素为右操作数。
				s.pop();//出栈
				int left = s.top();//第二个栈顶元素为左操作数
				s.pop();//出栈
				switch (str[0])//str[0]表示哪个操作字符，进行switch
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};
int main()
{
	vector<string> v{ "2", "1", "+", "3", "*" };
	solution s;
	int result = s.IsRPN(v);
	cout << "计算结果为：" << result << endl;
	system("pause");
	return 0;
}