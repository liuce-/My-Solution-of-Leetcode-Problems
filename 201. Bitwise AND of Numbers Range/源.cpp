//Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//Example 1:
//
//Input: [5, 7]
//	Output : 4
//	Example 2 :
//
//	Input : [0, 1]
//	Output : 0

//Time limit exceeded
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int ans = m;
		for (int i = m + 1; i <= n; i++) {
			ans = ans & i;
		}
		return ans;
	}
};

class Solution {
public:
	int rangeBitwiseAnd(int _m, int _n) {
		unsigned int m = _m;
		unsigned int n = _n;
		unsigned int diff = m ^ n;
		unsigned int mask = 0;
		mask = ~mask;		
		while (diff != 0) {
			mask = mask << 1;
			diff = diff & mask;
		}
		unsigned int ans = (~(n^m))&mask&m;
		return (int)ans;
	}
};