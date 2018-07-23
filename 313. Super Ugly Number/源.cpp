//Write a program to find the nth super ugly number.
//
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
//
//Example:
//
//Input: n = 12, primes = [2, 7, 13, 19]
//	Output : 32
//	Explanation : [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12
//	super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//	Note :
//
//	1 is a super ugly number for any given primes.
//	The given numbers in primes are in ascending order.
//	0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
//	The nth super ugly number is guaranteed to fit in a 32 - bit signed integer.
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//o(n*primes.size())
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> currentIndex(primes.size(), 0);
		vector<int> dp(1,1);
		while (dp.size() < n) {
			int nextdp = INT_MAX;
			for (int i = 0; i < primes.size(); i++)
				nextdp = min(nextdp, primes[i] * dp[currentIndex[i]]);
			dp.push_back(nextdp);
			for (int i = 0; i < primes.size(); i++)
				if (primes[i] * dp[currentIndex[i]] == nextdp)
					currentIndex[i]++;
		}
		return dp.back();

	}
};
//o(n*log(primes.size())
class Solution {
	class compare {
	public:
		bool operator()(pair<int, int>&a, pair<int, int> &b) {
			return greater<int>()(a.first, b.first);
		}
	};
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> currentIndex(primes.size(), 0);
		vector<int> dp(1, 1);
		priority_queue<pair<int,int>,vector<pair<int,int>>,compare> heap;
		for (int i = 0; i < primes.size(); i++) {
			heap.push({ primes[i], i});
		}

		while (dp.size() < n) {
			pair<int, int> top = heap.top();
			dp.push_back(top.first);			
			while (heap.top().first == top.first) {
				currentIndex[heap.top().second]++;
				heap.push({ primes[heap.top().second] * dp[currentIndex[heap.top().second]],heap.top().second });
				heap.pop();
			}
			
		}
		return dp.back();

	}
};