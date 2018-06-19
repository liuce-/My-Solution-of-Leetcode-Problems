//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//A sudoku solution must satisfy all of the following rules :
//
//Each of the digits 1 - 9 must occur exactly once in each row.
//Each of the digits 1 - 9 must occur exactly once in each column.
//Each of the the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.
//Empty cells are indicated by the character '.'.
//
//
//A sudoku puzzle...
//
//
//...and its solution numbers marked in red.
//
//Note:
//
//The given board contain only digits 1 - 9 and the character '.'.
//You may assume that the given Sudoku puzzle will have a single unique solution.
//The given board size is always 9x9.
#include<vector>
#include<iostream>
using namespace std;
class Solution {
	vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(10, false));
	vector<vector<bool>> column = vector<vector<bool>>(9, vector<bool>(10, false));
	vector<vector<vector<bool>>> box = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));
	vector<pair<int, int>> coordinate;
	
	bool solve(vector<vector<char>>& board, int index) {
		if (index < coordinate.size()) {
			int x = coordinate[index].first;
			int y = coordinate[index].second;
			for (int i = 1; i < 10; i++) {
				if (!row[x][i] && !column[y][i] && !box[x / 3][y / 3][i]) {
					board[x][y] = i + '0';
					row[x][i] = column[y][i] = box[x / 3][y / 3][i] = true;
					bool result = solve(board, index+1);
					if (result)
						return true;
					row[x][i] = column[y][i] = box[x / 3][y / 3][i] = false;
					board[x][y] = '.';
				}
			}
			return false;
		}
		//cout << "finally have one correct answer" << endl;
		return true;

	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					row[i][board[i][j] - '0'] = true;
					column[j][board[i][j] - '0'] = true;
					box[i / 3][j / 3][board[i][j] - '0'] = true;
				}
				else {
					coordinate.push_back(make_pair(i, j));
				}
			}
		}
		solve(board, 0);
		return;
	}
};