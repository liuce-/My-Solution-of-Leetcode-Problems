//Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//Example:
//
//Given array nums = [-1, 2, 1, -4], and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;
		sort(nums.begin(), nums.end());
		int min = nums[0]+nums[1]+nums[2];
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] > target) {
				if (abs(target - nums[i] - nums[i + 1] - nums[i + 2]) < abs(target - min))
					min = nums[i] + nums[i + 1] + nums[i + 2];
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (abs(sum - target) < abs(min - target)) {
					min = sum;
				}
				if (sum < target)
					left++;
				else if (sum > target)
					right--;
				else if (sum == target)
					return target;
			}
		}
		return min;
		
	}
};