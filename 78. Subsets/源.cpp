//Given a set of distinct integers, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : nums = [1, 2, 3]
//	Output :
//	[
//		[3],
//		[1],
//		[2],
//		[1, 2, 3],
//		[1, 3],
//		[2, 3],
//		[1, 2],
//		[]
//	]

#include<vector>
using namespace std;

class Solution {
	vector<vector<int>> result;
	void findSubsets(vector<int>& nums, int start, int count, vector<int>& prev) {
		if (count == 0)
			result.push_back(prev);
		else if (count > 0 && start < nums.size()) {
			for (int i = start; i < nums.size(); i++) {
				prev.push_back(nums[i]);
				findSubsets(nums, i + 1, count - 1, prev);
				prev.pop_back();
			}
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size + 1; i++) {
			vector<int> prev;
			findSubsets(nums, 0, i, prev);
		}
		return result;
	}
};