//��Ŀ��https://leetcode-cn.com/problems/ransom-note/submissions/
#include<iostream>
#include<string>
//����ransomNote�ַ�����ÿ���ַ�����magazine���Ҳ�����˵��������ɣ�����false����֮����������ֱ��ransomNote�����꣬����ture��
//ע�⣺��magazine���ҵ�һ����Ӧ���ַ�����Ҫɾ�����ַ�����Ϊ��ĿҪ����ransomNote���ַ����ּ��Σ�magazine�о�Ҫ�м����ַ��������޷��ﵽĿ��
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