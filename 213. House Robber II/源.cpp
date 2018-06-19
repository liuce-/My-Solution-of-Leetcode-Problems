//You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed.All houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//Example 1:
//
//Input: [2, 3, 2]
//	Output : 3
//	Explanation : You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//	because they are adjacent houses.
//	Example 2 :
//
//	Input : [1, 2, 3, 1]
//	Output : 4
//	Explanation : Rob house 1 (money = 1) and then rob house 3 (money = 3).
//	Total amount you can rob = 1 + 3 = 4.

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//¶¯Ì¬¹æ»®

class Solution {
	int* result;

public:
	int rob(vector<int>& nums) {
		int houseCount = nums.size();
		if (houseCount <= 0) {
			return 0;
		}
		if (houseCount == 1) {
			return nums[0];
		}


		result = new int[3];
		result[0] = nums[0];
		result[1] = max(nums[0], nums[1]);
		for (int i = 2; i < houseCount - 1; i++)
			result[i % 3] = max(result[(i - 2) % 3] + nums[i], result[(i - 1) % 3]);
		int temp1 = result[(houseCount - 2) % 3];
		
		result[0] = nums[1];
		result[1] = max(nums[2], nums[1]);
		for (int i = 3; i < houseCount; i++)
			result[(i-1) % 3] = max(result[(i - 3) % 3] + nums[i], result[(i - 2) % 3]);
		int temp2 = result[(houseCount - 2) % 3];

		return max(temp1,temp2);
	}
};
int main() {
	vector<int> test = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	Solution s;
	cout << s.rob(test);
	system("pause");
}