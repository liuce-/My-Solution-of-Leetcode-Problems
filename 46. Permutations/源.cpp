//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1, 2, 3]
//	Output :
//	[
//		[1, 2, 3],
//		[1, 3, 2],
//		[2, 1, 3],
//		[2, 3, 1],
//		[3, 1, 2],
//		[3, 2, 1]
//	]
#include<string>
#include<vector>
using namespace std;
//回溯
class Solution {
	vector<vector<int>> result;
	void helper(vector<int>& prev, vector<bool>& mark, vector<int>& nums) {
		int state = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (!mark[i]) {
				prev.push_back(nums[i]);
				state = 1;
				mark[i] = true;
				helper(prev, mark, nums);
				////回溯，恢复递归前的状态
				mark[i] = false;
				prev.pop_back();
			}
		}
		if (state == 0)
			result.push_back(prev);
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)
			return vector<vector<int>>();
		vector<bool> mark(size, false);
		vector<int> p;
		helper(p, mark, nums);
		return result;
	}
};
//更快
class Solution2 {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > result;
		permuteRecursive(num, 0, result);
		return result;
	}
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result) {
		if (begin == num.size() - 1) {
			result.push_back(num);
			return;
		}
		for (int i = begin; i < num.size(); i++) {
			swap(num[begin], num[i]);//excellent
			permuteRecursive(num, begin + 1, result);
			swap(num[begin], num[i]);
		}
	}
};