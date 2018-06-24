//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
//Example 1:
//
//Input: 4
//	Output : 2
//	Example 2 :
//
//	Input : 8
//	Output : 2
//	Explanation : The square root of 8 is 2.82842..., and since
//	the decimal part is truncated, 2 is returned.
class Solution {
public:
	int mySqrt(int _x) {
		long long int x = _x;//prevent overflow
		if (x == 1)
			return 1;
		long long int start = x % 2 == 0 ? 0 : 1;
		while (start*start < x)start += 2;
		return start*start==x?start:(start-1)*(start-1)<x?start-1:start - 2;
	}
};

//newton 
class Solution {
public:
	int mySqrt(int x) {
		long r = x;
		while (r*r > x)
			r = (r + x / r) / 2;
		return r;
	}
};

