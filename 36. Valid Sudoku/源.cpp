//Determine if a 9x9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :
//
//Each row must contain the digits 1 - 9 without repetition.
//Each column must contain the digits 1 - 9 without repetition.
//Each of the 9 3x3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
//
//A partially filled sudoku which is valid.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//Example 1:
//
//Input:
//[
//	["5", "3", ".", ".", "7", ".", ".", ".", "."],
//	["6", ".", ".", "1", "9", "5", ".", ".", "."],
//	[".", "9", "8", ".", ".", ".", ".", "6", "."],
//	["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//	["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//	["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//	[".", "6", ".", ".", ".", ".", "2", "8", "."],
//	[".", ".", ".", "4", "1", "9", ".", ".", "5"],
//	[".", ".", ".", ".", "8", ".", ".", "7", "9"]
//]
//Output: true
//	Example 2 :
//
//	Input :
//	[
//		["8", "3", ".", ".", "7", ".", ".", ".", "."],
//		["6", ".", ".", "1", "9", "5", ".", ".", "."],
//		[".", "9", "8", ".", ".", ".", ".", "6", "."],
//		["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//		["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//		["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//		[".", "6", ".", ".", ".", ".", "2", "8", "."],
//		[".", ".", ".", "4", "1", "9", ".", ".", "5"],
//		[".", ".", ".", ".", "8", ".", ".", "7", "9"]
//	]
//		Output: false
//			Explanation : Same as Example 1, except with the 5 in the top left corner being
//			modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//			Note :
//
//			A Sudoku board(partially filled) could be valid but is not necessarily solvable.
//			Only the filled cells need to be validated according to the mentioned rules.
//			The given board contain only digits 1 - 9 and the character '.'.
//			The given board size is always 9x9.
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<unordered_set<char>> row(9,unordered_set<char>());
		vector<unordered_set<char>> col(9, unordered_set<char>());
		vector<unordered_set<char>> box(9, unordered_set<char>());

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char c = board[i][j];
				if (c != '.') {
					if (row[i].find(c) == row[i].end())
						row[i].insert(c);
					else
						return false;
					if (col[j].find(c) == col[j].end())
						col[j].insert(c);
					else
						return false;
					int boxI = i / 3;
					int boxJ = j / 3;
					int index = boxI * 3 + boxJ;
					if (box[index].find(c) == box[index].end())
						box[index].insert(c);
					else
						return false;
				}
			}			
		}
		return true;
	}
};