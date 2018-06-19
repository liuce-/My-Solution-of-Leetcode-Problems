//Given an input string(s) and a pattern(p), implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like . or *.
//Example 1 :
//
//	Input :
//	s = "aa"
//	p = "a"
//	Output : false
//	Explanation : "a" does not match the entire string "aa".
//	Example 2 :
//
//	Input :
//	s = "aa"
//	p = "a*"
//	Output : true
//	Explanation : '*' means zero or more of the precedeng element, 'a'.Therefore, by repeating 'a' once, it becomes "aa".
//	Example 3 :
//
//	Input :
//	s = "ab"
//	p = ".*"
//	Output : true
//	Explanation : ".*" means "zero or more (*) of any character (.)".
//	Example 4 :
//
//	Input :
//	s = "aab"
//	p = "c*a*b"
//	Output : true
//	Explanation : c can be repeated 0 times, a can be repeated 1 time.Therefore it matches "aab".
//	Example 5 :
//
//	Input :
//	s = "mississippi"
//	p = "mis*is*p*."
//	Output : false
#include<string>
#include<vector>
#include<iostream>
using namespace std;
enum mode { character, dot, star };
//dot .
//star a* b& .*
//character a b c
class node {
public:
	mode m;
	char c;
	node(mode _m, char _c) :m(_m), c(_c) {};
};
class Solution {
	vector<node> patternList;
	void processPattern(string &p) {
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == '*')
				continue;

			if (p[i] == '.') {
				if (i + 1 < p.size() && p[i + 1] == '*')
					patternList.push_back(node(star, '.'));
				else
					patternList.push_back(node(dot, '.'));
			}
			else if (i + 1 < p.size() && p[i + 1] == '*') {
				patternList.push_back(node(star, p[i]));
			}
			else {
				patternList.push_back(node(character, p[i]));
			}
		}
	}
	void printPattern() {//for debug
		for (int i = 0; i < patternList.size(); i++) {
			switch (patternList[i].m)
			{
			case character:
				cout << "char " << patternList[i].c << endl;
				break;
			case dot:
				cout << "dot " << endl;
				break;
			case star:
				cout << "star " << patternList[i].c << endl;
				break;
			default:
				break;
			}
		}
	}
	bool match(string s,int index, int patternIndex) {
		if (patternList.size() == 0) 
			return s.size() == 0;
		if (s.size() == 0) {
			for (int i = 0; i < patternList.size(); i++) {
				if (patternList[i].m == character || patternList[i].m == dot)
					return false;
			}
			return true;
		}

		while (index < s.size() && patternIndex<patternList.size()) {
			if (patternList[patternIndex].m == character) {
				if (s[index] != patternList[patternIndex].c)
					return false;
				index++;
				patternIndex++;
			}
			else if (patternList[patternIndex].m == dot) {
				index++;
				patternIndex++;
			}
			else if (patternList[patternIndex].m == star) {
				bool res = false;
				int count = 0;
				//
				if (patternList[patternIndex].c == '.') {
					count = s.size() - index;
				}
				else {
					for (int i = index; i < s.size(); i++) {
						if (s[i] == patternList[patternIndex].c)
							count++;
						else
							break;
					}
				}
				//
				for (int i = 0; i < count + 1; i++) {
					res = res || match(s, index + i, patternIndex + 1);
				}
				return res;
			}
		}
		if (patternIndex == patternList.size() && index != s.size())
			return false;
		else if (patternIndex != patternList.size() && index == s.size()) {
			for (int i = patternIndex; i < patternList.size(); i++) {
				if (patternList[i].m != star)
					return false;
			}
			return true;
		}
		else //patternIndex == patternList.size() && index == s.size();
			return true;
	}
public:
	bool isMatch(string s, string p) {
		processPattern(p);
		return match(s, 0, 0);
	}
};
int main() {
	Solution s;
	auto res =s.isMatch("a", "ab*a");
	return 0;

}