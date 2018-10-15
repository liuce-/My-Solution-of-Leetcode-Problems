#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int left = 0;
		int right = 0;
		unordered_map<char, int> map;
		int maxLength = 0;
		while (right < s.size()) {
			if (map.size() <= 2)
				map[s[right++]]++;
			while (map.size() > 2) {
				map[s[left++]]--;
				if (map[s[left - 1]] == 0)
					map.erase(s[left - 1]);
			}
			maxLength = max(maxLength, right - left);
		}
		return maxLength;
	}
};