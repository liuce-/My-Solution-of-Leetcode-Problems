//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?
//
//Note : m and n will be at most 100.
//


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		int** result=new int*[m];
		for (int i = 0; i < m; i++)
			result[i] = new int[n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0) {
					result[i][j] = 1;
					continue;
				}
				if (j == 0) {
					result[i][j] = 1;
					continue;
				}
				result[i][j] = result[i][j - 1] + result[i - 1][j];

			}
		}
		return result[m-1][n-1];

	}
};