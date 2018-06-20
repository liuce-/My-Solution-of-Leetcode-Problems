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
//stack solution.
//Hint: Have you ever played zuma?
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

//DP
//f(n)	=	0								s[n]=='('
//			f(n-2)+2						s[n]==')' && s[n-1]=='('
//			f(n-1)+2+f(n-f(n-1)-2)			s[n]==')' && s[n-1]==')' && s[n - f(n-1) -1] == '('
#include<vector>
class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> dp(s.size(), 0);
		int max = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i - 1 >= 0 && s[i] == ')' && s[i - 1] == '(')
				dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
			else if ( i >= 3 && s[i] == ')' && s[i - 1] == ')'&& s[i-dp[i-1]-1]=='(') {
				dp[i] = dp[i - 1] + 2;
				if (i >= 5)
					dp[i] += dp[i - dp[i - 1] - 2];
			}
			max = dp[i] > max ? dp[i] : max;
		}
		return max;
	}
};
