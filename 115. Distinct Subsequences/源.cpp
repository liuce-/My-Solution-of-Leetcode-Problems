//Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Example 1:
//
//Input: S = "rabbbit", T = "rabbit"
//	Output : 3
//	Explanation :
//
//	As shown below, there are 3 ways you can generate "rabbit" from S.
//	(The caret symbol ^ means the chosen letters)
//
//	rabbbit
//	^^^^ ^^
//	rabbbit
//	^^ ^^^^
//	rabbbit
//	^^^ ^^^
//	Example 2:
//
//   Input: S = "babgbag", T = "bag"
//	   Output : 5
//	   Explanation :
//
//	   As shown below, there are 5 ways you can generate "bag" from S.
//	   (The caret symbol ^ means the chosen letters)
//
//	   babgbag
//	   ^^ ^
//	   babgbag
//	   ^^    ^
//	   babgbag
//	   ^    ^^
//	   babgbag
//	   ^  ^^
//	   babgbag
//	   ^^^
#include<string>
#include<vector>
using namespace std;
//f(i,j)=f(i-1,j-1)+f(i-1,j) //if s[i-1]==t[j-1]    i,j is the length of str.(starting from the left
//		=f(i-1,j)			//if s[i-1]!=t[j-1]
//      =1					//if j==0
class Solution {
public:
	int numDistinct(string s, string t) {
		vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
		for (int i = 0; i <= s.size(); i++)
			dp[i][0] = 1;

		for(int i=1;i<=s.size();i++)
			for (int j = 1; j <= t.size(); j++) {
				dp[i][j] = dp[i - 1][j];
				if (s[i-1] == t[j-1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		return dp.back().back();
	}
};