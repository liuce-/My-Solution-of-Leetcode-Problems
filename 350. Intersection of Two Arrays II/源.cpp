//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2, 2].
//
//Note :
//	Each element in the result should appear as many times as it shows in both arrays.
//	The result can be in any order.
//	Follow up :
//What if the given array is already sorted ? How would you optimize your algorithm ?
//What if nums1's size is small compared to nums2's size ? Which algorithm is better ?
//What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once ?
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> map1, map2;
		for (auto i : nums1) map1[i]++;
		for (auto i : nums2) map2[i]++;
		vector<int> result;
		for (auto i = map1.begin(); i != map1.end(); i++) {
			int count = min(i->second, map2[i->first]);
			for (int j = 0; j < count; j++)
				result.push_back(i->first);
		}
		return result;

	}
};

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> map;
		vector<int> result;
		for (auto i = nums1.begin(); i != nums1.end(); i++) {
			auto t = map.find(*i);
			if (t == map.end()) {
				map.insert(make_pair(*i, 1));
			}
			else {
				t->second++;
			}
		}
		for (auto i = nums2.begin(); i != nums2.end(); i++) {
			auto j = map.find(*i);
			if (j != map.end()) {
				result.push_back(j->first);
				j->second--;
				if (j->second == 0)
					map.erase(j);
			}
		}
		return result;

	}
};