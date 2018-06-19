//In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
//
//For now, suppose you are a dominator of m 0s and n 1s respectively.On the other hand, there is an array with strings consisting of only 0s and 1s.
//
//Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s.Each 0 and 1 can be used at most once.
//
//Note:
//The given numbers of 0s and 1s will both not exceed 100
//The size of given string array won't exceed 600.
//Example 1 :
//	Input : Array = { "10", "0001", "111001", "1", "0" }, m = 5, n = 3
//	Output : 4
//
//	Explanation : This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are ¡°10, ¡±0001¡±, ¡±1¡±, ¡±0¡±
//	Example 2 :
//	Input : Array = { "10", "0", "1" }, m = 1, n = 1
//	Output : 2
//
//	Explanation : You could form "10", but then you'd have nothing left. Better form "0" and "1".
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
	vector<vector<vector<int>>> result;
	int zeroCount(string& str) {
		int count = 0;
		for (char c : str) {
			if (c == '0')
				count++;
		}
		return count;
	}
	int oneCount(string& str) {
		int count = 0;
		for (char c : str) {
			if (c == '1')
				count++;
		}
		return count;
	}
	int helper(vector<string>& strs, int start, int m, int n) {
		if (m < 0 || n < 0)
			return -INT_MAX;

		if (start >= strs.size()) {
			return 0;
		}

		if (m == 0 && n == 0)
			return result[start][m][n] = 0;
		

		if (result[start][m][n] != -1)
			return result[start][m][n];

		return result[start][m][n] = max(helper(strs, start + 1, m, n), 1 + helper(strs, start + 1, m - zeroCount(strs[start]), n - oneCount(strs[start])));

		
	}
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.size() == 0)
			return 0;

		result.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1,-1)));
		return helper(strs, 0, m, n);
	}
};

class Solution2 {
	vector<vector<int>> result;
	int countChr(string& str,char target) {
		int count = 0;
		for (char c : str) {
			if (c == target)
				count++;
		}
		return count;
	}
	
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		result.resize(m+1, vector<int>(n+1, 0));
		
		//init
		int zero = countChr(strs[0],'0');
		int one = countChr(strs[0], '1');
		for (int i = 0; i < m+1; i++) {
			for (int j = 0; j < n+1; j++) {
				if (i >= zero && j >= one) {
					result[i][j] = 1;
				}
				else {
					result[i][j] = 0;
				}
			}
		}
		//dp
		for (int index = 1; index < strs.size(); index++) {
			int one = countChr(strs[index], '1');
			int zero = countChr(strs[index], '0');

			for (int i = m; i >= zero; i--) {
				for (int j = n; j >=one ; j--) {
					result[i][j] = max(result[i][j], 1 + result[i-zero][j-one]);
				}
			}
		}
		return result[m][n];


	}
};