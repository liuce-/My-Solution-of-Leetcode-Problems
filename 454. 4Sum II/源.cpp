//Given four lists A, B, C, D of integer values, compute how many tuples(i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
//
//To make problem a bit easier, all A, B, C, D have same length of N where 0 ¡Ü N ¡Ü 500. All integers are in the range of - 228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
//
//Example:
//
//Input:
//A = [1, 2]
//B = [-2, -1]
//C = [-1, 2]
//D = [0, 2]
//
//Output :
//	2
//
//	Explanation :
//	The two tuples are :
//1. (0, 0, 0, 1)->A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0)->A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
//Time Limit Execeeded, O(n^3) time, O(n) space
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		if (A.size() == 0)
			return 0;
		int result = 0;
		unordered_map<int,int> setOfD;
		for (auto i : D) 
			setOfD[i]++;
		
		for (auto i : A) 
			for (auto j : B) 
				for (auto k : C) {
					int sum = i + j + k;
					if (setOfD.find(-sum) != setOfD.end())
						result+=setOfD.find(-sum)->second;
				}
		return result;
		
	}
};
//accepted, time O(n^2), space O(n^3)
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		if (A.size() == 0)
			return 0;
		int result = 0;
		
		unordered_map<int, int> C_Plus_D;
		for (auto i : D)
			for (auto j : C)
				C_Plus_D[i + j]++;

		for (auto i : A)
			for (auto j : B) {
				int sum = i + j;
				if (C_Plus_D.find(-sum) != C_Plus_D.end())
					result += C_Plus_D.find(-sum)->second;
			}				
		return result;
	}
};