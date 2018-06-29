//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Your algorithm should run in O(n) complexity.
//
//Example:
//
//Input: [100, 4, 200, 1, 3, 2]
//	Output : 4
//	Explanation : The longest consecutive elements sequence is[1, 2, 3, 4].Therefore its length is 4.
#include<vector>
#include<algorithm>
using namespace std;
//Memory Limited Exceeded
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int minValue = INT_MAX;
		int maxValue = INT_MIN;
		for (auto i : nums) {
			minValue = min(minValue, i);
			maxValue = max(maxValue, i);
		}
		vector<bool> bucket(maxValue - minValue + 1, false);
		for (auto i : nums)
			bucket[i - minValue] = true;
		
		int maxCount = 0;
		int currentCount = 0;
		for (auto i : bucket) {
			if (i)
				currentCount++;
			else {
				maxCount = max(currentCount, maxCount);
				currentCount = 1;
			}
		}
		maxCount = max(currentCount, maxCount);
		return maxCount;			
	}
};
//O(nlogn) time limited exceeded
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(), nums.end(), less<int>());
		if (nums.size() == 0)
			return 0; 
		int maxCount = 1;
		int currentCount = 1;
		for (int i = 1; i < nums.size();i++) {
			if (nums[i] == nums[i - 1])
				continue;

			if (nums[i]-nums[i-1]==1)
				currentCount++;
			else {
				maxCount = max(currentCount, maxCount);
				currentCount = 1;
			}
		}
		maxCount = max(currentCount, maxCount);
		return maxCount;
	}
};

//
#include<unordered_set>
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_set<int> record(num.begin(), num.end());
		int res = 0;
		while(record.size()>res) {
			auto i = record.begin();
			int number = *i;
			int cur = number;
			int tmp = 0;
			while (record.find(cur)!=record.end()) {
				tmp++;				
				record.erase(cur);
				cur--;
			}
			cur = number+1;
			while (record.find(cur) != record.end()) {
				tmp++;
				record.erase(cur);
				cur++;				
			}
			res = max(res, tmp);
		}
		return res;
	}
};

