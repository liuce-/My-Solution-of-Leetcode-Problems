#include<string>	
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		if (s == "")
			return 0;
		int res = s[0] == '0' ? 0 : s[0] == '*' ? 9 : 1;
		int prev = 1;
		for (int i = 1; i < s.size(); i++) {
			int prevprev = prev;
			prev = res;
			if (s[i] == '0')
				res = 0;
			else if (s[i] == '*')
				res = prev * 9;
			else
				res = prev;

			if (s[i] == '*') {
				if (s[i - 1] == '1')
					res += prevprev * 9;
				if (s[i - 1] == '2')
					res += prevprev * 6;
				if (s[i - 1] == '*')
					res += prevprev * 15;
			}
			else {
				if (s[i - 1] == '*') {
					res += s[i - 1] > '6' ? 1 : 2;
				}
				else {
					int tmp = stoi(s.substr(i - 1, 2));
					if (tmp >= 10 && tmp <= 26)
						res += prevprev;

				}
			}



		}
		return res;
	}
};
int main() {
	Solution s;
	auto res = s.numDecodings("1*72*");
	return 0;
}