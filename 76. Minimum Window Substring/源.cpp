//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//Example:
//
//Input: S = "ADOBECODEBANC", T = "ABC"
//	Output : "BANC"
//	Note :
//
//	If there is no such window in S that covers all characters in T, return the empty string "".
//	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution2 {
	bool isContain(vector<int>& freq, vector<int>& target) {
		for (int i = 0; i < 256; i++) {
			if (freq[i] < target[i])
				return false;
		}
		return true;
	}
public:
	string minWindow(string s, string t) {		
		if (t.size() == 0 || s.size() == 0)
			return "";
		vector<int> target(256, 0);
		vector<int> freq(256, 0);
		string res;
		for (auto c : t)
			target[c]++;
		int left = 0;
		int right = 0;
		while (right < s.size()) {
			if (target[s[right]] == 0) 
				right++;
			else {
				freq[s[right]]++;
				if (isContain(freq,target)) {//s contain t
					string tmp = s.substr(left, right - left + 1);
					if (res == "")
						res = tmp;
					else
						res = res.size() < tmp.size() ? res : tmp;
					//shrink from left
					if (target[s[left]] != 0) 
						freq[s[left]]--;					
					left++;
				}
				else
					right++;
			}
		}
		return res;

	}
};

class Solution {
	bool isContain(vector<int>& freq, vector<int>& target) {
		for (int i = 0; i < 128; i++) {
			if (target[i] != 0) {
				if (freq[i] < target[i])
					return false;
			}
		}
		return true;
	}
	void print(vector<int>& v) {
		for (int i = 0; i<v.size(); i++) {
			if (v[i] != 0)
				cout << (char)i << v[i] << " ";
		}
		cout << endl;
	}
public:
	string minWindow(string s, string t) {
		if (t.size() == 0 || s.size() == 0)
			return "";
		vector<int> target(128, 0);
		vector<int> freq(128, 0);
		string res;
		for (auto c : t)
			target[c]++;
		int left = 0;
		int right = -1;
		while (right < (int)s.size() && left<(int)s.size()) {
 			if (isContain(freq, target)) {//s contain t
				//print(freq);
				string tmp = s.substr(left, right - left + 1);
				//cout << left << " " << right << " " << tmp << endl;
				if (res == "")
					res = tmp;
				else
					res = res.size() < tmp.size() ? res : tmp;
				//shrink from left
				freq[s[left]]--;
				left++;
			}
			else
				freq[s[++right]]++;

		}
		return res;

	}
};
class BestSolution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size()) {
			if (map[s[end++]]-- > 0) counter--; //in t
			while (counter == 0) { //valid
				if (end - begin < d)  d = end - (head = begin);
				if (map[s[begin++]]++ == 0) counter++;  //make it invalid
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);


	}
};
int main() {
	BestSolution solution;
	string s = "DBCAD";
	string t = "ABC";
	auto res =solution.minWindow(s, t);
	return 0;
}