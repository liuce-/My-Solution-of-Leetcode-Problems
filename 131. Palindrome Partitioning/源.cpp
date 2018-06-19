//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//	Output :
//	[
//		["aa", "b"],
//		["a", "a", "b"]
//	]
#include<vector>
#include<string>
using namespace std;
class Solution {
	vector<vector<string>> result;
	bool isPalindrome(const string& a) {
		int size = a.size();
		int i = 0, j = size - 1;
		while (i <= j) {
			if (a[i] != a[j]) {
				return false;
			}
			else {
				i++;
				j--;
			}
		}
		return true;
	}
	void helper(string& s, int index,const vector<string>& prev) {
		int size = s.size();
		
		for (int i = index; i < size; i++) {
			if (i != size - 1) {
				string temp = s.substr(index, i - index + 1);
				if (isPalindrome(temp)) {
					vector<string> tmp = prev;
					tmp.push_back(temp);
					helper(s, i + 1, tmp);
					
				}
			}
			else {
				string temp = s.substr(index, string::npos);
				if (isPalindrome(temp)) {
					vector<string> tmp = prev;
					tmp.push_back(temp);
					result.push_back(tmp);
				}
			}
		}
		
	}
public:
	vector<vector<string>> partition(string s) {
		if(s.size()>0)
			helper(s, 0,vector<string>());
		return result;
	}
};