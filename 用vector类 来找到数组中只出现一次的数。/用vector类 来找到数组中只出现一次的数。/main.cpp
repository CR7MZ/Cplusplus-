#include<iostream>
#include<vector>
using namespace std;
//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//ǰ�᣺���ÿ��������ռ䡣
class solution
{
public:
	int singleNumber(vector<int>& v)
	{
		int result = 0;//���������������������Ԫ�ض����
		for (auto e : v)
			result ^= e;
		return result;
	}
};
int main()
{
	vector<int> v{ 2, 1, 2 };
	solution s;
	int result = 0;
	result=s.singleNumber(v);
	cout << "ֻ����һ�ε����ǣ�"<<result << endl;
	system("pause");
	return 0;
}