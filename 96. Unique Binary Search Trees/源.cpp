//Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
//Example:
//
//Input: 3
//	Output : 5
//	Explanation :
//	Given n = 3, there are a total of 5 unique BST's:
//
//	1         3     3      2      1
//	\       /     /      / \      \
//	3     2     1      1   3      2
//	/     /       \                 \
//	2     1         2                 3
#include<vector>
using namespace std;
class Solution {
	vector<int> data;
public:
	int numTrees(int n) {
		if (data.size() > n && data[n]!=0)
			return data[n];
		else if(data.size()<=n)
			data.resize(n + 1);

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int left = numTrees(i - 1);
			int right = numTrees(n - i);
			left = left == 0 ? 1 : left;
			right = right == 0 ? 1 : right;
			ans += left * right;
		}
		return data[n] = ans;
	}
};
int main() {
	Solution s;
	auto res = s.numTrees(3);
	return 0;
}