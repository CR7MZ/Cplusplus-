#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//���磺
//A = "abc"; B = "b";
//���������ְ�B����A�ķ�����
//��a֮ǰ�����ǻ�����
//��a֮���ǻ�����
//��b֮���ǻ�����
//�ڵڶ���b֮�󣺲��ǻ�����
int main()
{
	string A;
	string B;
	getline(cin, A);
	getline(cin, B);
	int count = 0;
	string C;
	string D;
	string E;
	for (int i = 0; i < A.size(); i++)//һ����A.size()+1�����������һ�ַ�����Ҳ���ǽ�B����A���������ʱ�޼���
	{
		C = A;//��A����C��
		D = C.insert(i, B);//��B���벻ͬλ�ã��õ�D
		E = D;//E������D��ת֮ǰ���ַ���
		reverse(D.begin(), D.end());//��ת�ַ���D
		if (D == E)//�����תǰ��D�뷭ת����ͬ����Ϊ������
		{
			count++;//��¼�ǻ�������λ�ô���
		}
	}
	D = A.append(B);//ΪB��������һ��λ��
	E = D;
	reverse(D.begin(), D.end());
	if (D == E)
	{
		count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}