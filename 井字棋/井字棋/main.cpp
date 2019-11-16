#include<iostream>
#include<vector>
using namespace std;
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，
//为0表示没有棋子，为 - 1代表是对方玩家的棋子。

//思路：
//很简单，我们下的棋子是1，对方下的是-1，所以棋盘上所有棋子加起来大于0，我们赢
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

	//检查每一行、每一列、对角线，将其数字加起来，若等于board.size()则赢
	bool checkWon2(vector<vector<int>> board)
	{
		int len = board.size();
		//检查行
		for (int i = 0; i < len; i++)
		{
			int sum = 0;
			for (int j = 0; j < len; j++)
				sum += board[i][j];
			if (sum == len)
				return true;
		}
		//检查列
		for (int i = 0; i < len; i++)
		{
			int sum = 0;
			for (int j = 0; j < len; j++)
				sum += board[j][i];
			if (sum == len)
				return true;
		}
		//对角线
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += board[i][i];
		}
		if (sum == len)
			return true;
		//副对角线
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
		cout << "恭喜你赢了" << endl;
	}
	else
		cout << "你输了" << endl;
	system("pause");
	return 0;
}