//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//Example :
//
//	Consider the following matrix :
//
//[
//	[1, 4, 7, 11, 15],
//	[2, 5, 8, 12, 19],
//	[3, 6, 9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//Given target = 5, return true.
//
//Given target = 20, return false.
//
#include<vector>
using namespace std;

//slow, o(nlogm)
class Solution2 {
	bool search(vector<int>& row, int target) {
		int left = 0;
		int right = row.size();
		while (left < right) {
			int mid = (right + left) / 2;
			if (row[mid] == target)
				return true;
			else if (row[mid] > target)
				right = mid;
			else
				left = mid + 1;
		}
		return false;
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		bool res = false;
		for (int i = 0; !res && i < matrix.size(); i++)
			res = search(matrix[i], target);
		return res;
	}
};

//shoule be good, but the LeedCode result doesn't show that
class Solution {	
	bool search(vector<vector<int>>& matrix, int rowLeft, int rowRight, int colLeft, int colRight,int target) {//[rowleft,rowright) [colleft,colright)
		if (rowLeft >= rowRight || colLeft >= colRight||rowRight>matrix.size() || colRight>matrix[0].size())
			return false;
		int rowMid = (rowLeft + rowRight) / 2;
		int colMid = (colLeft + colRight) / 2;
		bool res = false;
		if (matrix[rowLeft][colLeft]==target || 
			(rowMid-1>=rowLeft && matrix[rowMid-1][colMid]==target)||
			(colMid+1<colRight&&matrix[rowLeft][colMid+1]==target)||
			(rowMid-1>=rowLeft&&matrix[rowMid-1][colRight-1]==target)||
			(rowMid+1<rowRight&&matrix[rowMid+1][colLeft]==target)||
			(colMid-1>=colLeft&&matrix[rowRight-1][colMid-1]==target)||
			(rowMid+1<rowRight&&matrix[rowMid+1][colMid]==target)||
			matrix[rowMid][colMid] == target || 
			matrix[rowRight-1][colRight-1]==target
			)
			return true;
		
		if (matrix[rowMid][colMid] > target && matrix[rowLeft][colLeft]<target) 
			res = search(matrix, rowLeft, rowMid, colLeft, colMid+1, target)|| search(matrix,rowMid,rowMid+1, colLeft,colMid,target);		
		if(!res && matrix[rowMid][colMid] < target && matrix[rowRight-1][colRight-1]>target)
			res = search(matrix, rowMid+1, rowRight, colMid, colRight, target)||search(matrix,rowMid,rowMid+1, colMid+1, colRight,target);		
		if (!res && colMid + 1<colRight && matrix[rowLeft][colMid + 1] < target && rowMid-1>=rowLeft && matrix[rowMid-1][colRight-1]>target)
			res = search(matrix, rowLeft, rowMid, colMid + 1, colRight, target);
		if (!res && rowMid + 1<rowRight && matrix[rowMid + 1][colLeft] < target  && colMid - 1>=colLeft&& matrix[rowRight-1][colMid-1]>target)
			res = search(matrix, rowMid + 1, rowRight, colLeft, colMid, target);

		return res;
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return 0;
		return search(matrix, 0, matrix.size(), 0, matrix[0].size(),target);
	}
};
//O(m+n)
//however, when the matrix is very tall of very long, which means that m>>n or n>>m, the algorithm is worse than a binary search
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int x = matrix.size() - 1;
		int y = 0;
		
		while (x >= 0 && y < matrix[0].size()) {
			if (matrix[x][y] == target)
				return true;
			else if (matrix[x][y] > target)
				x--;
			else
				y++;
		}
		return false;
	}
};
int main() {
	Solution s;
	vector<vector<int>>test{ { 1, 2, 3, 4, 5 },{ 6, 7, 8, 9, 10 },{ 11, 12, 13, 14, 15 },{ 16, 17, 18, 19, 20 },{ 21, 22, 23, 24, 25 } };


	auto res = s.searchMatrix(test, 15);
	return 0;
}
