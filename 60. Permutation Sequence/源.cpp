//The set[1, 2, 3, ..., n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note:
//
//Given n will be between 1 and 9 inclusive.
//Given k will be between 1 and n!inclusive.
//Example 1 :
//
//	Input : n = 3, k = 3
//	Output : "213"
//	Example 2 :
//
//	Input : n = 4, k = 9
//	Output : "2314"
#include<string>
#include<vector>	
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		int pTable[10] = { 1 };
		for (int i = 1; i <= 9; i++) {
			pTable[i] = i * pTable[i - 1];
		}
		string result;
		vector<char> numSet{'1','2','3','4','5','6','7','8','9'};
		while (n > 0) {
			int temp = (k - 1) / pTable[n - 1];
			result += numSet[temp];
			numSet.erase(numSet.begin() + temp);
			k = k - temp * pTable[n - 1];
			n--;
		}
		return result;
	}

};