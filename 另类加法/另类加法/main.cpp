#include<iostream>
using namespace std;
//计算两个数的加法，不能用+以及计算运算符

//思路：
//tmp = A&B 相当于是A+B的进位。
// A^B  相当于是A+B，相异为1，相同为0，所以异或后，当有哪一位为0是说明需要进位。这是tmp左移1赋给B，继续循环运算
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