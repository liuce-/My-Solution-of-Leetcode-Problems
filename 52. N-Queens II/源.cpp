//
//The n - queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
//
//
//
//Given an integer n, return the number of distinct solutions to the n - queens puzzle.
//
//Example:
//
//Input: 4
//	Output : 2
//	Explanation : There are two distinct solutions to the 4 - queens puzzle as shown below.
//	[
//		[".Q..",  // Solution 1
//		"...Q",
//		"Q...",
//		"..Q."],
//
//		["..Q.",  // Solution 2
//		"Q...",
//		"...Q",
//		".Q.."]
//	]
#include<vector>
#include<string>
using namespace std;
class Solution {
	vector<vector<bool>> mark;
	int result=0;
	void tryPutQueens(int currentRow, int n) {
		if (currentRow >= n) {
			result++;
			return;
		}
		for (int j = 0; j < n; j++) {
			if (mark[0][j] || mark[1][currentRow + j] || mark[2][currentRow - j + n - 1])
				continue;
			else {
				mark[0][j] = mark[1][currentRow + j] = mark[2][currentRow - j + n - 1] = true;
				tryPutQueens(currentRow + 1, n);
				mark[0][j] = mark[1][currentRow + j] = mark[2][currentRow - j + n - 1] = false;
			}
		}
	}
public:
	int totalNQueens(int n) {
		if (n >= 1) {
			mark.resize(3);
			mark[0].resize(n, false);//i
			mark[1].resize(2 * n - 1, false);//i+j	
			mark[2].resize(2 * n - 1, false);//i-j+n-1
			tryPutQueens(0, n);
		}
		return result;
	}
};
