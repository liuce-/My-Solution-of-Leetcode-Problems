//Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
//
//Below is one possible representation of s1 = "great":
//
//great
/// \
//gr    eat
/// \ / \
//g   r  e   at
/// \
//a   t
//To scramble the string, we may choose any non - leaf node and swap its two children.
//
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//rgeat
/// \
//rg    eat
/// \ / \
//r   g  e   at
/// \
//a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//
//rgtae
/// \
//rg    tae
/// \ / \
//r   g  ta  e
/// \
//t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
//
//Example 1:
//
//Input: s1 = "great", s2 = "rgeat"
//	Output : true
//	Example 2 :
//
//	Input : s1 = "abcde", s2 = "caebd"
//	Output : false

#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//Here is my original thought
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;

		int len = s1.length();
		int s1count[26] = { 0 };
		int s2count[26] = { 0 };
		for (int i = 0; i<len; i++)
		{
			s1count[s1[i] - 'a']++;
			s2count[s2[i] - 'a']++;
		}

		for (int i = 0; i<26; i++)
		{
			if (s1count[26] != s2count[26])
				return false;
		}

		for (int i = 1; i <= len - 1; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};


class Solution {
	vector<vector<vector<bool>>> anagram;
	bool isAnagram(unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
		int count = 0;
		for (auto i = map1.begin(); i != map1.end(); i++) {
			if (map2[i->first] != i->second)
				return false;
			else
				count++;
		}
		
		return map2.size()==count;		
	}
	bool scramble(string s1, int left1, string s2, int left2, int length) {//[left1,left1+length) [left2,left2+length)
		if (length == 1||length==0)
			return true;
		bool res = false;
		for (int i = 0; i < length-1; i++) {//length-1 prevent infinit loop
			if (anagram[left1][left2+length-i-1 ][i+1]) 
				res = res || (scramble(s1, left1, s2, left2 + length - 1 - i, i+1 ) && scramble(s1, left1 + i + 1, s2, left2, length - i - 1));
			
			if (!res && anagram[left1][left2][i+1])
				res = res || (scramble(s1, left1, s2, left2, i + 1) && scramble(s1, left1 + i + 1, s2, left2 + i + 1, length - i - 1));

			if (res)
				return true;
		}
		return false;		
	}
public:
	bool isScramble(string s1, string s2) {
		anagram.resize(s1.size(), vector<vector<bool>>(s1.size(), vector<bool>(s1.size() + 1)));//s1Index,s2Index,length
		for (int i = 0; i < s2.size(); i++) {
			unordered_map<char, int> s1Map;
			unordered_map<char, int> s2Map;
			for (int j = i, k = 0; j < s2.size(); j++, k++) {
				s2Map[s2[j]]++;
				s1Map[s1[k]]++;
				anagram[0][i][j - i + 1] = isAnagram(s2Map, s1Map);
			}
		}
		for (int i = 0; i < s1.size(); i++) {
			unordered_map<char, int> s1Map;
			unordered_map<char, int> s2Map;
			for (int j = i, k = 0; j < s1.size(); j++, k++) {
				s1Map[s1[j]]++;
				s2Map[s2[k]]++;
				anagram[i][0][j - i + 1] = isAnagram(s2Map, s1Map);
			}
		}

		for (int i = 1; i < s1.size(); i++) {
			for (int j = 1; j < s2.size(); j++) {
				int maxIJ = max(j, i);
				int minIJ = min(i, j);
				unordered_map<char, int> s1Map;
				unordered_map<char, int> s2Map;
				for (int s1Index = i, s2Index = j; s1Index < s1.size() && s2Index < s2.size();s1Index++,s2Index++) {
					s1Map[s1[s1Index]]++;
					s2Map[s2[s2Index]]++;
					int originI = i - min(i, j);
					int originJ = j - min(i, j);
					bool longStr = anagram[originI][originJ][s1Index - originI + 1];
					bool shortStr = anagram[originI][originJ][i - originI];
					if (!longStr && !shortStr)
						anagram[i][j][s1Index - i + 1] = isAnagram(s1Map, s2Map);
					else
						anagram[i][j][s1Index - i + 1] = longStr && shortStr;
				}
			}
		}
		if (anagram[0][0][s1.size()])//only anagram could be scramble strign
			return scramble(s1, 0, s2, 0, s1.size());
		else
			return false;
	}
}; 
//Here is my original thought
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;

		int len = s1.length();
		int s1count[26] = { 0 };
		int s2count[26] = { 0 };
		for (int i = 0; i<len; i++)
		{
			s1count[s1[i] - 'a']++;
			s2count[s2[i] - 'a']++;
		}

		for (int i = 0; i<26; i++)
		{
			if (s1count[i] != s2count[i])
				return false;
		}

		for (int i = 1; i <= len - 1; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};


int main() {
	Solution s;
	auto res = s.isScramble("abcd", "bcda");
	return 0;
	
}