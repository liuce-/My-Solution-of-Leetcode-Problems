//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0 || s.length() == 1)
			return s.length();
		int result = 1;
		int start = 0;
		int end = 1;
		vector<int> cmp(256, -1);
		cmp[s[start]] = 0;
		int temp = end - start;

		for (; end != s.length(); end++) {
			//寻找end指向的字符是否在该子串前面存在
			int index = s[end];
			if (cmp[index] != -1) {
				start = cmp[index] + 1;
				temp = end - start+1;
				cmp[index] = end;
				//重新更新cmp数组
				for (int i = 0; i < 256; i++) {
					cmp[i] = -1;
				}
				for (int i = start; i <= end; i++) {
					cmp[s[i]] = i;
				}
			}
			else {
				cmp[index] = end;
				temp++;
			}
			//判断子串是否超过最大值
			if (temp > result)
				result = temp;
		}

		return result;

	}//47ms
};
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> cmp(256,0);
		int left = 0;
		int right = 0;
		int result = 0;
		while (right < s.size()) {
			if (cmp[s[right]] == 0)
				cmp[s[right++]]++;
			else
				cmp[s[left++]]--;
			result = result > right - left ? result:right - left;
		}
		return result;
	}
};
class Solution3 {
public:
	int lengthOfLongestSubstring(string s) {
		int left = 0;
		int right = -1;//[left,right]
		int result = 0;
		unordered_set<char> set;
		while (right+1 < (int)s.size()) {
			if ( set.find(s[++right]) != set.end()) {
				while (set.find(s[right]) != set.end())
					set.erase(s[left++]);
			}
			set.insert(s[right]);
			result = max(right - left + 1, result);

		}
		return result;
	}
};
int main() {
	string s = "bbbbb";
	Solution3 test;
	std::cout<<test.lengthOfLongestSubstring(s);
	system("pause");
	return 0;
}