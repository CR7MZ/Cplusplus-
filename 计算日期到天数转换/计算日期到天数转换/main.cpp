#include<iostream>
#include<vector>
using namespace std;
//��Ŀ��https://www.nowcoder.com/questionTerminal/769d45d455fe40b385ba32f97e7bcded

bool Isleap(int year)//�ж��Ƿ�Ϊ����
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}
int main()
{
	int year;
	int mon;
	int day;
	while (cin >> year >> mon >> day)
	{
		vector<vector<int>> v(13);//����һ����ά���飬����ŵ���ÿ���¶�Ӧ������
		int flag = 0;
		for (int i = 0; i<v.size(); i++)
		{
			if (i == 2)//�����2�£�Ϊ28��
			{
				v[i].resize(28, 0);
				flag = 1;
				continue;
			}
			if (i == 8)//7��8�·ݶ���31��
			{
				flag = 1;
			}
			if (flag == 0)//flagΪ0����ʾ����30��
			{
				v[i].resize(30, 0);
				flag = 1;//��������£��¸���Ӧ���Ǵ���31�죬��flag��Ϊ1
				continue;
			}
			if (flag == 1)//flagΪ1ʱ������31��
			{
				v[i].resize(31, 0);
				flag = 0;//��������£��¸���Ӧ����С��30�죬��flag��Ϊ0
				continue;
			}
		}
		if (year <= 0 || mon <= 0 || mon > 12 || day <= 0 || day > v[mon].size())//�ж������Ƿ�Ϸ�
			return -1;
		int mi = 0;//�����Ѿ����˶�����
		for (int i = 1; i < mon; i++)
		{
			mi += v[i].size();
		}
		if (Isleap(year))//��������� ��������+1
			mi = mi + day + 1;
		else
			mi = mi + day;
		cout << mi << endl;;
	}
	return 0;
}