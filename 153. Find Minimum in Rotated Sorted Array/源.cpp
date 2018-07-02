//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.
//
//Example 1:
//
//Input: [3, 4, 5, 1, 2]
//	Output : 1
//	Example 2 :
//
//	Input : [4, 5, 6, 7, 0, 1, 2]
//	Output : 0
#include<vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums[0] <= nums.back())
			return nums[0];
		int start = 0;
		int end = nums.size();
		while (start < end) {
			int mid = (start + end) / 2;
			if (nums[mid] > nums[start]) {
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
		int start = 0;
		int end = nums.size();
		while (start < end) {
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