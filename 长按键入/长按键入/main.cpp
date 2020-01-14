//题目：https://leetcode-cn.com/problems/long-pressed-name/submissions/
#include<iostream>
#include<string>
//方法：定义两个字符串的迭代器，指向字符串的头。开始向后遍历。如果nameit和typeit指向的字符串一样，两迭代器都想向后移动。
//若不一样，typeit继续向后遍历，直到找到和nameit指向字符串一样，两个才一起向后移动。
//最后如果nameit到了尾部，说明正确。若typeit到了尾部，使循环退出，则错误。
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