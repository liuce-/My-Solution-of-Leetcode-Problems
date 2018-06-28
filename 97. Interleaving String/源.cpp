//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//Example 1:
//
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//	Output : true
//	Example 2 :
//
//	Input : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//	Output : false
#include<string>

using namespace std;
//Time Limted exceeded.
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		if (s1.size() == 0 && s2 != s3)
			return false;
		if (s2.size() == 0 && s1 != s3)
			return false;

		int s1Index = 0;
		int s2Index = 0;
		for (int i = 0; i < s3.size(); i++) {
			if (s3[i] == s1[s1Index] && s3[i] != s2[s2Index])
				s1Index++;
			else if (s3[i] == s2[s2Index] && s3[i] != s1[s1Index])
				s2Index++;
			else if (s3[i] != s2[s2Index] && s3[i] != s1[s1Index])
				return false;
			else {
				return isInterleave(s1.substr(s1Index), s2.substr(s2Index + 1), s3.substr(i+1))
					|| isInterleave(s1.substr(s1Index+1), s2.substr(s2Index), s3.substr(i + 1));
			}
		}
		return true;
	}
};

//dp[i][j]	= dp[i-1]dp[j] if(s1[i]==s3[i+j+1]] && s2[j]!=s3[i+j+1]])
//			= dp[j-1]dp[i] if(s2[j]==s3[i+j+1]] && s1[i]!=s3[i+j+1]])
//			= false	if(s2[j]!=s3[i+j+1]] && s1[i]!=s3[i+j+1]])
//			= dp[i-1]dp[j]||	dp[j-1]dp[i]		if(s1[i]=s2[j]=s3[i+j+1]])
#include<vector>
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;

		vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1,false));
		dp[0][0] = true;
		for (int i = 1; i <= s1.size(); i++) {
			if (s1[i - 1] == s3[i - 1])
				dp[i][0] = dp[i - 1][0];
			else 
				break;			
		}
		for (int i = 1; i <= s2.size(); i++) {
			if (s2[i - 1] == s3[i - 1])
				dp[0][i] = dp[0][i-1];
			else 
				break;
		}
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				if (s1[i-1] == s3[i + j-1] && s2[j-1] != s3[i + j - 1])
					dp[i][j] = dp[i - 1][j];
				else if (s2[j-1] == s3[i + j - 1] && s1[i-1] != s3[i + j - 1])
					dp[i][j] = dp[i][j - 1];
				else if (s2[j-1] != s3[i + j - 1] && s1[i-1] != s3[i + j - 1])
					dp[i][j] = false;
				else
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			}
		}
		return dp.back().back();

	}
};