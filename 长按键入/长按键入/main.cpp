//��Ŀ��https://leetcode-cn.com/problems/long-pressed-name/submissions/
#include<iostream>
#include<string>
//���������������ַ����ĵ�������ָ���ַ�����ͷ����ʼ�����������nameit��typeitָ����ַ���һ��������������������ƶ���
//����һ����typeit������������ֱ���ҵ���nameitָ���ַ���һ����������һ������ƶ���
//������nameit����β����˵����ȷ����typeit����β����ʹѭ���˳��������
bool isLongPressedName(std::string name, std::string typed) {
	auto nameit = name.begin();
	auto typeit = typed.begin();
	while (nameit != name.end() && typeit != typed.end())
	{
		if (*nameit == *typeit)
		{
			nameit++;
			typeit++;
		}
		else
			typeit++;
	}
	return nameit == name.end();
}
int main()
{

}