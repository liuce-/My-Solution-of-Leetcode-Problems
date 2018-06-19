//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//Example 1:
//
//Input: "(()"
//	Output : 2
//	Explanation : The longest valid parentheses substring is "()"
//	Example 2 :
//
//	Input : ")()())"
//	Output : 4
//	Explanation : The longest valid parentheses substring is "()()"
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2)
			return 0;
		stack<pair<char,int>> match;
		
		//Important. 
		//For two purpose: 
		//1. We do not need to consider match.size()==0 when matching. 
		//2.Calculating the corner cases such as "())" will be a lot eaiser.
		match.push(make_pair(')', -1));		
		for (int i = 0; i < s.size(); i++) {
			if (match.top().first == '(' && s[i] == ')')
				match.pop();
			else
				match.push(make_pair(s[i], i));			
		}
		int max = 0;
		int cur = 0;
		int right = s.size();
		while (match.size() != 0) {
			cur = (right - 1) - (match.top().second + 1) + 1;
			max = max > cur ? max : cur;
			right = match.top().second;
			match.pop();
		}
		return max;
	}
};