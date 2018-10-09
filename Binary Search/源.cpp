#include<vector>
#include<algorithm>
using namespace std;
int binarySearch(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {//search target in [left, right]
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] > target)
			right = mid - 1;
		else//nums[mid]<target 
			left = mid + 1;

	}
	return -1;
}
int main() {
	vector<int> testcase = { 12,122,213,8976,234,1233,21,31,23,1231,12,32,3,4,45,5,5,6,7,8,9,0 };
	sort(testcase.begin(), testcase.end());
	auto res = binarySearch(testcase, 9);
	auto res2 = binarySearch(testcase, 2);
	return 0;
}