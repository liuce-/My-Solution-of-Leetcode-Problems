//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {
		int size = nums.size();
		for (int i = 0; i != size-1; i++) {
			for (int j = i+1; j != size; j++) {
				if (nums[i] + nums[j] == target) {
					return vector<int>{i,j};
				}
			}
		}
		return vector<int>{-1};
	}//101 ms

	


};
#include<unordered_map>
class Solution {
public:
	
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> map;
		for (int i = 0; i < nums.size(); i++) {
			if (map.find(target - nums[i]) != map.end())
				return vector<int>{map[target - nums[i]], i};
			map[target - nums[i]] = i;
		}
		return vector<int>{-1};
	}
};

int main() {
	Solution s;
	vector<int> nums = { 3,2,4 };
	auto result = s.twoSum(nums, 6);
	for (auto i = result.begin(); i != result.end(); i++) {
		cout << *i << endl;
	}
	system("pause");
	return 0;
}