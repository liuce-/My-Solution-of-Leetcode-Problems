//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//Example:
//
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be :
//
//X X X X
//X X X X
//X X X X
//X O X X
//Explanation :
//
//Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.Two cells are connected if they are adjacent cells connected horizontally or vertically.
//
#include<vector>
using namespace std;
class Solution {
	vector<vector<int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<bool>> visited;
	int row;
	int column;
	bool isInArea(int x, int y) {
		return x >= 0 && x < row && y >= 0 && y < column;
	}
	bool searchFlip(int x, int y, vector<vector<char>>& board) {
		
 		bool surrounded=true;
		for (int i = 0; i < 4; i++) {
			int newx = x + direction[i][0];
			int newy = y + direction[i][1];
			if (!isInArea(newx,newy)) {
				surrounded = false;
			}
			else {
				if (!visited[newx][newy]&&board[newx][newy]=='O') {
					visited[newx][newy] = true;
					//不能这样写，短路求值导致无法执行后面的函数，surrounded = surrounded && searchFlip(newx, newy, board);
					bool temp = searchFlip(newx, newy, board);
					surrounded = surrounded && temp;
				}
			}
		}
		return surrounded;
	}
	void flipBoard(int x, int y, vector<vector<char>>& board) {
		board[x][y] = 'X';
		for (int i = 0; i < 4; i++) {
			int newx = x + direction[i][0];
			int newy = y + direction[i][1];
			if (isInArea(newx, newy) && board[newx][newy] == 'O') {
					flipBoard(newx, newy, board);			
			}
		}
		return ;
	}
public:
	void solve(vector<vector<char>>& board) {
		row = board.size();
		if (row == 0)
			return;
		column = board[0].size();
		visited.resize(row, vector<bool>(column, false));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (board[i][j] == 'O'&&!visited[i][j]) {
					visited[i][j] = true;
					bool surrounded = searchFlip(i, j, board);
					if (surrounded)
						flipBoard(i, j, board);
				}
			}
		}
		return ;
	}
};
//solution2 不包围的肯定在边界，从边界开始搜索。
class Solution2 {
	vector<vector<bool>> visited;
	vector<vector<int>> direction = { {0,-1},{0,1},{1,0},{-1,0} };
	int column = 0;
	int row = 0;
	bool isInArea(int x, int y) {
		return x >= 0 && x < row && y >= 0 && y < column;
	}
	void search(vector<vector<char>>& board, int x, int y) {
		for (int i = 0; i < 4; i++) {
			int newx = x + direction[i][0];
			int newy = y + direction[i][1];
			if (isInArea(newx, newy) && board[newx][newy] == 'O' && !visited[newx][newy]) {
				visited[newx][newy] = true;
				search(board, newx, newy);
			}
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		row = board.size();
		if (row == 0)
			return;
		column = board[0].size();
		visited.resize(row, vector<bool>(column, false));
		vector<int> helper(4,0);
		helper[0] = 0;
		helper[1] = column-1;
		helper[2] = 0;
		helper[3] = row -1;
		for(int j=0;j<2;j++)
		for (int i = 0; i < row; i++) {
			if (board[i][helper[j]] == 'O'&&!visited[i][helper[j]]) {
				visited[i][helper[j]] = true;
				search(board, i, helper[j]);
			}
		}
		for (int j = 2; j<4; j++)
			for (int i = 0; i < column; i++) {
				if (board[helper[j]][i] == 'O' && !visited[helper[j]][i]) {
					visited[helper[j]][i] = true;
					search(board, helper[j], i);
				}
			}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!visited[i][j] && board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};
int main() {
	vector<vector<char>> board = { { 'X', 'O', 'X' },{ 'X', 'O', 'X' },{ 'X', 'O', 'X' } };
		

	Solution2 s;
	s.solve(board);
	return 0;
}