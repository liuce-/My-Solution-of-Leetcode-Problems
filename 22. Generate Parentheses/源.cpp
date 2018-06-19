//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]
#include<vector>
#include<string>
using namespace std;
class Solution {
	vector<string> result;
	void generate(string &s, int leftUsed, int rightUsed, int pair) {
		int singleLeft = leftUsed - rightUsed;
		int leftleft = pair - leftUsed;
		int rightleft = pair - rightUsed;
		if (leftleft == 0 && rightleft !=0) {
			s.append(")");
			generate(s, leftUsed, rightUsed + 1, pair);
			s.erase(s.size() - 1, 1);
		}
		else if (leftleft == 0 && rightleft == 0) {
			result.push_back(s);
		}
		else {//leftused!=0 && leftUsed!=0
			s.append("(");
			generate(s, leftUsed + 1, rightUsed, pair);
			s.erase(s.size() - 1, 1);
			if (singleLeft != 0) {
				s.append(")");
				generate(s, leftUsed, rightUsed + 1, pair);
				s.erase(s.size() - 1, 1);
			}
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		string s;
		generate(s, 0, 0, n);
		return result;
	}
};