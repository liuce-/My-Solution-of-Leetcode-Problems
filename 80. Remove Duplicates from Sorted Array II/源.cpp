//Given a sorted array nums, remove the duplicates in - place such that duplicates appeared at most twice and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//Example 1:
//
//Given nums = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
//
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Given nums = [0, 0, 1, 1, 1, 1, 2, 3, 3],
//
//Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
//
//It doesn't matter what values are set beyond the returned length.

#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size()<3)
			return nums.size();
		int count = 0;
		int left = 1;
		for (int i = 1; i<nums.size(); i++) {
			if (nums[i] == nums[i - 1])
				count++;
			else
				count = 0;
			if (count <= 1) {
				nums[left] = nums[i];
				left++;
			}
		}
		return left;
	}
}; 
class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		for (int j=0;j<nums.size();j++)
			if (i < 2 || nums[j] > nums[i - 2])
				nums[i++] = nums[j];
		return i;
	}

};
int main() {
	Solution2 s;
	vector<int> testcase = { 1,1,1,2,2,3 };
	s.removeDuplicates(testcase);
	return 0;
}