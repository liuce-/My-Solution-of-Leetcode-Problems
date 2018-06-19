//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//Example 1:
//
//Input: s = "anagram", t = "nagaram"
//	Output : true
//	Example 2 :
//
//	Input : s = "rat", t = "car"
//	Output : false
//	Note :
//	You may assume the string contains only lowercase alphabets.
//
//	Follow up :
//	   What if the inputs contain unicode characters ? How would you adapt your solution to such case ?
//
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> map;
		for (auto i = s.begin(); i != s.end(); i++) {
			map[*i]++;
		}
		for (auto j = t.begin(); j != t.end(); j++) {
			if (map.find(*j) == map.end()) {
				return false;
			}
			else {
				map[*j]--;
				if (map[*j] == 0)
					map.erase(*j);
			}
		}
		return map.size() == 0;

	}
};