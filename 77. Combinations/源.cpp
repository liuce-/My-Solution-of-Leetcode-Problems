//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//Example:
//
//Input: n = 4, k = 2
//	Output :
//	[
//		[2, 4],
//		[3, 4],
//		[2, 3],
//		[1, 2],
//		[1, 3],
//		[1, 4],
//	]
#include<vector>
using namespace std;
class Solution {
	vector<vector<int>> result;
	vector<int> current;
	void alterCapacity(int n, int k) {
		//C(k,n)
		int up = 1;
		int down = 1;
		for (int i = 0; i < k; i++) {
			up *= (n - i); 
			down *= (k - i);
		}
		result.reserve(up / down);
	}
	void combination(int start, int n, int k, vector<int>& prev) {
		if ( n-start >= k) {
			if (k == 0) {
				result.push_back(prev);
			}
			else {
				for (int i = start; i < n; i++) {
					prev.push_back(i);
					combination(i + 1, n, k - 1, prev);
					prev.pop_back();
				}
			}
		}
		return;
		
	}
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || n < 1 || k <= 0)
			return result;		
		alterCapacity(n, k);
		current.reserve(k);
		combination(1, n+1, k, current);
		return result;
	}
};
//c(n,k)= c(n,n-k)
class Solution2 {
	vector<vector<int>> result;
	vector<int> current;
	void alterCapacity(int n, int k) {
		//C(k,n)
		int up = 1;
		int down = 1;
		for (int i = 0; i < k; i++) {
			up *= (n - i);
			down *= (k - i);
		}
		result.reserve(up / down);
	}
	void restore(int n, int k) {
		if (result[0].size() == 0) {
			vector<int> s(n,1);
			for (int i = 0; i < n; i++) {
				s[i] = i + 1;
			}
			result[0]=s;
		}
		else {
			for (int i = 0; i < result.size(); i++) {
				vector<int> s;
				s.reserve(k);
				for (int j = 1, m=0; j < n + 1; j++) {
					if (m < n + 1 - k && result[i][m] == j) {
						m++;
						continue;
					}
					s.push_back(j);
				}
				result[i] = s;
			}
		}
	}
	void combination(int start, int n, int k, vector<int>& prev) {
		if (n - start >= k) {
			if (k == 0) {
				result.push_back(prev);
			}
			else {
				for (int i = start; i < n; i++) {
					prev.push_back(i);
					combination(i + 1, n, k - 1, prev);
					prev.pop_back();
				}
			}
		}
		return;

	}
public:
	vector<vector<int>> combine(int n, int k) {
		if (k > n || n < 1 || k <= 0)
			return result;
		alterCapacity(n, k);
		current.reserve(k);
		if (k > n / 2) {
			combination(1, n + 1, n - k, current);
			restore(n, k);
		}
		else
			combination(1, n + 1, k, current);
		return result;
	}
};