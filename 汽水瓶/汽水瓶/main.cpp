#include<iostream>
using namespace std;
#include<vector>
//https://www.nowcoder.com/questionTerminal/fe298c55694f4ed39e256170ff2c205f
void Func()
{
	vector<int> v(10);
	int size = 0;
	for (int i = 0; i<10; i++)
	{
		cin >> v[i];
		size++;
		if (v[i] == 0)//������Ϊ0���������
		{
			break;
		}
	}
	v.resize(size);//�������С��Ϊ��������ݸ���
	for (int i = 0; i<v.size(); i++)//��ÿ�������������
	{
		if (v[i] == 0)//�����������0ʱ������
			break;
		int count = 0;//��ͳ�ƺ���ƿ��
		int result = 0;//ͳ�����պȵ���ƿ��
		while (1)
		{
			if (v[i] == 2)//��ʣ������ƿ��ʱ�����ټ�һƿ
			{
				result++;
			}
			if (v[i] >= 3)
			{
				count = v[i] / 3;//������ƿ
				v[i] = count + v[i] % 3;//ʣ�µĿ�ƿ��
				result += count;//ͳ�ƺȵ���ƿ��
			}
			else
			{
				cout << result << endl;
				break;
			}
		}
	}
}

void Func2()//��෽��
{
	vector<int> v(10);
	int size = 0;
	for (int i = 0; i<10; i++)
	{
		cin >> v[i];
		size++;
		if (v[i] == 0)
		{
			break;
		}
	}
	v.resize(size);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 0)
			break;
		cout << v[i] / 2 << endl;//��������ɵ�ֻҪ��������ƿ�ӣ��Ϳ��Ի�һƿ��
	}
}
int main()
{
	Func2();
	system("pause");
	return 0;
}

