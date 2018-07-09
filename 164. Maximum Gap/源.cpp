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
		sort(nums.begin(), nums.end());
		int maxGap = 0;
		for (int i = 1; i < nums.size(); i++) 
			maxGap = max(maxGap, nums[i] - nums[i - 1]);
		return maxGap;	
	}
};

class Bucket {
public:
	bool used = false;
	int minval = numeric_limits<int>::max();        // same as INT_MAX
	int maxval = numeric_limits<int>::min();        // same as INT_MIN
};

//https://leetcode.com/problems/maximum-gap/solution/
int maximumGap(vector<int>& nums)
{
	if (nums.empty() || nums.size() < 2)
		return 0;

	int mini = *min_element(nums.begin(), nums.end()),
		maxi = *max_element(nums.begin(), nums.end());

	int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
	int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
	vector<Bucket> buckets(bucketNum);

	for (auto&& num : nums) {
		int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
		buckets[bucketIdx].used = true;
		buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
		buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
	}

	int prevBucketMax = mini, maxGap = 0;
	for (auto&& bucket : buckets) {
		if (!bucket.used)
			continue;

		maxGap = max(maxGap, bucket.minval - prevBucketMax);
		prevBucketMax = bucket.maxval;
	}

	return maxGap;
}