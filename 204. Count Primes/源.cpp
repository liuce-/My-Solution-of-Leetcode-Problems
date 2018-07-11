//Count the number of prime numbers less than a non - negative number, n.
//
//Example:
//
//Input: 10
//	Output : 4
//	Explanation : There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
#include<vector>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		vector<bool> data(n, true);
		for (size_t i = 2; i < data.size(); i++)
			if (data[i])
				for (size_t j = i; j*i < data.size(); j++)
					data[j*i] = false;							
		int count = 0;
		for (size_t i=2;i<data.size();i++)
			if (data[i])
				count++;
		return count;
	}
};
int main() {
	Solution s;
	auto res = s.countPrimes(499979);
	return 0;
}