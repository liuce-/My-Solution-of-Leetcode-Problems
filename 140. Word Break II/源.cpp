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
//TLE
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


class Solution {
	vector<string> res;
	vector<vector<int>> comparasion;
	
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

		return res;
	}
};

