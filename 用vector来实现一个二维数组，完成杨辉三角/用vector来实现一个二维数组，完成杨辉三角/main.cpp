#include<iostream>
#include<vector>
using namespace std;
class solution
{
	//杨辉三角的核心思想：每行的首和尾元素都是1，中间的 v[i][j=v[i-1][j-1]+v[i-1][j]。
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> v;//开辟一个二维数组的空间
		v.resize(numRows);//开辟numRows行
		for (int i = 0; i < numRows; i++)//每行开辟对应的i+1列
		{
			v[i].resize(i + 1, 0);
			v[i][0] = 1;//将每行的第一列赋值为1
			v[i][i] = 1;//将每行的最后一个赋值为1
		}
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == 0)
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];//杨辉三角的核心
				}
			}
		}
		return v;
	}
};
int main()
{
	solution s;
	vector<vector<int>> v=s.generate(5);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}