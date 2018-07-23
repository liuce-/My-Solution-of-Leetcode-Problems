//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.You may assume that each word will contain only lower case letters.If no such two words exist, return 0.
//
//Example 1:
//
//Input: ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//	Output : 16
//	Explanation : The two words can be "abcw", "xtfn".
//	Example 2 :
//
//	Input : ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//	Output : 4
//	Explanation : The two words can be "ab", "cd".
//	Example 3 :
//
//	Input : ["a", "aa", "aaa", "aaaa"]
//	Output : 0
//	Explanation : No such pair of words.
#include<vector>
#include<unordered_set>
#include<string>	
#include<algorithm>
using namespace std;
//o(n^2*words.length())
class Solution {
	bool hasCommenLetters(int a, int b, vector<unordered_set<char>>& sets) {
		for (char c : sets[a]) {
			if (sets[b].find(c) != sets[b].end()) {
				return true;
			}
		}
		return false;

	}
public:
	int maxProduct(vector<string>& words) {
		
		vector<unordered_set<char>> sets(words.size(),unordered_set<char>());
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++)
				sets[i].insert(words[i][j]);
		}
		unsigned ans = 0;
		for (int i = 0; i < words.size(); i++) {
			for (int j = i+1; j < words.size(); j++) {
				if (!hasCommenLetters(i, j, sets)) 
					ans = max(ans, (unsigned)words[i].length()*words[j].length());
				
			}
		}
		
		return ans;
		

	}
};
//o(n^2)
class Solution {
public:
	int maxProduct(vector<string>& words) {
		int res = 0;
		vector<int> mask(words.size(), 0);
		for (int i = 0; i < words.size(); ++i) {
			for (char c : words[i]) {
				mask[i] |= 1 << (c - 'a');
			}
			for (int j = 0; j < i; ++j) {
				if (!(mask[i] & mask[j])) {
					res = max(res, int(words[i].size() * words[j].size()));
				}
			}
		}
		return res;
	}
};
