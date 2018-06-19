//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//

//solution:
//o(n) space,n is number of row, o(j) time, j is number of int in the triangle
//f(i,j)=value(i,j)+min( f(i+1,j), f(i+1,j+1) )
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		if (row < 1) {

		}
		vector<int> result(row+1,0);

		for (int i = row-1 ; i >= 0; i--) {
			int column = triangle[i].size();
			
			for (int j = 0; j < column; j++) {
				result[j] = min(result[j], result[j + 1])+triangle[i][j];
			}
		}
		return result[0];
		
	}
};