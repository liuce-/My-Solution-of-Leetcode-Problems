//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//	Output : 1
//	Explanation : The palindrome partitioning["aa", "b"] could be produced using 1 cut.
#include<string>
#include<vector>	
#include<algorithm>
using namespace std;

//o(n^2)
class Solution {
public:
	int minCut(string s) {
		vector<vector<bool>> palindromeDP(s.size(), vector<bool>(s.size(), true));
		
		for (int i = 0; i < s.size(); i++)
			palindromeDP[i][i] = 1;
		for (int i = 1; i < s.size(); i++) 
			for (int j = 0; j < s.size() - i;j++) 
				palindromeDP[j][i + j] = s[j] == s[i + j] && palindromeDP[j + 1][i + j - 1];

		vector<int> partitionDP(s.size(),0);
		for (int i = s.size()-1; i >= 0; i--) {
			if (palindromeDP[i][s.size()-1])
				partitionDP[i] = 0;
			else {
				int ans = INT_MAX;
				for (int k = i; k < s.size(); k++) 
					if (palindromeDP[i][k]) 
						ans = min(ans, 1 + partitionDP[k + 1]);			
				partitionDP[i] = ans;
			}
		}
		return partitionDP.size()==0?0: partitionDP[0];
	}
};