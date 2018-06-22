//Given an input string(s) and a pattern(p), implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like ? or *.
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
//	p = "*"
//	Output : true
//	Explanation : '*' matches any sequence.
//	Example 3 :
//
//	Input :
//	s = "cb"
//	p = "?a"
//	Output : false
//	Explanation : '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//	Example 4 :
//
//	Input :
//	s = "adceb"
//	p = "*a*b"
//	Output : true
//	Explanation : The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//	Example 5 :
//
//	Input :
//	s = "acdcb"
//	p = "a*c?b"
//	Output : false

#include<string>
#include<vector>
using namespace std;
//brutal force, memory limited exceeded
class Solution {
	vector<vector<char>> data;
	bool match(string s, int i, string p, int j) {
		if (data[i][j] != CHAR_MAX)
			return data[i][j];

		if (j == p.size()) {
			data[i][j] = (i == s.size());
			return data[i][j];

		}
		if (i == s.size()) {
			for (; j < p.size(); j++) {
				if (p[j] != '*')
					return data[i][j]=false;
			}
			return data[i][j]=true;
		}
		bool res = false;
		if (p[j] == '?')
			res = match(s, i + 1, p, j + 1);
		else if (p[j] == '*') {
			while (j+1 <p.size() && p[j + 1] == '*')j++;

			for (int k = i; k <= s.size(); k++) {
				res = res || match(s, k, p, j + 1);
				if (res)
					break;
			}
		}
		else {
			if (s[i] == p[j])
				res= match(s, i + 1, p, j + 1);
			else
				res= false;
		}
		data[i][j] = res;
		return res;

	}
public:
	bool isMatch(string s, string p) {
		data.resize(s.size()+1,vector<char>(p.size()+1, CHAR_MAX));
		return match(s, 0, p, 0);
	}
};
class Solution2 {
	vector<vector<bool>> dp;
public:
	bool isMatch(string s, string _p) {
		string p;
		for (int i = 0; i < _p.size(); i++) {
			if (_p[i] != '*')
				p.push_back(_p[i]);
			else if (i == 0 || _p[i] == '*'&&_p[i - 1] != '*')
				p.push_back('*');
		}//reduce p length, reduce dp memory cost


		dp.resize(s.size() + 1, vector<bool>(p.size()+1, false));
		/* 
			dp[i][j]=s[0,i-1] match p[0,j-1]
			1¡¢why i-1
			need to consider the match between "" and "*"
			2¡¢whyj-1
			need to consider the match between "asdf" and "". it also make the comparison of "aa" and "a" easier

		*/
		dp[0][0] = true;// "" always match "" and dp[1][0] to dp[end][0] always false
		if (p[0] == '*')
			dp[0][1] = true;//p[1] is not '*' because we eliminate the continuous '*' at the beginning.

		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= p.size(); j++) {
				if (p[j-1] == '?'|| s[i - 1] == p[j-1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j-1] == '*') {
					//dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];	//true
					//dp[i][j] = dp[i - 1][j];	//false it asumes that '*' always match at least one element, but actually it can match nothing. eg: "adceb" and "*a*b"
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; //true
					//dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1]; //false it asumes that '*' always match at least one element, but actually it can match nothing. eg: "a" and "a*"

				}
			}
		}
		return dp.back().back();

	}
};
//the while version of solution 1
class Solution3 {
public:
	bool isMatch(string s, string p) {
		char* s1 = &s[0], *sstar = nullptr, *p1 = &p[0], *pstar = nullptr;
		while (*s1) {
			if (*s1 == *p1 || *p1 == '?') {
				++s1; ++p1;
			}
			else if (*p1 == '*') {
				pstar = p1++;
				sstar = s1;
			}
			else if (pstar != nullptr) {
				s1 = ++sstar;
				p1 = pstar + 1;
			}
			else {
				return false;
			}
		}
		while (*p1 == '*') ++p1;
		return !(*p1);
	}
};

int main() {
	Solution3 s;
	auto res= s.isMatch("adced", "*a*d");
	return 0;
}