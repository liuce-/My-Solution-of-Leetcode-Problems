//198. House Robber
//You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//Example 1:
//
//Input: [1, 2, 3, 1]
//	Output : 4
//	Explanation : Rob house 1 (money = 1) and then rob house 3 (money = 3).
//	Total amount you can rob = 1 + 3 = 4.
//	Example 2 :
//
//	Input : [2, 7, 9, 3, 1]
//	Output : 12
//	Explanation : Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//	Total amount you can rob = 2 + 9 + 1 = 12.
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//自己的递归做法
class Solution {
	vector<int> result;
	int subrub(int start, int end, const vector<int>&nums) {
		if (start >= end)
			return 0;

		if (result[start] != -1) {
			return result[start];
		}

		int max = 0;
		for (int i = start; i < end; i++) {
			int temp = nums[i] + subrub(i + 2, end, nums);
			if (max < temp) {
				max = temp;
			}
		}
		result[start] = max;
		return max;
	}
public:
	int rob(vector<int>& nums) {
		int houseCount = nums.size();
		if (houseCount <= 0) {
			return 0;
		}
		result.clear();
		result.resize(houseCount, -1);
		
		return subrub(0, houseCount,nums);
	}
};
//视频中的递归做法
class Solution2 {
	vector<int> result;
	int subrub(int start, int end, const vector<int>&nums) {
		if (start >= end)
			return 0;

		if (result[start] != -1) {
			return result[start];
		}

		int temp1 = subrub(start+1,end,nums);
		int temp2 = subrub(start + 2, end, nums)+nums[start];

		return result[start] = max(temp1,temp2);
	}
public:
	int rob(vector<int>& nums) {
		int houseCount = nums.size();
		if (houseCount <= 0) {
			return 0;
		}
		result.clear();
		result.resize(houseCount, -1);

		return subrub(0, houseCount, nums);
	}
};
//动态规划

class Solution3 {
	int* result;
	
public:
	int rob(vector<int>& nums) {
		int houseCount = nums.size();
		if (houseCount <= 0) {
			return 0;
		}
		result = new int[3];
		result[0] = nums[0];
		result[1] = max(nums[0], nums[1]);
		for (int i = 2; i < houseCount; i++)
			result[i%3] = max(result[(i-2)%3]+nums[i], result[(i-1)%3]);
		
		
		return result[(houseCount-1)%3];
	}
};
int main() {
	vector<int> test = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	Solution s;
	cout << s.rob(test);
	system("pause");
}