//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.
//
//Example:
//
//Input:  [1, 2, 1, 3, 2, 5]
//	Output : [3, 5]
//	Note :
//
//	The order of the result is not important.So in the above example, [5, 3] is also correct.
//	Your algorithm should run in linear runtime complexity.Could you implement it using only constant space complexity ?
#include<vector>
#include<unordered_map>
using namespace std;

//o(n) time, O(n) space
class Solution2 {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_map<int, int> map;
		for (auto i : nums)
			map[i]++;
		vector<int> ans;
		for (auto i : map) {
			if (i.second == 1)
				ans.push_back(i.first);
		}
		return ans;
	}
};

//有了第一题的基本的思路，我们可以将数组分成两个部分，每个部分里只有一个元素出现一次，其余元素都出现两次。
//那么使用这种方法就可以找出这两个元素了。不妨假设出现一个的两个元素是x，y，那么最终所有的元素异或的结果就是res = x^y。
//并且res！=0，那么我们可以找出res二进制表示中的某一位是1。对于原来的数组，我们可以根据这个位置是不是1就可以将数组分成两个部分。
//x，y在不同的两个子数组中。而且对于其他成对出现的元素，要么在x所在的那个数组，要么在y所在的那个数组。
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto i : nums)
			res = res ^ i;

		int mask = 1;
		int s = res & 1;
		while ((res & 1) == 0) {
			mask = mask << 1;
			res = res >> 1;
		}

		int withOne = 0;
		int withoutOne = 0;

		for (auto i : nums) {
			if ((i&mask) == 0)
				withoutOne = withoutOne ^ i;
			else
				withOne = withOne ^ i;
		}
		return { withOne,withoutOne };
	}
};

