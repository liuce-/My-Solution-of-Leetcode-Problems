//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
//	Output : [[1, 6], [8, 10], [15, 18]]
//	Explanation : Since intervals[1, 3] and [2, 6] overlaps, merge them into[1, 6].
//	Example 2 :
//
//	Input : [[1, 4], [4, 5]]
//	Output : [[1, 5]]
//	Explanation : Intervals[1, 4] and [4, 5] are considerred overlapping.

#include<vector>
#include<algorithm>
using namespace std;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 class cmp {
 public:
	 bool operator()(Interval& a, Interval& b) {
		 if (a.start != b.start)
			 return a.start < b.start;
		 else
			 return a.end < b.end;
	 }
 };
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {		
		vector<Interval> res;
		if (intervals.size() == 0)
			return res;
		sort(intervals.begin(), intervals.end(), cmp());
		int i = 0;
		while (i < intervals.size()) {
			Interval& interval = intervals[i];
			while (i + 1 < intervals.size() && interval.end >= intervals[i + 1].start) {
				i++;
				if (interval.end < intervals[i].end)
					interval.end = intervals[i].end;
			}
			res.push_back(interval);
			i++;
		}
		return res;
	}
};