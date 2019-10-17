#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�
class solution
{
public:
	bool IsPopOrder(vector<int>pushV, vector<int>popV)
	{
		stack<int> s;
		int outindex = 0;
		int inindex = 0;
		while (outindex<popV.size())
		{
			while (s.empty() || s.top() != popV[outindex])//��ջΪ�գ�����ջ��Ԫ�غ͵������е�һ��Ԫ�ز����ʱ��ѹջ��
			{
				if (inindex < pushV.size())//���������еķ�Χ��ѹջ��
					s.push(pushV[inindex++]);
				else
					return false;//���ջ��Ϊ����ջ��Ԫ�غ���Ե�������Ԫ�ز����ʱ���Լ����������Ѿ�ѹջ��ʱ�����ǵ������С�
			}
			s.pop();//��ջ��Ԫ�غ͵������е����Ԫ�����ʱ��ɾ��ջ�����Ƚ�ջ��һ��Ԫ�ء�
			outindex++;//�ҵ�����������һ��Ԫ�ء�
		}
		return true;
	}
};
void test()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };//ѹ������
	vector<int> v2{ 4, 3, 5, 1, 2 };//��������
	solution s;
	if (s.IsPopOrder(v1, v2))
		cout << "�ǵ�������" << endl;
	else
		cout << "���ǵ�������" << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}