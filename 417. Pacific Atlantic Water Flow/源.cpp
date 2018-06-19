//Given an m x n matrix of non - negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
//Water can only flow in four directions(up, down, left, or right) from a cell to another one with height equal or lower.
//
//Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
//Note:
//The order of returned grid coordinates does not matter.
//Both m and n are less than 150.
//Example :
//
//	Given the following 5x5 matrix :
//
//Pacific ~~~~~
//~1   2   2   3  (5) *
//~3   2   3  (4) (4) *
//~2   4  (5)  3   1 *
//~(6) (7)  1   4   5 *
//~(5)  1   1   2   4 *
//*   *   *   *   * Atlantic
//
//Return :
//
//[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]](positions with parentheses in above matrix).
#include<vector>
#include<utility>
using namespace std;

class Solution {
	vector<vector<bool>> pacificVisited;
	vector<vector<bool>> atlanticVisited;
	vector<pair<int, int>> location;
	enum Water{ Pacific,Atlantic };
	int row = 0;
	int column = 0;
	vector<vector<int>> direction = { {0,1},{0,-1},{1,0},{-1,0} };
	bool isInAera(int x, int y) {
		return x >= 0 && x < row&&y >= 0 && y < column;
	}
	void waterFlowUp(int x, int y, Water water, vector<vector<int>>& matrix) {
		if (water == Atlantic)
			atlanticVisited[x][y] = true;
		else
			pacificVisited[x][y] = true;
		for (int i = 0; i < direction.size(); i++) {
			int newx = x + direction[i][0];
			int newy = y + direction[i][1];
			if (isInAera(newx, newy)) {
				bool isVisited = water == Atlantic ? atlanticVisited[newx][newy] : pacificVisited[newx][newy];
				if ( !isVisited && matrix[newx][newy] >= matrix[x][y]) {
					waterFlowUp(newx, newy, water, matrix);
				}
			}
		}
	}
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		row = matrix.size();
		if (row == 0)
			return location;
		column = matrix[0].size();
		pacificVisited.resize(row, vector < bool>(column, false));
		atlanticVisited.resize(row, vector<bool>(column, false));
		//pacific
		for (int i = 0; i < column; i++) {
			if (!pacificVisited[0][i]) {
				waterFlowUp(0, i, Pacific, matrix);
			}
		}
		for (int i = 1; i < row; i++) {
			if (!pacificVisited[i][0]) {
				waterFlowUp(i, 0, Pacific, matrix);
			}
		}
		//atlantic
		for (int i = 0; i < column; i++) {
			if (!atlanticVisited[row - 1][i]) {
				waterFlowUp(row-1, i, Atlantic, matrix);
			}
		}
		for (int i = 0; i < row; i++) {
			if (!atlanticVisited[i][column - 1]) {
				waterFlowUp(i, column - 1, Atlantic, matrix);
			}
		}
		//find the intersection 
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (atlanticVisited[i][j] && pacificVisited[i][j])
					location.push_back(make_pair(i, j));
			}
		}
		return location;
	}
};
int main() {
	vector<vector<int>> matrix = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
	Solution s;
	s.pacificAtlantic(matrix);
	return 0;
}