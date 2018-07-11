//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//Example 1:
//
//Input:  [0, 1, 2, 4, 5, 7]
//	Output : ["0->2", "4->5", "7"]
//	Explanation : 0, 1, 2 form a continuous range; 4, 5 form a continuous range.
//	Example 2:
//
//	Input:  [0, 2, 3, 4, 6, 8, 9]
//		Output : ["0", "2->4", "6", "8->9"]
//		Explanation : 2, 3, 4 form a continuous range; 8, 9 form a continuous range.
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if (nums.size() == 0)
			return ans;
		int left = nums[0];
		int right = nums[0];
		for (int i = 1; i < nums.size() + 1; i++) {
			if (i!=nums.size() && nums[i] - nums[i - 1] == 1)
				right = nums[i];
			else {
				if (left == right)
					ans.push_back(to_string(left));
				else
					ans.push_back(to_string(left) + "->" + to_string(right));
				if(i!=nums.size())
					left = right = nums[i];
			}
		}
		return ans;
	}
};