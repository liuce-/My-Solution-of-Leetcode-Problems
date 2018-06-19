//
//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note :
//
//	The solution set must not contain duplicate triplets.
//
//	Example :
//
//	Given array nums = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]

#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size()-2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int target = -nums[i];
			int left = i + 1;//avoid the dup
			int right = nums.size() - 1;
			while (left < right) {
				if (left > i + 1 && right < nums.size() - 1 && nums[left] == nums[left - 1] && nums[right] == nums[right + 1]) {//avoid the dup
					left++;
					right--;
				}
				else if (nums[left] + nums[right] < target)//sum is smaller than the target. move the left ptr to make it bigger
					left++;
				else if (nums[left] + nums[right] > target)//sum is bigger than the target. move the right ptr to make it smaller
					right--;
				else{
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					left++;
					right--;
				}
			}

		}
		return result;
		
	}
};
int main() {
	Solution s;
	vector<int> testcase = {0, 2, 2, 3, 0, 1, 2, 3, -1, -4, 2};
	s.threeSum(testcase);
	return 0;
}