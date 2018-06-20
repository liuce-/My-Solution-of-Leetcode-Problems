//Given an unsorted integer array, find the smallest missing positive integer.
//
//Example 1:
//
//Input: [1, 2, 0]
//	Output : 3
//	Example 2 :
//
//	Input : [3, 4, -1, 1]
//	Output : 2
//	Example 3 :
//
//	Input : [7, 8, 9, 11, 12]
//	Output : 1
//	Note :
//
//	Your algorithm should run in O(n) time and uses constant extra space.
//
#include<vector>
using namespace std;
//o(n) time and o(n) space
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		vector<bool> res(nums.size() + 1, false);
		res[0] = true;
		for (auto i : nums) {
			if (i > 0 && i < res.size())
				res[i] = true;
		}
		for (int i = 0; i < res.size(); i++) {
			if (!res[i])
				return i;
		}
		return res.size();
	}
};

//o(n) time and o(1) solution, same algorithm as previous one , but store the info in the input array.
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size();) {
			if (nums[i] > 0 && nums[i] - 1 < nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
			else
				i++;			
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]!=i+1)
				return i;
		}
		return nums.size();
	}
};