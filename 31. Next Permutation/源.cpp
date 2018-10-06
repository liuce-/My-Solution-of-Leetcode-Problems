//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place and use only constant extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//
//1, 2, 3 ¡ú 1, 3, 2
//3, 2, 1 ¡ú 1, 2, 3
//1, 1, 5 ¡ú 1, 5, 1
#include<vector>
using namespace std;
class Solution {
	void reverse(vector<int>& nums, int left, int right) {
		while (left < right) swap(nums[left++], nums[right--]);

	}
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		int pos = nums.size() - 2;
		while (pos >= 0 && nums[pos] >= nums[pos + 1])pos--;
		if (pos == -1)
			reverse(nums, 0, nums.size() - 1);
		else {
			int target = pos + 1;
			while (target<nums.size() && nums[pos] < nums[target]) target++;
			target--;
			swap(nums[target], nums[pos]);
			reverse(nums, pos + 1, nums.size() - 1);
		}
	}
};