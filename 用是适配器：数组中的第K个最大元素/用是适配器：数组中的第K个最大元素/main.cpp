#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class solution
{
public:
	void FindKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int> q(nums.begin(), nums.end());//����vector����q�У���Ϊ�����ȼ��������Ǵ�ѣ�����
		//�ǴӴ�С�ġ�
		for (int i = 0; i < k - 1; i++)//ֻ��ɾ������ͷ��ɾ����i<k-1���ɡ�
			q.pop();
		cout << "��K��������Ϊ��" << q.top() << endl;//��ʱ����ͷΪ��K��������
	}
};
int main()
{
	vector<int> v{ 3, 2, 1, 5, 6, 4 };
	solution s;
	s.FindKthLargest(v, 2);
	system("pause");
	return 0;
}