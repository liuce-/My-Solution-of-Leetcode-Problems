//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	Output : 6
//	Explanation : [4, -1, 2, 1] has the largest sum = 6.
//	Follow up :
//
//	   If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//
#include<vector>
using namespace std;
//o(n^2)
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max=INT_MIN;		
		for (int i = 0; i < nums.size(); i++) {
			int cur = 0;
			for (int j = i; j < nums.size(); j++) {
				cur += nums[j];
				max = cur > max ? cur : max;
			}
		}
		return max;
	}
};
//o(n)
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> sum(nums.size(), 0);
		sum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			sum[i] = sum[i - 1] + nums[i];
		int min=sum[0];
		int ans=sum[0];
		for (int i = 1; i < sum.size(); i++) {
			int tmp = sum[i] - min > sum[i] ? sum[i] - min : sum[i];
			ans = ans > tmp ? ans : tmp;
			min = min < sum[i] ? min : sum[i];
		}
		return ans;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = INT_MIN;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > max)
				max = nums[i];
			sum += nums[i];
			if (sum < 0)
				sum = 0;
			else
				max = sum > max ? sum : max;
		}
		return max;
	}
};