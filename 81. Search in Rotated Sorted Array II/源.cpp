//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 0, 1, 2, 2, 5, 6] might become[2, 5, 6, 0, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return true, otherwise return false.
//
//Example 1:
//
//Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 0
//	Output : true
//	Example 2 :
//
//	Input : nums = [2, 5, 6, 0, 0, 1, 2], target = 3
//	Output : false
//	Follow up :
//
//	   This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
//		   Would this affect the run - time complexity ? How and why ?
#include<vector>
using namespace std;
//worst O(n),best(logn)
class Solution {
	bool binarySearch(vector<int>& nums, int left, int right, int target) {//[left,right)
		if(right<=nums.size())
		while (left < right) {
			int mid = (right + left) / 2;
			if (target == nums[mid])
				return true;
			else if (target > nums[mid])
				left = mid + 1;
			else
				right = mid;
		}
		return false;
	}
public:
	bool search(vector<int>& nums, int target) {
		int i = 0;
		while (i+1 < nums.size() && nums[i] <= nums[i + 1])i++;
		return binarySearch(nums, 0, i + 1, target) || binarySearch(nums, i + 1, nums.size(), target);
	}
};

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;

		while (left <= right)
		{
			mid = (left + right) /2;
			if (nums[mid] == target) return true;

			// the only difference from the first one, trickly case, just update left and right
			if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }

			else if (nums[left] <= nums[mid])
			{
				if ((nums[left] <= target) && (nums[mid] > target)) right = mid - 1;
				else left = mid + 1;
			}
			else
			{
				if ((nums[mid] < target) && (nums[right] >= target)) left = mid + 1;
				else right = mid - 1;
			}
		}
		return false;
	}
};

