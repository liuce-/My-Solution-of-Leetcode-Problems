//Given a non - empty array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//
//Example 1 :
//
//	Input : [2, 2, 1]
//	Output : 1
//	Example 2 :
//
//	Input : [4, 1, 2, 1, 2]
//	Output : 4
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> set;
		for (int i = 0; i<nums.size(); i++) {
			if (set.find(nums[i]) == set.end())
				set.insert(nums[i]);
			else
				set.erase(nums[i]);
		}
		return *(set.begin());
	}
}; //
//Òì»ò
//If we take XOR of zero and some bit, it will return that bit
//a¨’0 = a
//If we take XOR of two same bits, it will return 0
//a¨’a = 0
//a¨’b¨’a = (a¨’a)¨’b = 0¨’b = b
//So we can XOR all bits together to find the unique number.


int singleNumber(int A[], int n) {
	int result = 0;
	for (int i = 0; i<n; i++)
	{
		result ^= A[i];
	}
	return result;
}
