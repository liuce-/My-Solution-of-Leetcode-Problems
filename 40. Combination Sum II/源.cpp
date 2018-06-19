
//Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
//	A solution set is :
//[
//	[1, 7],
//	[1, 2, 5],
//	[2, 6],
//	[1, 1, 6]
//]
//Example 2:
//
//Input: candidates = [2, 5, 2, 1, 2], target = 5,
//	A solution set is :
//	   [
//		   [1, 2, 2],
//		   [5]
//	   ]
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	vector<vector<int>> result;
	vector<bool> visited;
	void findSum(vector<int>& candidates, int start, vector<int>& prev, int target) {
		if (target == 0) {
			result.push_back(prev);
		}
		else if (start < candidates.size() && target>0) {
			for (int i = start; i < candidates.size(); i++) {
				if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1])
					continue;
				prev.push_back(candidates[i]);
				visited[i] = true;
				findSum(candidates, i + 1, prev, target - candidates[i]);
				visited[i] = false;
				prev.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.size() > 0) {
			sort(candidates.begin(), candidates.end(), less<int>());
			visited.resize(candidates.size(), false);
			vector<int> prev;
			findSum(candidates, 0, prev, target);
		}
		return result;
	}
};