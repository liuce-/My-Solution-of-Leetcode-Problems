#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_set>
using namespace std; 
class Solution {
	bool isValid(const string& s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') count++;
			if (s[i] == ')' && count-- == 0)return false;
		}
		return count == 0;
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		queue<string> q;
		unordered_set<string> result;
		unordered_set<string> visited;

		q.push(s);
		visited.insert(s);

		bool found = false;
		while (q.size() != 0) {
			string curStr = q.front();
			q.pop();
			if (isValid(curStr)) {
				result.insert(curStr);
				found = true;
			}
			if (found)
				continue;

			for (int i = 0; i < curStr.size(); i++) {
				if (curStr[i] != '(' && curStr[i] != ')' || (i > 0 && curStr[i] == curStr[i - 1]))
					continue;
				string tmp = curStr;
				tmp.erase(i, 1);
				if (visited.find(tmp) == visited.end()) {
					q.push(tmp);
					visited.insert(tmp);
				}
			}
		}
		return vector<string>(result.begin(), result.end());
	}
};
int main() {
	Solution s;
	string testcase = ")k)))())()())))())";
	auto result = s.removeInvalidParentheses(testcase);
	return 0;
}