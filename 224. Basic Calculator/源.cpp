//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
//
//Example 1:
//
//Input: "1 + 1"
//	Output : 2
//	Example 2 :
//
//	Input : " 2-1 + 2 "
//	Output : 3
//	Example 3 :
//
//	Input : "(1+(4+5+2)-3)+(6+8)"
//	Output : 23
//	Note :
//	You may assume that the given expression is always valid.
//	Do not use the eval built - in library function.
#include<string>	
#include<vector>
#include<list>
using namespace std;
class Solution {
	int cal(string s) {
		list<int> num;
		list<char> operation;
		while (s.size()>0) {
			size_t pos = 0;
			num.push_back(stoi(s, &pos));
			if (pos < s.size()) {
				operation.push_back(s[pos]);
				pos++;
			}
			s = s.substr(pos, s.npos);
		}
		while (operation.size() > 0) {
			char c = *operation.begin();
			int a = *num.begin();
			int b = *(++num.begin());
			if (c == '+')
				a = a + b;
			else
				a = a - b;
			operation.pop_front();
			num.pop_front();
			num.pop_front();
			num.push_front(a);
		}
		return *num.begin();
	}
public:
	int calculate(string s) {
		vector<char> stack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ')
				continue;
			else if (s[i] == ')') {
				int j = stack.size()-1;
				while (j>=0 && stack[j] != '(') j--;
				string tmp(stack.begin() + j + 1, stack.end());
				stack.resize(j);
				string res = to_string(cal(tmp));
				stack.insert(stack.end(), res.begin(), res.end());
			}
			else
				stack.push_back(s[i]);
		}
		string tmp(stack.begin(), stack.end());
		return cal(tmp);
	}
};
int main() {
	Solution s;
	auto res = s.calculate("(1 + (4 + 5 + 2) - 3) + (6 + 8)");
	return 0;

}