//You are given a list of non - negative integers, a1, a2, ..., an, and a target, S.Now you have 2 symbols + and -.For each integer, you should choose one from + and -as its new symbol.
//
//Find out how many ways to assign symbols to make sum of integers equal to target S.
//
//Example 1:
//Input: nums is[1, 1, 1, 1, 1], S is 3.
//	Output : 5
//	Explanation :
//
//	-1 + 1 + 1 + 1 + 1 = 3
//	+ 1 - 1 + 1 + 1 + 1 = 3
//	+ 1 + 1 - 1 + 1 + 1 = 3
//	+ 1 + 1 + 1 - 1 + 1 = 3
//	+ 1 + 1 + 1 + 1 - 1 = 3
//
//	There are 5 ways to assign symbols to make the sum of nums be target 3.
//	Note:
//	   The length of the given array is positive and will not exceed 20.
//		   The sum of elements in the given array will not exceed 1000.
//		   Your output answer is guaranteed to be fitted in a 32 - bit integer.
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
	vector<vector<int>> result;
	int shift = 0;
public:
	int helper(vector<int>&nums, int n, int target) {

		if (nums.size() <= n) {
			return 0;
		}
		if (n == nums.size() - 1) {
			result[n ][target + shift] = 0;
			if (target == nums[n])
				result[n][target + shift] += 1;
			if(target==-nums[n])
				result[n][target + shift] += 1;
			return result[n][target+shift];
		}
		
		if (result[n][target+shift] != -1)
			return result[n][target+shift];

		return result[n][target+shift] = helper(nums, n + 1, target + nums[n]) + helper(nums, n + 1, target - nums[n]);


	}
	int findTargetSumWays(vector<int>& nums, int target) {
		int size = nums.size();
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += nums[i];
		}
		result.resize(size, vector<int>(2 * sum + 1, -1));
		shift = sum - target;
		return helper(nums, 0, target);
	}
};