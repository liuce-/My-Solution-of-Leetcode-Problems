//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, determine if s can be segmented into a space - separated sequence of one or more dictionary words.
//
//Note:
//
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.
//Example 1 :
//
//	Input : s = "leetcode", wordDict = ["leet", "code"]
//	Output : true
//	Explanation : Return true because "leetcode" can be segmented as "leet code".
//	Example 2 :
//
//	Input : s = "applepenapple", wordDict = ["apple", "pen"]
//	Output : true
//	Explanation : Return true because "applepenapple" can be segmented as "apple pen apple".
//	Note that you are allowed to reuse a dictionary word.
//	Example 3 :
//
//	Input : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//	Output : false
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
	vector<vector<int>> comparison;
	vector<bool> result;
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int length = s.size();
		int dictSize = wordDict.size();
		//init comparison
		comparison.resize(length);
		for (int j = 0; j < dictSize; j++) {
			int k = 0;
			while (k < length) {
				k = s.find(wordDict[j], k);
				if (k == s.npos)
					break;
				else {
					comparison[k].push_back(j);
					k++;
				}
			}
		}
		result.resize(length,false);
		result[length-1] = comparison[length - 1].size() != 0;
		//dp
		for (int i = length-2; i >=0; i--) {
			for (int j = 0; j < comparison[i].size(); j++) {
				int temp = comparison[i][j];
				int index = i + wordDict[temp].size();
				if (index != result.size()) {
					result[i] = result[i] || result[index];
				}
				else
					result[i] = true;
			}
		}
		return result[0];

		
	}
};
int main() {
	Solution s;
	string str = { "cars" };
	vector<string> wordDict = { "car","ca","rs" };
	cout<<s.wordBreak(str, wordDict);
	return 0;
}