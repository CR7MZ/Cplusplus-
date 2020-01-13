//题目：https://leetcode-cn.com/problems/ransom-note/submissions/
#include<iostream>
#include<string>
//遍历ransomNote字符串的每个字符，在magazine若找不到，说明不能组成，返回false。反之继续遍历，直到ransomNote遍历完，返回ture。
//注意：在magazine中找到一个对应的字符，就要删除此字符，因为题目要求是ransomNote里字符出现几次，magazine中就要有几个字符，否则无法达到目的
bool canConstruct(std::string ransomNote, std::string magazine) {
	for (size_t i = 0; i<ransomNote.size(); i++)
	{
		int ret = magazine.find(ransomNote[i]);
		if (ret == std::string::npos)
		{
			return false;
		}
		else
		{
			magazine.erase(ret, 1);
		}
	}
	return true;
}