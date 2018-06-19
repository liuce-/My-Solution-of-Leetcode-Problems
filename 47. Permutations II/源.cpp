//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//Example:
//
//Input: [1, 1, 2]
//	Output :
//	[
//		[1, 1, 2],
//		[1, 2, 1],
//		[2, 1, 1]
//	]
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	vector<vector<int>> result;
	vector<int> mark;
	vector<int> prev;
public:
	void helper(vector<int>& nums) {
		int state = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (mark[0]==0 && i == 0) {
				prev.push_back(nums[0]);
				mark[0] = 1;
				helper(nums);
				mark[0] = 0;
				prev.pop_back();
				state = 1;
			}
			else {
				if (mark[i]==0 && (nums[i] != nums[i - 1] || (nums[i]==nums[i-1] && mark[i-1]==1))) {
					prev.push_back(nums[i]);
					mark[i] = 1;
					helper(nums);
					mark[i] = 0;
					prev.pop_back();
					state = 1;
				}
			}
				
		}
		if (state == 0)
			result.push_back(prev);
		return;

	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() != 0) {
			mark.resize(nums.size(), 0);
			sort(nums.begin(), nums.end(), less<int>());
			helper(nums);
		}
		return result;
	}
};