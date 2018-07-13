//Write a program to find the n - th ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
//Example:
//
//Input: n = 10
//	Output : 12
//	Explanation : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//	Note :
//
//	1 is typically treated as an ugly number.
//	n does not exceed 1690.
#include<queue>
#include<unordered_set>
using namespace std;
//heap nlogn
class Solution {
	vector<int> data;
	unordered_set<int> set;
	priority_queue<int, vector<int>, greater<int>> queue;
	void insert(int i,int x) {//logn
		if (i < INT_MAX / x && set.find(i*x) == set.end()  ) {
			set.insert(i*x);//1
			queue.push(i*x);//logn
		}
	}
public:
	int nthUglyNumber(int n) {
		queue.push(1);
		set.insert(1);
		data.reserve(n + 1);
		while (data.size() < n) {
			int top = queue.top();
			queue.pop();//logn
			set.erase(top);//1
			data.push_back(top);//1
			if (data.size() + queue.size() < 2 * n) {
				insert(top , 2);//logn
				insert(top , 3);
				insert(top , 5);
			}
		}
		return data[n-1];
	}
};

//O(N)
//https://leetcode.com/problems/ugly-number-ii/discuss/69368/Elegant-C++-Solution-O(N)-space-time-with-detailed-explanation.
struct Solution {
	int nthUglyNumber(int n) {
		vector <int> results(1, 1);
		int i = 0, j = 0, k = 0;
		while (results.size() < n)
		{
			results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
			if (results.back() == results[i] * 2) ++i;
			if (results.back() == results[j] * 3) ++j;
			if (results.back() == results[k] * 5) ++k;
		}
		return results.back();
	}
};

int main() {
	Solution s;
	auto res = s.nthUglyNumber(1690);
	return 0;
}