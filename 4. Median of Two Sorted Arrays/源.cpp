//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2 :
//	nums1 = [1, 2]
//	nums2 = [3, 4]
//
//	The median is(2 + 3) / 2 = 2.5

#include<vector>
#include<iostream>
using namespace std;

class Solution {

private:
	int findPos(vector<int>&s, int start, int end, int target) {
		int median = (start + end) / 2;
		if (start == end)
			return start;
		else if (s[median] == target)
			return median;
		else if (s[median] > target)
			return findPos(s, start, median-1,target);
		else if (s[median] < target)
			return findPos(s, median+1, end, target);
		
		return 0;
	}
	double findMedian(vector<int>&s1) {
		if (s1.size() % 2 == 0) {
			int median = (0 + s1.size() - 1) / 2;
			return (s1[median] + s1[median + 1]) / 2;
		}
		else
			return s1[s1.size() / 2];
			
	}
	double findMedian(vector<int>&s1, int s1start, int s1end, vector<int>&s2, int s2start, int s2end) {
		if (s1[s1end] <= s2[s2start]) {
			int totalsize = s1end - s1start + s2end - s2start + 2;
			int s1size = s1end - s1start + 1;
			int s2size = s2end - s2start + 1;
			double result = 0;
			if (totalsize % 2 == 0) {
				int medianPos1 = totalsize / 2;
				int medianPos2 = totalsize / 2+1;
				int result1 = 0;
				int result2 = 0;

				if (medianPos1 > s1size) {
					medianPos1 = medianPos1 - s1size + s2start - 1;
					result1 = s2[medianPos2];
				}
				else {
					medianPos1 = medianPos1 + s1start - 1;
					result1 = s1[medianPos1];
				}
				if (medianPos2 > s1size) {
					medianPos2 = medianPos2 - s1size + s2start - 1;
					result2 = s2[medianPos2];
				}
				else {
					medianPos2 = medianPos2 - s1size + s2start - 1;
					result2 = s1[medianPos2];
				}
				result = (result1 + result2) / 2;
			}
			else {
				int medianPos = totalsize / 2 + 1;
				if (medianPos > s1size) {
					medianPos = medianPos - s1size + s2start - 1;
					result = s1[medianPos];
				}
				else {
					medianPos = medianPos - s1size + s2start - 1;
					result = s2[medianPos];
				}			
				
			}
			return result;
			
		}
		else if (s1[s1end] >= s2[s2start] && s1[s1start] >= s2[s2start]) {
			if (s1end - s1start + s2end - s2start + 2 == 3)
			{
				if (s1end - s1start == 0)
					return s1[s1start];
				else
					return s2[s2start];
			}
			else if (s1end - s1start + s2end - s2start + 2 == 2)
			{
				return (s1[s1start] + s2[s2start]) / 2;
			}
			//²»¾«È·
			int s1median = (s1start + s1end) / 2;
			int s2median = (s2start + s2end) / 2;
			int s1subend = 0;
			int s2substart = 0;
			if (s2[s2median] >= s1[s1end]) {
				s1subend = s1end;
			}
			else {
				s1subend = findPos(s1, s1start, s1end, s2[s2median]);
			}
			if (s1[s1median] <= s2[s2start])
				s2substart = s2start;
			else {
				s2substart = findPos(s2, s2start, s2end, s1[s1median]);
			}
			return findMedian(s1, s1median, s1subend, s2, s2substart, s2median);
		}
		else {
			return findMedian(s2, s2start, s2end, s1, s1start, s1end);
		}
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0)
			return findMedian(nums2);
		if (nums2.size() == 0)
			return findMedian(nums1);

		return findMedian(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1);		
	}
};
int main() {
	vector<int> s1 = { 100001 };
	vector<int> s2 = { 100000 };
	Solution s;
	cout << s.findMedianSortedArrays(s1, s2) << endl;
	system("pause");
}