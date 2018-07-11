//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//Example:
//
//Input:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output : 4
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		int res = 0;
		//{square, left, top}
		vector<vector<vector<int>>> dp(matrix.size() + 1, vector<vector<int>>(matrix[0].size() + 1, vector<int>(3, 0)));
		for (int i = 1; i < dp.size(); i++) {
			for (int j = 1; j < dp[0].size(); j++) {
				if (matrix[i - 1][j - 1] == '1') {
					dp[i][j][1] = dp[i][j - 1][1] + 1;
					dp[i][j][2] = dp[i - 1][j][2] + 1;
					dp[i][j][0] = min(dp[i-1][j-1][0]+1,min(dp[i][j][1], dp[i][j][2]));
					res = max(res, dp[i][j][0]);
				}
			}
		}
		return res*res;
	}
};