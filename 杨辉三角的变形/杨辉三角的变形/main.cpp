#include<iostream>
using namespace std;
#include<vector>
//https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
void Func()
{
	int n = 0;
	while (cin >> n)
	{
		vector<vector<int>> v(n);//����һ����ά����
		for (int i = 0; i<n; i++)
		{
			v[i].resize(2 * n - 1, 0);//ÿ�г�ʼ��Ϊ2*n-1�У���Ϊһ�����Ϊ2*n-1��
		}
		v[0][(2 * n - 1) / 2] = 1;//��һ�е��м��ʼ��Ϊ1
		for (int i = 1; i<n; i++)//��ÿ�еı߽磬��ʼ��Ϊ1
		{
			v[i][((2 * n - 1) / 2) - i] = 1;
			v[i][((2 * n - 1) / 2) + i] = 1;
		}
		for (int i = 1; i<n; i++)//�����������
		{
			for (int j = 1; j<(2 * n - 2); j++)
			{

				v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
			}
		}
		int k = 0;
		for (k = 0; k < (2 * n - 1); k++)//�������һ�����ݣ�����ܱ�2���������λ������+1��
		{
			if (v[n - 1][k] % 2 == 0)
			{
				cout << k + 1 << endl;
				break;
			}
		}
		if (k == 2 * n - 2)//���������������û�������-1
			cout << "-1" << endl;
	}
}
int main()
{
	Func();
	system("pause");
	return 0;
}