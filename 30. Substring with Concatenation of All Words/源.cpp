//You are given a string, s, and a list of words, words, that are all of the same length.Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//Example 1:
//
//Input:
//s = "barfoothefoobarman",
//words = ["foo", "bar"]
//Output : [0, 9]
//	Explanation : Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
//	The output order does not matter, returning[9, 0] is fine too.
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//brutal force
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (words.size() == 0 || s.size() == 0)
			return res;
		int totalLength = 0;
		int wordLength = words[0].size();
		totalLength = words[0].size()*words.size();
		if (s.size() < totalLength)
			return res;

		unordered_map<string, vector<int>> map;
		for (int i = 0; i < words.size(); i++)
			map[words[i]].push_back(i);			
		for (int i = 0; i < s.size() - totalLength + 1; i++) {
			string sub = s.substr(i, wordLength);
			if (map.find(sub) != map.end()) {
				vector<bool> used(words.size(), false);
				used[map[sub][0]] = true;
				int j = 1;
				for (;j < words.size(); j++) {
					string tmp = s.substr(i + j * wordLength, wordLength);
					if (map.find(tmp) != map.end()) {
						vector<int>& v = map[tmp];
						int k = 0;
						for (; k < v.size();k++) {
							if (!used[v[k]]) {
								used[v[k]] = true;
								break;
							}
						}
						if (k == v.size()) {
							break;
						}
					}
					else
						break;
				}
				if (j == words.size())
					res.push_back(i);
			}
		}
		return res;		
	}
};
//brutal force
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (words.size() == 0 || s.size() == 0)
			return res;
		int totalLength = 0;
		int wordLength = words[0].size();
		totalLength = words[0].size()*words.size();
		if (s.size() < totalLength)
			return res;
		unordered_map<string, int> target;
		for (int i = 0; i < words.size(); i++)
			target[words[i]]++;
		for (int i = totalLength-1; i < s.size(); i++) {
			unordered_map<string, int> map;
			string sub = s.substr(i - totalLength + 1, totalLength);
			for (int j = 0; j < words.size(); j++) {
				string tmp = sub.substr(j * words[0].size(), words[0].size());
				map[tmp]++;
			}
			if (map == target)
				res.push_back(i - totalLength + 1);

		}
		return res;
		
	}
};

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.size() == 0 || words.size() == 0)
			return res;
		int wordLength = words[0].size();
		int totalLength = words.size()*wordLength;
		if (s.size() < totalLength)
			return res;

		unordered_map<string, int> target;
		for (int i = 0; i < words.size(); i++)
			target[words[i]]++;

		for (int i = 0; i < wordLength; i++) {
			unordered_map<string, int> map;
			int count = 0;
			int left = i;
			for (int j = i; j < s.size() - wordLength + 1; j+=wordLength) {
				string sub = s.substr(j, wordLength);
				if (target.find(sub) == target.end()) {//clear all, discard the previous substring
					map.clear();
					left = j + wordLength;
					count = 0;
				}
				else {
					map[sub]++;
					count++;
					if (map[sub] <= target[sub]) { // it's a valid substring
						if (count == words.size()) {//found a match
							res.push_back(left);
							string tmp = s.substr(left, wordLength);
							map[tmp]--;
							count--;
							left = left + wordLength;
						}

					}
					else {//have a excessive sub in current string, remove the left words till the map[sub]==target[sub]
						while (map[sub] > target[sub]) {
							string tmp = s.substr(left, wordLength);
							map[tmp]--;
							count--;
							left = left + wordLength;
						}
					}
				}
			}
		}
		return res;
	}
};