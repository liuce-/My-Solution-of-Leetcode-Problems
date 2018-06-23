//Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//Example:
//
//Input: 3
//	Output :
//	[
//		[1, 2, 3],
//		[8, 9, 4],
//		[7, 6, 5]
//	]
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<pair<int, int>> direction = { make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0) };
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int count = 1;
		int x = 0;
		int y = 0;		
		int currentDirection = 0;
		while (count <= n*n) {
			matrix[x][y] = count++;
			int tmpX = x + direction[currentDirection].first;
			int tmpY = y + direction[currentDirection].second;
			if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= n || matrix[tmpX][tmpY] != 0)
				currentDirection = (currentDirection + 1) % 4;
			x = x + direction[currentDirection].first;
			y = y + direction[currentDirection].second;
		}

		return matrix;
		
	}
};