//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Note:
//
//All numbers will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : k = 3, n = 7
//	Output : [[1, 2, 4]]
//	Example 2 :
//
//	Input : k = 3, n = 9
//	Output : [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
#include<vector>
using namespace std;
class Solution {
	vector<vector<int>> result;
	void findSum(int k, int target, int start, vector<int>& prev) {
		if (target == 0 && k==0)
			result.push_back(prev);
		else if (start < 10 && target >= 0 && k > 0 ) {
			for (int i = start; i < 10; i++) {
				prev.push_back(i);
				findSum(k - 1, target - i, i + 1, prev);
				prev.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k > 0 && n > 0) {
			vector<int> prev;
			findSum(k, n, 1, prev);

		}
		return result;
	}
};