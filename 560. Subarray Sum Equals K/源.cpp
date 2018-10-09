//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//Input:nums = [1, 1, 1], k = 2
//	Output : 2
//	Note :
//	The length of the array is in range[1, 20, 000].
//	The range of numbers in the array is[-1000, 1000] and the range of the integer k is[-1e7, 1e7].
#include<vector>
#include<unordered_map>
using namespace std;
//cleanest
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int presum = 0;
		int result = 0;
		unordered_map<int, int> map;
		map[0]=1;
		for (int i = 0; i < nums.size(); i++) {
			presum += nums[i];
			result += map[presum - k];
			map[presum]++;
		}
		return result;

	}
};
//cleaner code
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int presum = 0;
		int result = 0;
		unordered_map<int, int> map;
		map.insert({ 0,1 });
		for (int i = 0; i < nums.size(); i++) {
			presum += nums[i];
			auto pair = map.find(presum - k);
			if (pair != map.end())
				result += pair->second;
			map[presum]++;
		}
		return result;

	}
};
//not clean, but easy to understand
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;
		vector<int> presum(nums.size(), 0);
		unordered_map<int, int> map;
		map.insert({ 0,1 });
		int result = 0;
		for (int i = 0; i < presum.size(); i++) {
			if (i == 0)
				presum[0] = nums[0];
			else
				presum[i] = nums[i] + presum[i - 1];
			auto pair = map.find(presum[i] - k);
			if (pair != map.end())
				result += pair->second;
			map[presum[i]]++;
		}
		return result;


	}
};
//the original version
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;
		vector<int> presum(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0)
				presum[0] = nums[0];
			else
				presum[i] = presum[i - 1] + nums[i];
		}
		unordered_map<int, int> map;
		map.insert({ 0,1 });
		int result = 0;
		for (int i = 0; i < presum.size(); i++) {
			auto pair = map.find(presum[i] - k);
			if (pair != map.end())
				result += pair->second;
			map[presum[i]]++;
		}
		return result;


	}
};