//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero.
//
//Example 1:
//
//Input: dividend = 10, divisor = 3
//	Output : 3
//	Example 2 :
//
//	Input : dividend = 7, divisor = -3
//	Output : -2
//	Note :
//
//	Both dividend and divisor will be 32 - bit signed integers.
//	The divisor will never be 0.
//	Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
#include<algorithm>

//TLE
class Solution {
public:
	int divide(int dividend, int divisor) {
		long long int ldividend = dividend;
		long long int ldivisor = divisor;
		
		if (divisor == 0)
			throw "divisor is zero!";
		ldividend = abs(ldividend);
		ldivisor = abs(ldivisor);
		long long int flag = dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0 ? 1 : -1;
		long long int res = 0;

		if (ldivisor == 1) {
			res = ldividend;
		}
		else {
			while ((ldividend -= ldivisor) >= 0) {
				res++;
			}
		}

		res = res * flag;
		if (res > INT_MAX || res < INT_MIN)
			return INT_MAX;
		else
			return (int)res;
	}
};
int main() {
	Solution s;
	s.divide(10, 0);
	return 0;
}

//