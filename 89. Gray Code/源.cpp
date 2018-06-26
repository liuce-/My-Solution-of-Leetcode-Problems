//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//Example 1:
//
//Input: 2
//	Output : [0, 1, 3, 2]
//	Explanation :
//	00 - 0
//	01 - 1
//	11 - 3
//	10 - 2
//
//	For a given n, a gray code sequence may not be uniquely defined.
//	For example, [0, 2, 3, 1] is also a valid gray code sequence.
//
//	00 - 0
//	10 - 2
//	11 - 3
//	01 - 1
//	Example 2:
//
//   Input: 0
//	   Output : [0]
//	   Explanation : We define the gray code sequence to begin with 0.
//	   A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
//	   Therefore, for n = 0 the gray code sequence is[0].
#include<vector>
using namespace std;
class Solution {
	vector<int> prefix{ 0,1,1,0 };

public:
	vector<int> grayCode(int n) {
		if (n == 0)
			return vector<int>{0};
		auto prevRes=grayCode(n - 1);
		vector<int> ans(prevRes.size() * 2);
		for (int i = 0; i < prevRes.size();i++) {
			ans[2*i] = prefix[(2 * i) % 4] << (n - 1) | prevRes[i];
			ans[2*i + 1] = prefix[(2 * i + 1) % 4] << (n - 1) | prevRes[i];
		}
		return ans;
	}
};
int main() {
	Solution s;
	auto res = s.grayCode(2);
	return 0;
}