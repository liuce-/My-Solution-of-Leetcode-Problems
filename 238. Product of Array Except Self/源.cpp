//Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Example:
//
//Input:  [1, 2, 3, 4]
//	Output : [24, 12, 8, 6]
//	Note : Please solve it without division and in O(n).
//
//	Follow up :
//		Could you solve it with constant space complexity ? (The output array does not count as extra space for the purpose of space complexity analysis.)
//
#include<vector>
using namespace std;
//with division
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int zeroCount = 0;
		int product = 1;
		for (int i = 0; i < nums.size(); i++) {
			product = product * nums[i];
			if (nums[i] == 0)
				zeroCount++;
		}
		vector<int> res(nums.size(),0);
		if (zeroCount == 1) {
			int zeroIndex = 0;
			int product = 1;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == 0)
					zeroIndex = i;
				else
					product = product * nums[i];
			}
			res[zeroIndex] = product;
		}
		else if (product != 0) {
			for (int i = 0; i < res.size(); i++) 
				res[i] = product / nums[i];
		}
		return res;
	}
};
//without division,O(N) space
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> rightProduct(nums.size(), 1);
		vector<int> leftProduct(nums.size(), 1);
		for (int i = 1; i < leftProduct.size(); i++) 
			leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
		for (int i = rightProduct.size() - 2; i >= 0; i--)
			rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
		
		vector<int> ans(nums.size());
		for (int i = 0; i < ans.size(); i++)
			ans[i] = leftProduct[i] * rightProduct[i];
		return ans;
	}
};
//without division, O(1) space
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans(nums.size(),1);//rightProduct
		for (int i = nums.size() - 2; i >= 0; i--)
			ans[i] = ans[i + 1] * nums[i + 1];

		int lastNumber = nums[0];
		nums[0] = 1;
		for (int i = 1; i < nums.size(); i++) {
			int tmp = nums[i];
			nums[i] = nums[i - 1] * lastNumber;
			lastNumber = tmp;
		}

		for (int i = 0; i <ans.size(); i++) 
			ans[i] = ans[i] * nums[i];
		return ans;
	}
};