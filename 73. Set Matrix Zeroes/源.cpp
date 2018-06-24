//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in - place.
//
//Example 1:
//
//Input:
//[
//	[1, 1, 1],
//	[1, 0, 1],
//	[1, 1, 1]
//]
//Output :
//	[
//		[1, 0, 1],
//		[0, 0, 0],
//		[1, 0, 1]
//	]
//	   Example 2:
//
//   Input:
//	   [
//		   [0, 1, 2, 0],
//		   [3, 4, 5, 2],
//		   [1, 3, 1, 5]
//	   ]
//	   Output :
//		   [
//			   [0, 0, 0, 0],
//			   [0, 4, 5, 0],
//			   [0, 3, 1, 0]
//		   ]
//			  Follow up :
//
//			  A straight forward solution using O(mn) space is probably a bad idea.
//				  A simple improvement uses O(m + n) space, but still not the best solution.
//				  Could you devise a constant space solution ?
#include<vector>
using namespace std;
//O(m+n)space
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return;
		vector<bool> row(matrix.size(), false);
		vector<bool> column(matrix[0].size(), false);
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0)
					column[j]=row[i] = true;
			}
		}
		for (int i = 0; i < row.size();i++) {
			if(row[i])
				for (int j = 0; j < matrix[0].size(); j++)
					matrix[i][j] = 0;
		}
		for (int j = 0; j < column.size(); j++)
			if (column[j])
				for (int i = 0; i < matrix.size(); i++)
					matrix[i][j] = 0;
	}
};
//constant space
class Solution2 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return;
		bool col0 = false;
		bool row0 = false;
		for (int i = 0; i < matrix.size(); i++)
			if (matrix[i][0] == 0) {
				col0 = true;
				break;
			}
		for (int i = 0; i < matrix[0].size(); i++)
			if (matrix[0][i] == 0) {
				row0 = true;
				break;
			}

		for (int i = 1; i < matrix.size(); i++)
			for (int j = 1; j < matrix[0].size(); j++)
				if (matrix[i][j] == 0)
					matrix[0][j] = matrix[i][0] = 0;
		for (int i = 1; i < matrix.size(); i++) 
			for (int j = 1; j < matrix[0].size(); j++) 
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			
		
		if (col0)
			for (int i = 0; i < matrix.size(); i++)
				matrix[i][0] = 0;
		if (row0)
			for (int i = 0; i < matrix[0].size(); i++)
				matrix[0][i] = 0;
	}
};
int main() {
	Solution2 s;
	vector<vector<int>> test{{ -1,2,3 }};
	s.setZeroes(test);
	return 0;
}