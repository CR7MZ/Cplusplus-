#include<iostream>
#include<string>
using namespace std;
//https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())//�����ַ����ŵ�a��
			swap(a, b);
		string maxstr;//�洢������Ӵ�
		for (int i = 0; i < a.size(); i++)//��a�б��������ν�ȡ�ַ������ŵ�b����
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (b.find(temp) == std::string::npos)//�Ҳ���
					break;
				else if (maxstr.size() < temp.size())
					maxstr = temp;
			}
		}
		cout << maxstr << endl;
	}
	return 0;
}