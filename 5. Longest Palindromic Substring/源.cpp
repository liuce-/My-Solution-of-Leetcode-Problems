//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//	Output : "bab"
//
//	Note : "aba" is also a valid answer.
//
//
//	Example :
//
//	Input : "cbbd"
//
//	Output : "bb"
#include<string>
#include<vector>
using namespace std;

class Solution {
	vector<vector<int>> cache;
	int calPalindrome(string& s, int i, int j) {
		if (cache[i][j] != INT_MAX)
			return cache[i][j];

		if (i == j){
			cache[i][j] = 1;
		}
		else if (i + 1 == j) {
			cache[i][j] = s[i] == s[j] ? 2 : 0;
		}
		else {
			if (s[i] != s[j] || calPalindrome(s, i + 1, j - 1) == 0)
				cache[i][j] = 0;
			else
				cache[i][j] = calPalindrome(s, i + 1, j - 1) + 2;
		}
		return cache[i][j];
	}
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
			return "";
		int max = 0;
		string result = "";
		cache.resize(s.size(), vector<int>(s.size(), INT_MAX));
		for (int i = 0; i < cache.size(); i++) {
			for (int j = i; j < cache.size(); j++) {
				int tmp = calPalindrome(s, i, j);
				if (tmp > max) {
					max = tmp;
					result = s.substr(i, j - i + 1);
				}
			}
		}
		return result;
	}
}; 

class Solution {
	vector<vector<int>> cache;
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
			return "";
		cache.resize(s.size(), vector<int>(s.size(), INT_MAX));
		int max = 0;
		string res = "";
		for (int diff = 0; diff < s.size(); diff++) {
			for (int i = 0; i < s.size()-diff; i++) {
				int j = i + diff;
				if (i == j)
					cache[i][j] = 1;
				else if (i + 1 == j)
					cache[i][j] = s[i] == s[j] ? 2 : 0;
				else {
					if (s[i] != s[j] || cache[i + 1][j - 1] == 0)
						cache[i][j] = 0;
					else
						cache[i][j] = cache[i + 1][j - 1] + 2;
				}
				if (cache[i][j] > max) {
					max = cache[i][j];
					res = s.substr(i, j - i + 1);
				}
			}
		}
		return res;
	}
};

//输入，并处理得到字符串s
int p[1000], mx = 0, id = 0;
memset(p, 0, sizeof(p));
for (i = 1; s[i] != '\0'; i++) {
	p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
	while (s[i + p[i]] == s[i - p[i]]) p[i]++;
	if (i + p[i] > mx) {
		mx = i + p[i];
		id = i;
	}
}
//找出p[i]中最大的
