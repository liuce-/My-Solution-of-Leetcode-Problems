//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
//The above elevation map is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.Thanks Marcos for contributing this image!
//
//Example:
//
//Input: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//	Output : 6
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0)
			return 0;
		int rocks = 0;		
		int total = 0;		
		int left = 0;
		int right = height.size() - 1;
		int lastHeight = 0;
		while (left <= right) {
			total += min(height[left] - lastHeight, height[right] - lastHeight)*(right - left + 1);
			if (height[left] < height[right]) {
				lastHeight = height[left];
				while (left<=right && height[left] <= lastHeight)left++;
			}
			else {
				lastHeight = height[right];
				while (right>=left && height[right] <= lastHeight) right--;
			}
		}
		for (auto h : height)
			rocks += h;
		return total - rocks;		
	}
};
int main() {
	Solution s;
	vector<int> testcase = { 1,1 };
	cout<<s.trap(testcase);
	return 0;
}