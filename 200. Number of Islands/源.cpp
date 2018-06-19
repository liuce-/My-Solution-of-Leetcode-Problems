//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//Input:
//11110
//11010
//11000
//00000
//
//Output : 1
//	Example 2 :
//
//	Input :
//	11000
//	11000
//	00100
//	00011
//
//	Output : 3
#include<vector>

using namespace std;
class Solution {
	int row;
	int column;
	vector<vector<bool>> visited;
	vector<vector<int>> direction = { {-1,0},{0,-1},{1,0},{0,1} };
	bool isInArea(int x, int y) {
		return x >= 0 && x < row && y >= 0 && y < column;		
	}
	void search(int x, int y, vector<vector<char>>& grid) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nextx = x + direction[i][0];
			int nexty = y + direction[i][1];
			if (isInArea(nextx, nexty) && !visited[nextx][nexty] && grid[nextx][nexty]=='1') {
				search(nextx, nexty, grid);
			}
		}
		return;
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int island = 0;
		row = grid.size();
		
		if(row !=0)
			column = grid[0].size();

		if (column != 0) {
			visited.resize(row, vector<bool>(column, false));
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					if (grid[i][j] == '1' && !visited[i][j]) {
						search(i, j, grid);
						island++;
					}
				}
			}
		}
		return island;
	}
};