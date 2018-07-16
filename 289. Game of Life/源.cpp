//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//Given a board with m by n cells, each cell has an initial state live(1) or dead(0).Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) using the following four rules(taken from the above Wikipedia article) :
//
//	Any live cell with fewer than two live neighbors dies, as if caused by under - population.
//	Any live cell with two or three live neighbors lives on to the next generation.
//	Any live cell with more than three live neighbors dies, as if by over - population..
//	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//	Write a function to compute the next state(after one update) of the board given its current state.The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
//
//	Example:
//
//Input:
//[
//	[0, 1, 0],
//	[0, 0, 1],
//	[1, 1, 1],
//	[0, 0, 0]
//]
//Output:
//	  [
//		  [0, 0, 0],
//		  [1, 0, 1],
//		  [0, 1, 1],
//		  [0, 1, 0]
//	  ]
//	  Follow up :
//
//	  Could you solve it in - place ? Remember that the board needs to be updated at the same time : You cannot update some cells first and then use their updated values to update other cells.
//		  In this question, we represent the board using a 2D array.In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array.How would you address these problems ?
#include<vector>
using namespace std;
//o(n) space
class Solution {
	vector<pair<int, int>> direction{ {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> lastRound = board;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				int liveCount = 0;
				for (int k = 0; k < direction.size(); k++) {
					int x = i + direction[k].first;
					int y = j + direction[k].second;
					if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && lastRound[x][y] == 1)
						liveCount++;
				}
				if (lastRound[i][j] == 0 && liveCount == 3)
					board[i][j] = 1;
				else if (lastRound[i][j] == 1 && (liveCount < 2 || liveCount>3))
					board[i][j] = 0;
			}
		}
	}
};

//o(1) space
class Solution {
vector<pair<int, int>> direction{ { -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,0 },{ 1,1 } };
enum state {
	one2zero = 2, zero2zero, zero2one, one2one,
};
public:
	void gameOfLife(vector<vector<int>>& board) {
		
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				int liveCount = 0;
				for (int k = 0; k < direction.size(); k++) {
					int x = i + direction[k].first;
					int y = j + direction[k].second;
					if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && (board[x][y] == 1 || board[x][y]==one2zero || board[x][y]==one2one))
						liveCount++;
				}
				if (board[i][j] == 0 && liveCount == 3)
					board[i][j] = zero2one;
				else if (board[i][j] == 1 && (liveCount < 2 || liveCount>3))
					board[i][j] = one2zero;
			}
		}
		
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] >= 2) {
					if (board[i][j] == one2zero || board[i][j] ==zero2zero) {
						board[i][j] = 0;
					}
					else {
						board[i][j] = 1;
					}
				}
			}
		}
	}
};
