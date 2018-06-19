//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s.If there isn't one, return 0 instead.
//
//Example:
//
//Input: s = 7, nums = [2, 3, 1, 2, 4, 3]
//	Output : 2
//	Explanation : the subarray[4, 3] has the minimal length under the problem constraint.
//	Follow up :
//	   If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int left = 0;
		int right = 0;
		int sum = nums[left];
		int result = INT_MAX;
		while (right < nums.size()) {
			if (sum < s) {
				right++;
				if(right<nums.size())
					sum = sum + nums[right];
			}
			else if (sum >= s) {
				result = result < right - left + 1 ? result : right - left + 1;
				sum = sum - nums[left];
				left++;
			}
		}
		
		return result==INT_MAX?0:result;
	}
};