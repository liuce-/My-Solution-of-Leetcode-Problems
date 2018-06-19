//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//
//Example:
//
//board =
//[
//	['A', 'B', 'C', 'E'],
//	['S', 'F', 'C', 'S'],
//	['A', 'D', 'E', 'E']
//]
//
//Given word = "ABCCED", return true.
//Given word = "SEE", return true.
//Given word = "ABCB", return false.
#include<vector>
#include<string>
using namespace std;
class Solution {
	vector<vector<bool>> visited;
	bool find(vector<vector<char>>& board, string word, int x, int y, int next) {
		bool result = false;
		if (next >= word.size())
			return true;
		if (x - 1 >= 0 && !visited[x-1][y] && board[x - 1][y] == word[next]) {
			visited[x - 1][y] = true;
			result = find(board, word, x - 1, y, next + 1);
			visited[x - 1][y] = false;

		}
		if (!result && x + 1 <board.size() && !visited[x+1][y]&& board[x + 1][y] == word[next]) {
			visited[x + 1][y] = true;
			result = find(board, word, x + 1, y,  next + 1);
			visited[x + 1][y] = false;
		}
		if (!result && y - 1 >= 0 && !visited[x][y-1] && board[x][y - 1] == word[next]) {
			visited[x][y - 1] = true;
			result =  find(board, word, x, y-1, next + 1);
			visited[x][y - 1] = false;
		}
		if (!result && y+1 < board[0].size()&&!visited[x][y+1] && board[x ][y+1] == word[next]) {
			visited[x][y + 1] = true;
			result =  find(board, word, x, y+1, next + 1);
			visited[x][y + 1] = false;
		}
		return result;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		bool result = false;
		visited.resize(board.size(), vector<bool>(board[0].size(), false));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					visited[i][j] = true;
					result = find(board, word, i, j, 1);
					visited[i][j] = false;
				}
				if (result)
					return true;
			}
		}
		return result;
	}
};