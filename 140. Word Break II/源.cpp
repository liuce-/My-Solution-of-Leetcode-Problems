//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, add spaces in s to construct a sentence where each word is a valid dictionary word.Return all such possible sentences.
//
//Note:
//
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.
//Example 1 :
//
//	Input :
//	s = "catsanddog"
//	wordDict = ["cat", "cats", "and", "sand", "dog"]
//	Output :
//	[
//		"cats and dog",
//		"cat sand dog"
//	]
//Example 2 :
//
//	Input :
//	s = "pineapplepenapple"
//	wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//	Output :
//	[
//		"pine apple pen apple",
//		"pineapple pen apple",
//		"pine applepen apple"
//	]
//Explanation : Note that you are allowed to reuse a dictionary word.
//	Example 3 :
//
//	Input :
//	s = "catsandog"
//	wordDict = ["cats", "dog", "sand", "and", "cat"]
//	Output :
//	[]
#include<vector>
using namespace std;
// Time Limit Exceeded
class Solution {
	vector<string> res;
	vector<vector<int>> comparasion;	
	void findall(string&s, int index, vector<string>& wordDict, string& prev) {
		if (index == s.size()) {
			res.push_back(prev.substr(1));
			return;
		}
		if (index > s.size())
			return;
		for (int i = 0; i < comparasion[index].size(); i++) {
			int tmp = prev.size();
			string &newWord = wordDict[comparasion[index][i]];
			prev = prev + " " + newWord;
			findall(s, index + newWord.size(), wordDict, prev);
			prev.resize(tmp);
		}	
	}
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (s.size() == 0)
			return res;
		comparasion.resize(s.size(), vector<int>());
		for (int i = 0; i < wordDict.size(); i++) {
			int pos = 0;
			while (pos<s.length()) {
				pos = s.find(wordDict[i], pos);
				if (pos == s.npos)
					break;
				else {
					comparasion[pos].push_back(i);
					pos++;
				}
			}
		}
		string tmp = "";
		findall(s, 0, wordDict, tmp);
		return res;
	}
};

// Memory Limit Exceeded
class Solution {
	vector < vector<string>> dp;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		dp.resize(s.size());
		if (s.size() == 0)
			return vector<string>();

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < wordDict.size(); j++) {
				int start = i - wordDict[j].size() + 1;
				if (start >= 0) {
					string tmp = s.substr(start, wordDict[j].size());
					if (tmp == wordDict[j]) {
						if (start - 1 >= 0) {
							for (int k = 0; k < dp[start - 1].size(); k++)
								dp[i].push_back(dp[start - 1][k] +" "+ tmp);
						}
						else
							dp[i].push_back(tmp);
					}
				}
			}
		}

		return dp.back();
	}
};

// Memory Limit Exceeded

class Solution {
	vector < vector<vector<int>>> dp;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		dp.resize(s.size());
		if (s.size() == 0)
			return vector<string>();
		int maxLength = 0;
		for (int i = 0; i < wordDict.size(); i++)
			maxLength = wordDict[i].size() > maxLength ? wordDict[i].size() : maxLength;

		for (int i = 0; i < s.size(); i++) {
			int release = (i - maxLength + 1) - 1 - 1;
			if (release >= 0)
				dp[release].clear();
			for (int j = 0; j < wordDict.size(); j++) {
				int start = i - wordDict[j].size() + 1;
				if (start >= 0) {
					string tmp = s.substr(start, wordDict[j].size());
					if (tmp == wordDict[j]) {
						if (start - 1 >= 0) {
							for (int k = 0; k < dp[start - 1].size(); k++) {
								vector<int> prev = dp[start - 1][k];
								prev.push_back(j);
								dp[i].push_back(prev);
							}
						}
						else
							dp[i].push_back({j});
					}
				}
			}
		}
		vector<string> ans;
		vector<vector<int>>& res = dp.back();
		for (int i = 0; i < res.size(); i++) {
			string tmp = wordDict[res[i][0]];
			for (int j = 1; j < res[i].size();j++) 				
				tmp += " "+wordDict[res[i][j]];
			ans.push_back(tmp);
		}
		return ans;
	}
};
//https://leetcode.com/problems/word-break-ii/discuss/128685/C++-minimal-solution-with-memoization
#include<unordered_map>
#include<unordered_set>
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict(wordDict.begin(), wordDict.end()); // for easy lookup
		unordered_map<size_t, vector<string>> cache; // memoization cache
		cache[s.length()] = { "" }; // base case
		return wordBreak(s, dict, 0UL, cache);
	}

	vector<string> wordBreak(string& s, unordered_set<string>& dict, size_t index, unordered_map<size_t, vector<string>>& cache) {
		vector<string> out;
		for (size_t i = index; i < s.length(); ++i) {
			string sub = s.substr(index, i - index + 1);
			if (dict.find(sub) != dict.end()) {
				bool found = (cache.find(i + 1) != cache.end());
				vector<string>& result = cache[i + 1];
				if (!found) {
					result = wordBreak(s, dict, i + 1, cache);
				}

				for (string& subsub : result) {
					out.emplace_back(sub + (subsub.length() ? (string(" ") + subsub) : ""));
				}
			}
		}
		return out;
	}
};

