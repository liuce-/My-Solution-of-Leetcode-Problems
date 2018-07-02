//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Return 0 if the array contains less than 2 elements.
//
//Example 1:
//
//Input: [3, 6, 9, 1]
//	Output : 3
//	Explanation : The sorted form of the array is[1, 3, 6, 9], either
//				  (3, 6) or (6, 9) has the maximum difference 3.
//	Example 2 :
//
//	Input : [10]
//	Output : 0
//	Explanation : The array contains less than 2 elements, therefore return 0.
//	Note :
//
//	You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
//	Try to solve it in linear time / space.
#include<vector>
#include<algorithm>
using namespace  std;
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int minNumber = nums[0];
		int maxNumber = nums[0];
		for (auto i : nums) {
			minNumber = min(i, minNumber);
			maxNumber = max(i, maxNumber);
		}

		for (auto i : nums) {
			if (i > minNumber && i < maxNumber) {
				if (i - minNumber > maxNumber - i)
					maxNumber = i;
				else
					minNumber = i;				
			}
		}
		int res = maxNumber - minNumber;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] > minNumber && nums[i] < maxNumber) {
				if (nums[i] - minNumber > maxNumber - nums[i])
					maxNumber = nums[i];
				else
					minNumber = nums[i];
			}
		}
		res = max(res, maxNumber - minNumber);
		return res;
	}
};