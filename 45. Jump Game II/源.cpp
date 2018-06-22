//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//Example:
//
//Input: [2, 3, 1, 1, 4]
//	Output : 2
//	Explanation : The minimum number of jumps to reach the last index is 2.
//	Jump 1 step from index 0 to 1, then 3 steps to the last index.
//	Note :
//
//	You can assume that you can always reach the last index.
//
#include<vector>

using namespace std;
//dp solution, Time limited exceeded o(n^2)
class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> dp(nums.size(), INT_MAX);
		dp[nums.size() - 1] = 0;
		for (int i = nums.size() - 2; i >= 0; i++) {
			int maxStep = nums[i];
			int min = INT_MAX;
			for (int j = 1; j <= maxStep && i+j<nums.size(); j++) {
				if(dp[i+j]!=INT_MAX)
					min = min < dp[i + j] + 1 ? min : dp[i + j] + 1;
			}
			dp[i] = min;
		}
		return dp[0];
	}
};
//greedy O(n) 
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;

		int count = 1;
		int max = nums[0];
		int last = 0;
		while (1) {
			if (max >= nums.size() - 1)
				return count;
			int tmp = max;
			max = 0;
			for (int i = last; i <= tmp; i++) {
				if (nums[i] + i > max)
					max = nums[i] + i;
			}
			last = tmp+1;
			count++;
		}
	}
};