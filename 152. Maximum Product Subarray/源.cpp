//Given an integer array nums, find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//Example 1:
//
//Input: [2, 3, -2, 4]
//	Output : 6
//	Explanation : [2, 3] has the largest product 6.
//	Example 2 :
//
//	Input : [-2, 0, -1]
//	Output : 0
//	Explanation : The result cannot be 2, because[-2, -1] is not a subarray.
#include<vector>
#include<algorithm>
using namespace std; 
class Solution {
	int maxValue(vector<int>& nums, int start, int end) {//[start,end)
		if (start == end)
			return INT_MIN;
		vector<int> res(end - start, 0);
		vector<int> negIndex;
		res[0] = nums[start];
		if (res[0] < 0)
			negIndex.push_back(0);
		for (int j=1,i = start+1; i <end; j++,i++) {
			res[j] = nums[i] * res[j - 1];
			if (nums[i] < 0)
				negIndex.push_back(j);
		}
		if (res.back() > 0 )
			return res.back();
		else {
			int ans = res.back();
			for (auto index : negIndex) {
				if (index - 1 >= 0)
					ans = max(ans, res[index - 1]);
				if (index == res.size() - 1)
					continue;
				ans = max(ans, res.back() / res[index]);
				ans = max(ans, nums[index+start]);
			}
			return ans;
		}

	}
public:
	int maxProduct(vector<int>& nums) {
		int ans = INT_MIN;
		int start = 0;
		int end = 0;
		while (end <= nums.size()) {

			if (nums[end] == 0) {
				ans = max(0, ans);
				ans = max(ans, maxValue(nums, start, end));
				start = end + 1;
			}
			else if (end == nums.size()) {
				ans = max(ans, maxValue(nums, start, end));
			}
			end++;
		}
		return ans;
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		// store the result that is the max we have found so far
		int r = nums[0];

		// imax/imin stores the max/min product of
		// subarray that ends with the current number nums[i]
		for (int i = 1, imax = r, imin = r; i < nums.size(); i++) {
			// multiplied by a negative makes big number smaller, small number bigger
			int oldMax = imax;
			int oldMin = imin;
			// max/min product for the current number is either the current number itself
			// or the max/min by the previous number times the current one
			imax = max(nums[i], max(oldMin*nums[i], oldMax * nums[i]));
			imin = min(nums[i], min(oldMax*nums[i], oldMin * nums[i]));

			// the newly computed max value is a candidate for our global result
			r = max(r, imax);
		}
		return r;
	}
};


int main() {
	Solution s;
	vector<int> asdf = {-2};
	auto res =s.maxProduct(asdf);
	return 0;
}