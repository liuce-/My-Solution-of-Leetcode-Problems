//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//	Note :
//
//	Although the above answer is in lexicographical order, your answer could be in any order you want.
//
#include<string>
#include<vector>
using namespace std;
class Solution {
	vector<string> data = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> result;

public:
	vector<string> letterCombinations(string digits) {
		helper("", digits, 0);
		return result;
	}
	void helper(const string& preStr, string& digits, int index) {
		string & s = data[digits[index] - '0'];
		for (int i = 0; i < s.size(); i++) {
			string temp = preStr;
			if (index == digits.size() - 1) {
				result.push_back(temp.append(1, s[i]));
			}
			else
				helper(temp.append(1,s[i]), digits, index + 1);
		}
	}
};