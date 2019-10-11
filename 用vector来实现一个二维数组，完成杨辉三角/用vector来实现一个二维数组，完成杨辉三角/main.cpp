#include<iostream>
#include<vector>
using namespace std;
class solution
{
	//������ǵĺ���˼�룺ÿ�е��׺�βԪ�ض���1���м�� v[i][j=v[i-1][j-1]+v[i-1][j]��
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> v;//����һ����ά����Ŀռ�
		v.resize(numRows);//����numRows��
		for (int i = 0; i < numRows; i++)//ÿ�п��ٶ�Ӧ��i+1��
		{
			v[i].resize(i + 1, 0);
			v[i][0] = 1;//��ÿ�еĵ�һ�и�ֵΪ1
			v[i][i] = 1;//��ÿ�е����һ����ֵΪ1
		}
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == 0)
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];//������ǵĺ���
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