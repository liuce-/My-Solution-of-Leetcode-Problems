//Given a string s and a non - empty string p, find all the start indices of p's anagrams in s.
//
//Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20, 100.
//
//The order of output does not matter.
//
//Example 1:
//
//Input:
//s: "cbaebabacd" p : "abc"
//
//	Output :
//	[0, 6]
//
//   Explanation :
//	   The substring with start index = 0 is "cba", which is an anagram of "abc".
//	   The substring with start index = 6 is "bac", which is an anagram of "abc".
//	   Example 2 :
//
//	   Input :
//	   s : "abab" p : "ab"
//
//	   Output :
//	   [0, 1, 2]
//
//			   Explanation :
//				   The substring with start index = 0 is "ab", which is an anagram of "ab".
//				   The substring with start index = 1 is "ba", which is an anagram of "ab".
//				   The substring with start index = 2 is "ab", which is an anagram of "ab".
#include<vector>
#include<unordered_map>
using namespace std;
//time limited exceeded
class Solution {
	bool isAnagram(string& p, unordered_map<char, int> freq) {
		for (auto c : p) {
			freq[c]--;
			if (freq[c]<0)
				return false;
			if (freq[c] == 0)
				freq.erase(c);
		}
		return freq.size() == 0;
	}
public:
	vector<int> findAnagrams(string s, string p) {
		int size = p.size();
		int index = 0;
		vector<int> result;
		unordered_map<char, int> freq;

		while (index < s.size()) {
			freq[s[index]]++;

			if (index==p.size()-1) {
				if (isAnagram(p, freq))
					result.push_back(index + 1 - size);

			}
			else if ( index >= p.size() ) {
				freq[s[index - size]]--;
				if (freq[s[index - size]] == 0)
					freq.erase(s[index - size]);
				if (isAnagram(p, freq))
					result.push_back(index + 1 - size);
			}

				index++;
		}
		return result;
	}
};

class Solution {
	bool isAnagram(unordered_map<char, int>& target , unordered_map<char, int> freq) {
		return target == freq;
		
	}
public:
	vector<int> findAnagrams(string s, string p) {
		int size = p.size();
		int index = 0;
		vector<int> result;
		unordered_map<char, int> freq;
		unordered_map<char, int> target;
		for (auto c : p)
			target[c]++;

		while (index < s.size()) {
			freq[s[index]]++;

			if (index == p.size() - 1) {
				if (isAnagram(target, freq))
					result.push_back(index + 1 - size);

			}
			else if (index >= p.size()) {
				freq[s[index - size]]--;
				if (freq[s[index - size]] == 0)
					freq.erase(s[index - size]);
				if (isAnagram(target, freq))
					result.push_back(index + 1 - size);
			}

			index++;
		}
		return result;
	}
};

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int size = p.size();
		int index = 0;
		vector<int> result;
		vector<int> freq(256, 0);
		vector<int> target(256, 0);
		for (auto c : p)
			target[c]++;

		while (index < s.size()) {
			freq[s[index]]++;

			if (index == p.size() - 1) {
				if (freq == target)
					result.push_back(index + 1 - size);

			}
			else if (index >= p.size()) {
				freq[s[index - size]]--;
				if (freq == target)
					result.push_back(index + 1 - size);
			}

			index++;
		}
		return result;
	}
};
int main() {
	Solution solution;
	string s = "cbaebabacd";
	string p = "abc";
	auto res = solution.findAnagrams(s, p);
	return 0;
}