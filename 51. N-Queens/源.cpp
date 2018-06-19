//The n - queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
//
//
//
//Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//Example:
//
//Input: 4
//	Output : [
//				 [".Q..",  // Solution 1
//					 "...Q",
//					 "Q...",
//					 "..Q."],
//
//					 ["..Q.",  // Solution 2
//					 "Q...",
//					 "...Q",
//					 ".Q.."]
//			 ]
//	Explanation: There exist two distinct solutions to the 4 - queens puzzle as shown above.
#include<vector>
#include<string>
using namespace std;
class Solution {
	vector<vector<bool>> mark;
	vector<vector<string>> result;
	vector<string> currentTry;
	void tryPutQueens(int currentRow, int n) {
		if (currentRow >= n) {
			result.push_back(currentTry);
			return;
		}
		for (int j = 0; j < n; j++) {
			if (mark[0][j] || mark[1][currentRow + j] || mark[2][currentRow - j + n - 1])
				continue;
			else {
				mark[0][j] = mark[1][currentRow + j] = mark[2][currentRow - j + n - 1] = true;
				currentTry[currentRow][j] = 'Q';
				tryPutQueens(currentRow + 1, n);
				mark[0][j] = mark[1][currentRow + j] = mark[2][currentRow - j + n - 1] = false;
				currentTry[currentRow][j] = '.';
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		if (n >= 1) {
			mark.resize(3);
			mark[0].resize(n, false);//i
			mark[1].resize(2 * n - 1, false);//i+j	
			mark[2].resize(2 * n - 1, false);//i-j+n-1
			currentTry.resize(n, string(n, '.'));
			tryPutQueens(0, n);
		}
		return result;
	}
};