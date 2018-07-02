//Given an input string, reverse the string word by word.
//
//Example:
//
//Input: "the sky is blue",
//	Output : "blue is sky the".
//	Note :
//
//	A word is defined as a sequence of non - space characters.
//	Input string may contain leading or trailing spaces.However, your reversed string should not contain leading or trailing spaces.
//	You need to reduce multiple spaces between two words to a single space in the reversed string.
//	Follow up : For C programmers, try to solve it in - place in O(1) space.
//
#include<sstream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		stack<string>  stack;
		string res;
		istringstream stream(s);
		string tmp;
		while (getline(stream, tmp, ' ')) {
			if(tmp.size()!=0)
			stack.push(tmp);
		}
		
		while (stack.size() != 0) {
			res.append(stack.top());
			res.append(" ");
			stack.pop();
		}
		if(res.size()!=0)
			res.resize(res.size() - 1);
		s=res;
		
	}
};
int main() {
	Solution s;
	string testcase = "    ";
	s.reverseWords(testcase);
	return 0;

}