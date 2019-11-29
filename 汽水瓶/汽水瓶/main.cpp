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
		if (v[i] == 0)//当输入为0，输入结束
		{
			break;
		}
	}
	v.resize(size);//将数组大小变为输入的数据个数
	for (int i = 0; i<v.size(); i++)//对每个输入进行运算
	{
		if (v[i] == 0)//当数组遍历到0时，跳出
			break;
		int count = 0;//来统计喝了瓶数
		int result = 0;//统计最终喝的总瓶数
		while (1)
		{
			if (v[i] == 2)//当剩两个空瓶子时，可再加一瓶
			{
				result++;
			}
			if (v[i] >= 3)
			{
				count = v[i] / 3;//换多少瓶
				v[i] = count + v[i] % 3;//剩下的空瓶子
				result += count;//统计喝的总瓶数
			}
			else
			{
				cout << result << endl;
				break;
			}
		}
	}
}

void Func2()//简洁方法
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
		cout << v[i] / 2 << endl;//根据题意可得只要有两个空瓶子，就可以换一瓶。
	}
}
int main()
{
	Func2();
	system("pause");
	return 0;
}

