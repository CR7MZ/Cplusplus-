#include<iostream>
using namespace std;
//https://www.nowcoder.com/profile/144108282/codeBookDetail?submissionId=61356695

//˼·��
//���������ƣ�ÿ����һ�κ�1��λ2�룬�����1��count++��ֱ����һ��0���֣���Ϊ��һ��������1����count��ֵ��max
//����ִ����ȥ����֮���count����max�滻max������maxΪ���������bit����
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 0;
		int flag = 0;
		int max = 0;
		for (int i = 0; i<31; i++)
		{
			if (((n >> i) & 1) == 1)
			{
				if (flag == 0)//����һ�����������ּ�¼�����Ҫ��count��Ϊ0������ֻ��flag==0ʱ���Ŵ���һ�μ�¼��
					count = 0;
				count++;
				flag = 1;
			}
			else if (flag == 1){//ֻ��flag==1ʱ���űȽϴ�С��Ҳ����˵������0ʱ���Ž��˺������ڣ��Ƚ���flag��λ0
					{
						if (count>max)
							max = count;
						flag = 0;
					}
			}
		}
		cout << max << endl;;
	}
	system("pause");
	return 0;
}