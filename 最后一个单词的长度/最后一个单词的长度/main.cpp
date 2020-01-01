//题目：https://leetcode-cn.com/problems/length-of-last-word/submissions/
#include<iostream>
#include<string>
//从后向前遍历，用flag来标记是否已经计数，如果遇到空格且标记为1则说明得到随后一个单词长度。若flag为0说明还没有遇到单词，继续遍历
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