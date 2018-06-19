//Given a set of candidate numbers(candidates) (without duplicates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [2, 3, 6, 7], target = 7,
//	A solution set is :
//[
//	[7],
//	[2, 2, 3]
//]
//Example 2 :
//
//	Input : candidates = [2, 3, 5], target = 8,
//	A solution set is :
//[
//	[2, 2, 2, 2],
//	[2, 3, 3],
//	[3, 5]
//]
#include<vector>
using namespace std;
class Solution {
	vector<vector<int>> result;
	void findSum(vector<int>& candidates, int start, vector<int>& prev, int target) {
		if (target == 0) {
			result.push_back(prev);
		}
		else if (start < candidates.size() && target > 0) {
			for (int i = start; i < candidates.size(); i++) {
				prev.push_back(candidates[i]);
				findSum(candidates, i, prev, target - candidates[i]);
				prev.pop_back();
			}
		}
		return;

	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() > 0) {
			vector<int> prev;
			findSum(candidates, 0, prev, target);
		}
		return result;
	}
};