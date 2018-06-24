//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//Example 1 :
//
//	Input :
//	matrix = [
//		[1, 3, 5, 7],
//			[10, 11, 16, 20],
//			[23, 30, 34, 50]
//	]
//	target = 3
//		Output: true
//		Example 2 :
//
//		Input :
//		matrix = [
//			[1, 3, 5, 7],
//				[10, 11, 16, 20],
//				[23, 30, 34, 50]
//		]
//		target = 13
//			Output: false
#include<vector>
using namespace std;
//recursive
class Solution {
	bool search(vector<vector<int>>& matrix, int target,int left, int right) {//[left,right)
		if (left>=right)
			return false;
		int mid = (left + right) / 2;
		int x = mid / matrix[0].size();
		int y = mid % matrix[0].size();
		if (matrix[x][y] == target)
			return true;
		else if (matrix[x][y] > target)
			return search(matrix, target, left, mid);
		else
			return search(matrix, target, mid + 1, right);
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		return search(matrix, target,0,matrix.size()*matrix[0].size());
	}
};
//iteration
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int left = 0;
		int right = matrix.size()*matrix[0].size();
		while (left < right) {
			int mid = (left + right) / 2;
			int x = mid / matrix[0].size();
			int y = mid % matrix[0].size();
			if (matrix[x][y] == target)
				return true;
			else if (matrix[x][y] > target)
				right = mid;
			else
				left = mid + 1;	
			
		}
		return false;
	}
};