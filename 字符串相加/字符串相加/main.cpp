#include<iostream>
using namespace std;
#include<string>
//���������̫�󣬿������ַ������͵�����������
class solution
{
public:
	string addStrings(string num1, string num2)
	{
		int Lsize = num1.size();
		int Rsize = num2.size();
		if (Lsize < Rsize)
		{
			num1.swap(num2);
			swap(Lsize, Rsize);
		}
		//��string��Ĺ��캯�������Ұ����ĳ��ȱ�Ϊ����ַ�����1���Ҷ���ʼ��Ϊ0�ַ���������������
		string strRet(Lsize + 1, '0');
		char offset = 0;//��λ
		for (int L = num1.size() - 1, R = num2.size()-1; L >= 0; L--, R--)
		{
			char cRet = num1[L] - '0';//�Ӹ�λ��ʼ��������ӡ��ַ�'9'��ȥ�ַ�'0'��Ϊ����9��
			if (R >= 0)
			{
				cRet += num2[R]-'0';
			}
			cRet += offset;//����֮ǰ��ӵĽ�λ��
			offset = 0;//��λ����
			if (cRet >= 10)
			{
				offset = 1;//�����һλ��Ӻ���ڵ���10��λ
				cRet -= 10;
			}
			strRet[L + 1] += cRet;//��������һλ����֮ǰ������ַ��������б��档
		}
		if (offset == 1)
		{
			strRet[0] += 1;//���������λ���п����ٽ�λ����offsetΪ1���һλ
		}
		else
			strRet.erase(strRet.begin());//������λ���꣬û�н�λ�Ļ���ɾȥ�ַ����׵�ַ��
		return strRet;
	}
};
int main()
{
	string num1("111");
	string num2("900");
	solution s;
	//s.addStrings(num1, num2);
	string a(s.addStrings(num1, num2));
	cout << a<< endl;
	system("pause");
	return 0;
}