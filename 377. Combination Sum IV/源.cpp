//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are :
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//Follow up :
//What if negative numbers are allowed in the given array ?
//How does it change the problem ?
//What limitation we need to add to the question to allow negative numbers ?
//
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//f(n)=	|	1, if(n==0)
//		|	0, if(n<0)
//		|	f(n-nums[0])+f(n-nums[1])+f(n-nums[2])+....+f(n-nums[nums.size()-1]), if(n>0)
//better solution
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int size = nums.size();
		vector<int> result(target + 1, 0);
		sort(nums.begin(), nums.end(), less<int>());
		result[0] = 1;
		for (int i = 0; i < target+1; i++) {
			for (int j = 0; j<nums.size() && nums[j] <= i; j++) {
				result[i] += result[i-nums[j]];
			}
		}

		return result[target];
	}
};
class Solution2 {
	vector<int> result;
public:
	int helper(vector<int>&nums, int target) {
		if (target < 0) {
			return 0;
		}

		if (result[target] != -1)
			return result[target];
		
		int temp = 0;
		for (int i = 0; i < nums.size(); i++)
			temp += helper(nums, target - nums[i]);
		return result[target] = temp;

	}
	int combinationSum4(vector<int>& nums, int target) {
		result.resize(target + 1, -1);
		result[0] = 1;
		return helper(nums,target);
	}
};
int main() {
	Solution2 s;
	vector<int> test = { 1,2,3 };
	cout<<s.combinationSum4(test, 4);
	return 0;
}
