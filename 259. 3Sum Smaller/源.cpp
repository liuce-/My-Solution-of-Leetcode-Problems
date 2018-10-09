#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		if (nums.size() < 3)
			return 0;
		int result = 0;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (3 * nums[i] > target)
				break;
			int left = i + 1;
			int lastLeft = left;
			int right = nums.size() - 1;
			while (left < right) {
				while (left < right && nums[left] + nums[right] + nums[i] < target) left++;
				int m = right - lastLeft+1;
				int n = left - lastLeft;
				result += m * n - n * (n + 1) / 2;
				lastLeft = left;
				if (left == right)
					break;
				while (left<right && nums[left] + nums[right] + nums[i]>=target) right--;
				if (left == right) 					
					break;
				
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> testcase = { -2,0,1,3 };
	auto res =  s.threeSumSmaller(testcase,2);
	return 0;
}