//Implement pow(x, n), which calculates x raised to the power n(xn).
//
//Example 1:
//
//Input: 2.00000, 10
//	Output : 1024.00000
//	Example 2 :
//
//	Input : 2.10000, 3
//	Output : 9.26100
//	Example 3 :
//
//	Input : 2.00000, -2
//	Output : 0.25000
//	Explanation : 2 - 2 = 1 / 22 = 1 / 4 = 0.25
//	Note :
//
//	-100.0 < x < 100.0
//	n is a 32 - bit signed integer, within the range[−231, 231 − 1]
#include<algorithm>
class Solution {
public:
	double myPow(double x, int _n) {
		long long int n = _n;
		bool negative = n < 0;
		n = abs(n);
		if (_n == 0)
			return x == 0 ? 0 : 1;
		if (x == 1)
			return x;
		if (x == -1)
			return n% 2 == 0 ? 1 : -1;

		double ans = x;
		long long int cur = 1;
		while (cur * 2 <= n) {	
			cur = cur * 2;
			ans = ans * ans;
			if (ans == 0)
				break;
		}
		while (cur != n && ans !=0) {
			ans = ans * x;
			cur++;
		}
		return negative?1/ans:ans;
	}
};