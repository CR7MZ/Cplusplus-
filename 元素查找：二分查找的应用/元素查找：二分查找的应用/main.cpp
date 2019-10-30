#include<iostream>
#include<vector>
using namespace std;
//��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
//���磬ԭ����Ϊ[1, 2, 3, 4, 5, 6]��������λ5��λ�ü������[6, 1, 2, 3, 4, 5], 
//���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������


//����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)��
//��֤������Ԫ�ػ��졣
class solution
{
public:
	int FindElement(vector<int> v, int n, int x)//�ö��ֲ���
	{
		int start = 0;
		int end = n - 1;
		int mid;
		//������������λ��ģ�����֮��Ԫ�ص���������һ����һ��������ġ�
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (v[mid] == x)
				return mid;
			if (x > v[mid])
			{
				//���v[start] > v[mid]˵���ұ�������ģ�x>v[end]˵��x��mid���
				if (x > v[end] && v[start] > v[mid])
					end = mid - 1;
				else//���v[start] < v[mid]˵�����������ģ�x<v[end]˵��x��mid�ұ�
					start = mid + 1;
			}
			else//��x < v[mid]
			{
				//���v[start] < v[mid]˵�����������ģ�x<v[start]˵��x��mid�ұ�
				if (x < v[start] && v[start] < v[mid])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
	}
};
int main()
{
	vector<int> v{ 6, 1, 2, 3, 4, 5 };
	solution s;
	cout<<s.FindElement(v, v.size(), v.front());
	system("pause");
	return 0;
}