#include<iostream>
using namespace std;
//�����������ļӷ���������+�Լ����������

//˼·��
//tmp = A&B �൱����A+B�Ľ�λ��
// A^B  �൱����A+B������Ϊ1����ͬΪ0���������󣬵�����һλΪ0��˵����Ҫ��λ������tmp����1����B������ѭ������
int add(int A,int B)
{
	int tmp = 0;
	while (B != 0)
	{
		tmp = A&B;
		A = A^B;
		B = tmp << 1;
	}
	return A;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout<<add(a, b);
	system("pause");
	return 0;

}