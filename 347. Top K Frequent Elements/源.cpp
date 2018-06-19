//Given a non - empty array of integers, return the k most frequent elements.
//
//For example,
//Given[1, 1, 1, 2, 2, 3] and k = 2, return[1, 2].
//
//Note:
//You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//pair<int,int> first:frequency second,nums;
		priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
		//int,int first:num, second:frequency
		unordered_map<int, int> frequency;
		for (int i = 0; i < nums.size(); i++) {
			if (frequency.find(nums[i]) == frequency.end())
				frequency[nums[i]] = 1;
			else
				frequency[nums[i]]++;
		}
		//
		auto j = frequency.begin();
		
		for (int i = 0; i < k; i++) {
			q.push(make_pair((*j).second, (*j).first));
			j++;
		}
		for (; j != frequency.end(); j++) {
			if (q.top().first < (*j).second) {
				q.pop();
				q.push(make_pair((*j).second, (*j).first));
			}
		}

		vector<int> result(k);
		for (int j = k - 1; j >= 0; j--) {
			result[j] = q.top().second;
			q.pop();
		}
		return result;
				
	}
};