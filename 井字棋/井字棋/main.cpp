#include<iostream>
#include<vector>
using namespace std;
//����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
//����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�
//Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ����ӡ�

//˼·��
//�ܼ򵥣������µ�������1���Է��µ���-1�������������������Ӽ���������0������Ӯ
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		int sum = 0;
		for (int i = 0; i < board.size(); i ++ )
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				sum += board[i][j];
			}
		}
		if (sum > 0)
			return true;
		else
			return false;
	}

	//���ÿһ�С�ÿһ�С��Խ��ߣ��������ּ�������������board.size()��Ӯ
	bool checkWon2(vector<vector<int>> board)
	{
		int len = board.size();
		//�����
		for (int i = 0; i < len; i++)
		{
			int sum = 0;
			for (int j = 0; j < len; j++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//�����
		for (int i = 0; i < len; i++)
		{
			int sum = 0;
			for (int j = 0; j < len; j++)
				sum += board[j][i];
			if (sum == len)
				return true;
		}
		//�Խ���
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += board[i][i];
		}
		if (sum == len)
			return true;
		//���Խ���
		sum = 0;
		for (int i = 0; i <len; i++)
		{
			sum += board[i][len - i - 1];
		}
		if (sum == len)
			return true;
		return false;
	}
};
int main()
{
	vector<vector<int>> v = { { 1, 0, 0 }, {-1,-1,-1}, {1,0,0} };
	Board b;
	if (b.checkWon2(v))
	{
		cout << "��ϲ��Ӯ��" << endl;
	}
	else
		cout << "������" << endl;
	system("pause");
	return 0;
}