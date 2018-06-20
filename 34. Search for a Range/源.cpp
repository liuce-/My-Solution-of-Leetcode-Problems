//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//Example 1:
//
//Input: nums = [5, 7, 7, 8, 8, 10], target = 8
//	Output : [3, 4]
//	Example 2 :
//
//	Input : nums = [5, 7, 7, 8, 8, 10], target = 6
//	Output : [-1, -1]
#include<vector>
using namespace std;
class Solution {
	int find(vector<int>& nums, int left, int right, int target) {
		while(left <= right){				
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target) 
				right = mid - 1;			
			else
				left = mid + 1;
		}
		return -1;
	}
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return vector<int>{-1, -1};
		int pos = find(nums, 0, nums.size() - 1, target);
		if (pos == -1)
			return vector<int>{-1, -1};
		else {
			int left = pos;
			int right = pos;
			while (left>=0 && nums[left] == nums[pos]) left--;
			while (right < nums.size() && nums[right] == nums[pos])right++;
			left++;
			right--;
			return vector<int>{left, right};
		}
	}
};