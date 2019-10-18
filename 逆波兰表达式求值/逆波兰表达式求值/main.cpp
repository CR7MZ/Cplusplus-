#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
//�����沨����ʾ��������ʽ��ֵ��
//��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��

//�沨�����ʽ��RPN
//���Ǻ�׺���ʽ��a b + ; ��a+b---->ת��Ϊ��׺���ʽ��a b +��
class solution
{
public:
	int IsRPN(vector<string>& tokens)
	{
		stack<int> s;//����һ��ջ
		for (size_t i = 0; i < tokens.size(); i++)//����������ַ�������
		{
			string& str = tokens[i];//����һ���ַ����Ķ���������������Ĳ������ַ�����
			if (!(str == "+" || str == "-" || str == "*" || str == "/"))//�ҳ��ַ��������У������ַ�����
				s.push(atoi(tokens[i].c_str()));//���ַ��������е������ַ���ת��Ϊ�������֡�ͬʱѹջ
			else//����ҳ����ǲ�����
			{
				int right = s.top();//��һ��ջ��Ԫ��Ϊ�Ҳ�������
				s.pop();//��ջ
				int left = s.top();//�ڶ���ջ��Ԫ��Ϊ�������
				s.pop();//��ջ
				switch (str[0])//str[0]��ʾ�ĸ������ַ�������switch
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
	cout << "������Ϊ��" << result << endl;
	system("pause");
	return 0;
}