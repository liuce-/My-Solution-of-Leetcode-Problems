//A peak element is an element that is greater than its neighbors.
//
//Given an input array nums, where nums[i] ¡Ù nums[i + 1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that nums[-1] = nums[n] = -¡Þ.
//
//Example 1:
//
//Input: nums = [1, 2, 3, 1]
//	Output : 2
//	Explanation : 3 is a peak element and your function should return the index number 2.
//	Example 2 :
//
//	Input : nums = [1, 2, 1, 3, 5, 6, 4]
//	Output : 1 or 5
//	Explanation : Your function can return either index number 1 where the peak element is 2,
//	or index number 5 where the peak element is 6.
//	Note :
//
//	Your solution should be in logarithmic complexity.
//
#include<vector>
using namespace std;
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0 && nums[i] > nums[i + 1])
				return 0;
			else if (i == nums.size() - 1 && nums[i] > nums[i - 1])
				return nums.size() - 1;
			else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
					return i;
			
		}
	}
};
//explanation:https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)/117565
//Most people have figured out the binary search solution but are not able to understand how its working. I will try to explain it simply. What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current). How does that guarantee the result? Think about it, there are 2 possibilities.a) rising slope has to keep rising till end of the array b) rising slope will encounter a lesser element and go down.
//In both scenarios we will have an answer.In a) the answer is the end element because we take the boundary as - INFINITY b) the answer is the largest element before the slope falls.Hope this makes things clearer.
//nums[start] always bigger than nums[start-1] and nums[end] always bigger than nums[end+1]

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int start = 0;
		int end = nums.size()-1;
		while (start < end) {
			int mid = (start + end) / 2;
			
			if (nums[mid] > nums[mid + 1])
				end = mid;
			else
				start = mid + 1;	
		}
		return start;

	}
};



