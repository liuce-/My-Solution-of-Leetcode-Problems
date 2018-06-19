//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given a non - empty string containing only digits, determine the total number of ways to decode it.
//
//Example 1:
//
//Input: "12"
//	Output : 2
//	Explanation : It could be decoded as "AB" (1 2) or "L" (12).
//	Example 2 :
//
//	Input : "226"
//	Output : 3
//	Explanation : It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
	vector<int> result;
public:
	int checksingle(char c) {
		if (c >= '1'&& c <= '9')
			return 1;
		else
			return 0;
	}
	int checkdouble(char c1, char c2) {
		if (c1 == '1') {
			return 1;
		}
		else if (c1 == '2') {
			if (c2 >= '0'&&c2 <= '6')
				return 1;
			else
				return 0;
		}
		return 0;
	}
	int numDecodings(string s) {
		int length = s.size();
		result = vector<int>(length, 0);
		result[0] = checksingle(s[0]);
		result[1] = checkdouble(s[0], s[1])+checksingle(s[1])*result[0];

		for (int i = 2; i < length; i++) {
			result[i] = checksingle(s[i])*result[i - 1]+checkdouble(s[i-1],s[i])*result[i-2];
		}
		return result[length-1];

	}
};