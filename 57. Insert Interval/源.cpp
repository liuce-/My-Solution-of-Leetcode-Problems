//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//
//Input: intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
//	Output : [[1, 5], [6, 9]]
//	Example 2 :
//
//	Input : intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
//	Output : [[1, 2], [3, 10], [12, 16]]
//	Explanation : Because the new interval[4, 8] overlaps with[3, 5], [6, 7], [8, 10].

#include<vector>
#include<algorithm>
using namespace std;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		if (intervals.size() == 0) {
			res.push_back(newInterval);
		}
		else if (intervals.back().end < newInterval.start) {
			res = intervals;
			res.push_back(newInterval);
		}
		else {
			int i = 0;
			while (i< intervals.size() && intervals[i].end < newInterval.start) i++;
			res = vector<Interval>(intervals.begin(), intervals.begin() + i); 
			if (intervals[i].start > newInterval.end) {
				res.push_back(newInterval);
				res.insert(res.end(), intervals.begin() + i, intervals.end());
			}
			else {
				intervals[i].start = min(newInterval.start, intervals[i].start);
				intervals[i].end = max(newInterval.end, intervals[i].end);
				int j = i + 1;
				while (j < intervals.size() && intervals[i].end >= intervals[j].start) {
					intervals[i].end = max(intervals[j].end, intervals[i].end);
					j++;
				}
				res.push_back(intervals[i]);
				for (; j < intervals.size(); j++)
					res.push_back(intervals[j]);
			}
		}
		return res;
		
	}
};