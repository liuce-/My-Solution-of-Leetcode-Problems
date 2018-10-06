#include<vector>
using namespace std;
class Solution {
	int quickSelect(vector<int>& nums, int left, int right, int k) {//start: next element to check; end: next space to fill
		int start = left;
		int end = right - 1;
		int pivot = nums[right];
		while (start <= end) {
			if (nums[start] < pivot) {
				swap(nums[start], nums[end]);
				end--;
			}
			else {
				start++;
			}
		}
		swap(nums[right], nums[start]);
		if (start - left == k - 1)
			return nums[start];
		else if (start - left > k - 1)
			return quickSelect(nums, left, start - 1, k);
		else//start-left<k-1
			return quickSelect(nums, start + 1, right, k - (start - left + 1));
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() < k)
			return -1;
		return quickSelect(nums, 0, nums.size()-1, k);

	}
};

int main() {
	Solution s;
	vector<int> testcase = { 3,2,1,5,6,4 };
	auto result = s.findKthLargest(testcase, 2);
	return 0;
}