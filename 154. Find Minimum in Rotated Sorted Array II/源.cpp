//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//Find the minimum element.
//
//The array may contain duplicates.
//
//Example 1:
//
//Input: [1, 3, 5]
//	Output : 1
//	Example 2 :
//
//	Input : [2, 2, 2, 0, 1]
//	Output : 0
//	Note :
//
//	This is a follow up problem to Find Minimum in Rotated Sorted Array.
//	Would allow duplicates affect the run - time complexity ? How and why ?
#include<vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int start = 0;
		int end = nums.size();
		while (start < end) {

			//the only difference.
			//make sure no same elements at the begining or ending.
			while (start + 1 < end && nums[start] == nums[start + 1]) start++;
			while (end - 2 > start &&nums[end - 1] == nums[end - 2]) end--;
			
			int mid = (start + end) / 2;
			if (nums[mid] >= nums[start]) {
				if (nums[mid] <= nums[end - 1])//no rotation
					return nums[start];
				if (nums[mid] > nums[mid + 1])
					return nums[mid + 1];
				start = mid + 1;
			}
			else {
				if (nums[mid] < nums[mid - 1])
					return nums[mid];
				end = mid;
			}
		}
		return INT_MIN;//shouldn't be here.
	}
};



class Solution {
public:
	int findMin(vector<int>& nums) {
		int start = 1;
		while (start < nums.size() && nums[start] >= nums[start - 1])start++;
		return start == nums.size() ? nums[0] : nums[start];		
	}
};