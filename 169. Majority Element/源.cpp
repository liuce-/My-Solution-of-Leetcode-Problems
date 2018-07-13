//Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//
//You may assume that the array is non - empty and the majority element always exist in the array.
//
//Example 1:
//
//Input: [3, 2, 3]
//	Output : 3
//	Example 2 :
//
//	Input : [2, 2, 1, 1, 1, 2, 2]
//	Output : 2
#include<vector>
#include<unordered_map>
using namespace std;
//o(n) space, o(n) time
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> map;
		for (auto i : nums)
			map[i]++;
		for (auto i : map) {
			if (i.second > nums.size() / 2)
				return i.first;
		}
	}
};

//o(1) space, o(1) time;
//There is only one majority element and this element outnumbers all of the rest element;
//source:https://leetcode.com/problems/majority-element/discuss/51613/O(n)-time-O(1)-space-fastest-solution
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int majority = nums[0];
		int count = 0;
		for (auto i : nums) {
			if (count == 0) {
				majority = i;
				count++;
			}
			else if (majority != i)
				count--;
			else
				count++;
		}
		return majority;
	}
};