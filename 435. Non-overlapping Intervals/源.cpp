//Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non - overlapping.
//
//Note:
//You may assume the interval's end point is always bigger than its start point.
//Intervals like[1, 2] and [2, 3] have borders "touching" but they don't overlap each other.
//Example 1 :
//	Input : [[1, 2], [2, 3], [3, 4], [1, 3]]
//
//	Output : 1
//
//	Explanation : [1, 3] can be removed and the rest of intervals are non - overlapping.
//	Example 2 :
//	Input : [[1, 2], [1, 2], [1, 2]]
//
//	Output : 2
//
//	Explanation : You need to remove two[1, 2] to make the rest of intervals non - overlapping.
//	Example 3 :
//	Input : [[1, 2], [2, 3]]
//
//	Output : 0
//
//	Explanation : You don't need to remove any of the intervals since they're already non - overlapping.
/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class compare {
public:
	bool operator()(Interval& a, Interval& b) {
		return a.start < b.start;
	}
};
//dp
class Solution {
	bool isOverlapping(Interval& a, Interval& b) {
		return !((b.start >= a.end && b.end >= a.end) || (b.start <= a.start && b.end <= a.start));
	}
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), compare());
		int size = intervals.size();
		if (size == 0)
			return 0;
		vector<int> result(size,1);
		result[0] = 1;
		for (int i = 1; i < size; i++) {
			int max = 1;
			for (int j = 0; j < i; j++) {
				if (!isOverlapping(intervals[i],intervals[j])) {
					max = result[j] + 1>max?result[j]+1:max;
				}
			}
			result[i] = max;
		}
		return result.size() - result.back();
	}
};
//greedy

class compare2 {
public:
	bool operator()(Interval& a, Interval& b) {
		if (a.end != b.end)
			return a.end < b.end;
		else
			return a.start < b.start;
	}
};
class Solution {
	
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), compare2());
		int size = intervals.size();
		if (size == 0)
			return 0;		
		int result = 1;
		int prev = 0;
		for (int i = 1; i < size; i++) {
			if (intervals[i].start >= intervals[prev].end) {
				result++;
				prev = i;
			}			
		}
		return intervals.size() - result;
		
	}
};
int main() {
	Solution s;
	vector<Interval> test = { Interval(1,100),Interval(11,22),Interval(1,11),Interval(2,12) };
	cout<<s.eraseOverlapIntervals(test);
	return 0;
}