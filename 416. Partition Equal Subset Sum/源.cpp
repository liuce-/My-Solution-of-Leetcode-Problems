//Given a non - empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//Example 1 :
//
//	Input : [1, 5, 11, 5]
//
//	Output : true
//
//	Explanation : The array can be partitioned as[1, 5, 5] and [11].
//	Example 2 :
//
//	Input : [1, 2, 3, 5]
//
//	Output : false
//
//	Explanation : The array cannot be partitioned into equal sum subsets.
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution2 {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		int size = nums.size();

		for (int i = 0; i < size; i++)
			sum += nums[i];
		if (sum % 2 != 0)
			return false;

		vector<bool> result(sum / 2 + 1, false);
		if (nums[0] < sum / 2 + 1)
			result[nums[0]] = true;

		for (int i = 1; i < size; i++) {
			for (int j = sum / 2; j >= 0; j--) {
				result[j] = result[j] || (j - nums[i] >= 0 ? result[j - nums[i]] : false);				
			}			
			if (result[sum / 2])
				return true;
		}
		
		return false;
	}
};
//beter solution 
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (!nums.size()) return true;
		int n = nums.size(), sum = 0;
		for (int each : nums) {
			sum += each;
		}
		if (sum % 2) return false;
		sort(nums.begin(), nums.end(), greater<int>());
		sum /= 2;
		if (nums[0]>sum) return false;
		return helper(nums, 0, sum);
	}
	bool helper(vector<int>& nums, int x, int sum) {
		if ((sum - nums[x]) == 0)
			return true;
		else if ((sum - nums[x])<0)
			return false;
		for (int i = x + 1; i<nums.size(); ++i) {
			if (helper(nums, i, sum - nums[x]))
				return true;
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> test = { 1,2,5 };
	cout<<s.canPartition(test)<<endl;
	return 0;
}