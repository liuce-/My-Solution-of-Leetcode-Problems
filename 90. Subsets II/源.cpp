//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : [1, 2, 2]
//	Output :
//	[
//		[2],
//		[1],
//		[1, 2, 2],
//		[2, 2],
//		[1, 2],
//		[]
//	]
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	vector<vector<int>> result;
	vector<bool> visited;
	void findSubsets(vector<int>& nums, int start, int count, vector<int>& prev) {
		if (count == 0)
			result.push_back(prev);
		else if (count > 0 && start < nums.size()) {
			for (int i = start; i < nums.size(); i++) {
				if (i > start && nums[i] == nums[i - 1] && !visited[i - 1])
					continue;
				visited[i] = true;
				prev.push_back(nums[i]);
				findSubsets(nums, i + 1, count - 1, prev);
				prev.pop_back();
				visited[i] = false;
			}
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.size() > 0) {
			visited.resize(nums.size());
			sort(nums.begin(), nums.end(), less<int>());
			for (int i = 0; i < nums.size()+1; i++) {
				vector<int> prev;
				findSubsets(nums, 0, i, prev);
			}
		}
		return result;
	}
};