//Given an integer array of size n, find all elements that appear more than ⌊ n / 3 ⌋ times.
//
//Note: The algorithm should run in linear time and in O(1) space.
//
//	Example 1 :
//
//	Input : [3, 2, 3]
//	Output : [3]
//	Example 2 :
//
//	Input : [1, 1, 1, 3, 3, 2, 2, 2]
//	Output : [1, 2]
#include<vector>
#include<unordered_map>
using namespace std;

//o(n) time, o(n) space;
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> map;
		vector<int> ans;
		for (auto i : nums)
			map[i]++;
		for (auto i = map.begin(); i != map.end(); i++) {
			if (i->second > nums.size() / 3)
				ans.push_back(i->first);
		}
		
		return ans;
	}
};

//o(n) time, o(1) space;
//at most 2 elements
class Solution {
	int count(vector<int>& nums, int num) {
		int cnt = 0;
		for (auto i : nums) {
			if (i == num)
				cnt++;
		}
		return cnt;
	}
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int>map;
		vector<int> res;

		for (auto i:nums) {
			if (map.size() < 2)
				map[i]++;
			else {
				if (map.find(i)==map.end()){
					if (map.begin()->second == 0) {
						map.erase(map.begin());
						map[i] = 1;
					}
					else if ((++map.begin())->second == 0) {
						map.erase(++map.begin());
						map[i] = 1;
					}
					else {
						map.begin()->second--;
						(++map.begin())->second--;
					}
				}
				else {
					map[i]++;
				}
			}
		}
		if (map.size() == 0) {
			return res;
		}
		else if (map.size() == 1)
			return { map.begin()->first };
			 
		int first = map.begin()->first;
		int second = (++map.begin())->first;
		if (count(nums, first) > nums.size() / 3)
			res.push_back(first);
		if (count(nums, second) > nums.size() / 3)
			res.push_back(second);
		
		return res;
	}
};