//https://www.nowcoder.com/questionTerminal/fbcf95ed620f42a88be24eb2cd57ec54

//运用排序，将数组排成有序，则数组中间的数可能为超过数组一半的数，最后遍历数组，计数中间这个数，判断其二倍是否大于数组
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		for (int i = 0; i<gifts.size(); i++)
		{
			for (int j = 0; j<gifts.size() - 1; j++)
			{
				if (gifts[j]>gifts[j + 1])
					swap(gifts[j], gifts[j + 1]);
			}
		}
		int mid = n / 2;
		int count = 0;
		for (auto e : gifts)
		{
			if (e == gifts[mid])
				count++;
		}
		if (count * 2>n)
			return gifts[mid];
		else
			return 0;
	}
};