//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.Return the max sliding window.
//
//Example:
//
//Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3
//	Output : [3, 3, 5, 5, 6, 7]
//	Explanation :
//
//	Window position                Max
//	-------------- - ---- -
//	[1  3 - 1] - 3  5  3  6  7       3
//	1[3 - 1 - 3] 5  3  6  7       3
//	1  3[-1 - 3  5] 3  6  7       5
//	1  3 - 1[-3  5  3] 6  7       5
//	1  3 - 1 - 3[5  3  6] 7       6
//	1  3 - 1 - 3  5[3  6  7]      7
//	Note:
//	   You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
//
//		   Follow up :
//	   Could you solve it in linear time ?
//
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<int>heap;
		vector<int> res;
		int i = -1;
		int j = k-2;
		while (++j < nums.size()) {			
			if (heap.size() > 0 && heap.top() == nums[i]) {
				heap.pop();
				heap.push(nums[j]);
				res.push_back(heap.top());
			}else{
				auto start = nums.begin() + i + 1;
				auto end = start + k;
				vector<int> tmp(start,end);
				heap = priority_queue<int>(less<int>(), tmp);
				res.push_back(heap.top());
			}
			++i;
		}
		return res;
	}
};


class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		res.reserve(nums.size() - k + 1);
		int left = 0;
		int right = k - 1;
		while (right < nums.size()) {
			int maxNumber = INT_MIN;
			for (int i = left; i <= right; i++)
				maxNumber = max(nums[i], maxNumber);
			res.push_back(maxNumber);
			left++;
			right++;
		}
		return res;
	}
};

//https://leetcode.com/problems/sliding-window-maximum/discuss/65884/Java-O(n)-solution-using-deque-with-explanation
//不懂，有点类似84？ 84是在栈内维护一个递增的序列
//这个是维护了一个递减序列。同时保证序列的长度不超过K

class Solution3 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> windowMax;
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			while (!dq.empty() && dq.front() < i - k + 1)
				dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) 
				windowMax.push_back(nums[dq.front()]);
		}
		return windowMax;
	}
};

int main() {
	Solution3 s;
	vector<int> testcase = { 1,3,-1,-3,5,3,6,7 };
	s.maxSlidingWindow(testcase, 3);
	return 0;
}