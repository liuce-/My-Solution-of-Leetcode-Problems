//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.Return the maximum product you can get.
//
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//Note: You may assume that n is not less than 2 and not larger than 58.
//
//f(n)=max{n/2*(n-n/2),1*f(n-1),2*f(n-2), ... , n/2*f(n-n/2));
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		if (n < 1)
			return 0;

		vector<int> result(n+1, 0);
		result[1] = 1;

		for (int i = 2; i <= n; i++) {

			int max = i/2*(i-i/2);
			for (int sub = 1; sub <= i / 2; sub++) {
				if (sub * result[i - sub] > max)
					max = sub * result[i - sub];
			}
			result[i] = max;
		}
		return result[n];
	}
};