//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//Example 1:
//
//Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//	Output : 4
//	Example 2 :
//
//	Input : nums = [4, 5, 6, 7, 0, 1, 2], target = 3
//	Output : -1
#include<vector>
using namespace std;
class Solution {
	int find(vector<int>& nums, int start, int end, int target) {//find in [start,end)
		if (start >= end)
			return -1;
		if (start + 1 == end)
			return nums[start] == target ? -1 : start;
		else {
			int mid = nums[(start + end) / 2];
			if (mid == target)
				return mid;
			else if(mid>target){
				return find(nums, start, mid,target);
			}
			else
				return find(nums, mid + 1, end, target);
		}
	}
	int turningPoint(vector<int>& nums, int start, int end) {
		int mid = (start + end) / 2;
		
		while (nums[mid] > nums[end]) mid = (mid + end) / 2;
		
		int left = 2 * mid - end;
		int right = mid;
			
		while (left+1 != right) {
			int mid = (left + right) / 2;
			if (nums[mid] > nums[end]) 
				left = mid;			
			else 
				right = mid;				
		}
		return right;
	}
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
		
		if (nums[0] > nums[nums.size() - 1]) {//rotation happened
			//find the turning point
			int pivot = turningPoint(nums, 0, nums.size()-1);
			if (target > nums[nums.size() - 1]) 
				return find(nums, 0, pivot,target);			
			else 
				return find(nums, pivot, nums.size(),target);			
		}
		else 
			return find(nums, 0, nums.size(), target);
	}
};


class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;

			if (nums[left] <= nums[mid]) {
				if (nums[mid] > target && nums[left] <= target)
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {
				if (nums[mid]<target && nums[right] >= target)
					left = mid + 1;
				else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}

};