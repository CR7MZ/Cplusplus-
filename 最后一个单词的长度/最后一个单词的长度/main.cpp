//��Ŀ��https://leetcode-cn.com/problems/length-of-last-word/submissions/
#include<iostream>
#include<string>
//�Ӻ���ǰ��������flag������Ƿ��Ѿ���������������ո��ұ��Ϊ1��˵���õ����һ�����ʳ��ȡ���flagΪ0˵����û���������ʣ���������
int lengthOfLastWord(std::string s) {
	int count = 0;
	int flag = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			if (flag == 0)
				continue;
			break;
		}
		else
		{
			flag = 1;
			count++;
		}
	}
	return count;
}