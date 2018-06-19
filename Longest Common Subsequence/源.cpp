//Description
//Given two strings, find the longest common subsequence(LCS).
//
//Your code should return the length of LCS.
//
//Example
//For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
//
//For "ABCD" and "EACB", the LCS is "AC", return 2.
//

/*LCS(m,n)=		LCS(m-1,n-1)+1					if stringA[m]==stringB[n]
				max( LCS(m-1,n),LCS(m,n-1) )	if stringA[m]!=stringB[n]
*/

#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//递归，记忆化搜索
class Solution {
	vector<vector<int>> result;
public:
	/**
	* @param A: A string
	* @param B: A string
	* @return: The length of longest common subsequence of A and B
	*/
	int LCS(string& A, int a, string&B, int b) {
		if (a < 0 || b < 0)
			return 0;
		if (result[a][b] != -1)
			return result[a][b];
		
		if (A[a] == B[b])
			return result[a][b]=1+LCS(A, a - 1, B, b - 1);
		else {
			return result[a][b] = max(LCS(A,a-1,B,b), LCS(A,a,B,b-1));
		}
	}
	int longestCommonSubsequence(string &A, string &B) {
		int sizeofA = A.size();
		int sizeofB = B.size();
		if (sizeofA == 0 || sizeofB == 0) {
			return 0;
		}
		result.resize(sizeofA, vector<int>(sizeofB, -1));

		return LCS(A, sizeofA-1, B, sizeofB-1);
	}
};

//动态规划
class Solution2 {
	vector<vector<int>> result;
public:
	/**
	* @param A: A string
	* @param B: A string
	* @return: The length of longest common subsequence of A and B
	*/
	int longestCommonSubsequence(string &A, string &B) {
		int sizeofA = A.size();
		int sizeofB = B.size();
		if (sizeofA == 0 || sizeofB == 0) {
			return 0;
		}
		result.resize(sizeofA, vector<int>(sizeofB, -1));

		for (int i = 0; i < sizeofA; i++) {
			for (int j = 0; j < sizeofB; j++) {
				if (A[i] == B[j]) {
					result[i][j] = i == 0 ? 1 : (j == 0 ? 1 : result[i - 1][j - 1] + 1);
				}
				else {
					result[i][j] = max(i == 0 ? 0 : result[i - 1][j], j == 0 ? 0 : result[i][j - 1]);
				}
			}
		}
		return result[sizeofA - 1][sizeofB - 1];

	}
};