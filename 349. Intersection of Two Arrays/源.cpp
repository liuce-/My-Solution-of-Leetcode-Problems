//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2].
//
//Note :
//	Each element in the result must be unique.
//	The result can be in any order.
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_set<int> s1(nums1.begin(), nums1.end());
		unordered_set<int> s2(nums2.begin(), nums2.end());
		for (auto i = s1.begin(); i != s1.end(); i++) {
			if (s2.find(*i) != s2.end()) {
				result.push_back(*i);
			}
		}

		return result;
	}
};