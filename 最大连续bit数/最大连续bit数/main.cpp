#include<iostream>
using namespace std;
//https://www.nowcoder.com/profile/144108282/codeBookDetail?submissionId=61356695

//思路：
//将数字右移，每右移一次和1按位2与，如果是1则count++，直到下一个0出现，此为第一段连续的1，将count赋值给max
//继续执行下去，若之后的count大于max替换max。最后的max为最大连续的bit数字
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
				if (flag == 0)//当第一段连续的数字记录完后，需要将count置为0，但是只有flag==0时，才代表一段记录完
					count = 0;
				count++;
				flag = 1;
			}
			else if (flag == 1){//只有flag==1时，才比较大小，也就是说当遇到0时，才进此函数体内，比较完flag置位0
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