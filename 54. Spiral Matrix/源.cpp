//Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
//
//Example 1:
//
//Input:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//Output : [1, 2, 3, 6, 9, 8, 7, 4, 5]
//	Example 2 :
//
//	Input :
//	[
//		[1, 2, 3, 4],
//		[5, 6, 7, 8],
//		[9, 10, 11, 12]
//	]
//		 Output : [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		vector<pair<int, int>> direction = { make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0) };
		if (matrix.size() == 0)
			return res;
		int column = matrix[0].size();
		int row = matrix.size();		
		int x = 0;
		int y = 0;
		int index = 0;
		res.resize(row*column);
		int curDirection=0;
		while (index<res.size()) {
			res[index] = matrix[x][y];
			matrix[x][y] = INT_MIN;
			int tmpx = x + direction[curDirection].first;
			int tmpy = y + direction[curDirection].second;
			if (tmpx<0 || tmpx>=row || tmpy<0|| tmpy>=column || matrix[tmpx][tmpy]==INT_MIN )
				curDirection = (curDirection + 1) % 4;
			x = x + direction[curDirection].first;
			y = y + direction[curDirection].second;
			index++;
		}
		return res;
	}
};