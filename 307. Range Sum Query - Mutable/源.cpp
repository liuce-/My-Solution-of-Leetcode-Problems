//Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.
//
//Example:
//
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//Note:
//
//The array is only modifiable by the update function.
//You may assume the number of calls to update and sumRange function is distributed evenly.
#include<vector>
using namespace std;
class NumArray {
	vector<int> sum;
	vector<int> num;
public:
	NumArray(vector<int> nums): sum(nums.size(),0),num(nums) {
		for (int i = 0; i < nums.size(); i++) {
			sum[i] = i == 0 ? nums[0] : nums[i] + sum[i - 1];
		}

	}

	void update(int i, int val) {
		for (int j = i; j < sum.size(); j++)
			sum[j] = sum[j] - num[i] + val;
	}

	int sumRange(int i, int j) {
		return i==0?sum[j] : sum[j] - sum[i - 1];
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/