//https://www.nowcoder.com/questionTerminal/fbcf95ed620f42a88be24eb2cd57ec54

//�������򣬽������ų������������м��������Ϊ��������һ����������������飬�����м���������ж�������Ƿ��������
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