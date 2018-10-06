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
class MyCompare {
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>&b) {
		return a.second > b.second;
	}
};

class BestSolution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequency;
		for (auto number : nums)
			frequency[number]++;
		vector<list<int>> bucket(nums.size() + 1);
		for (auto freq : frequency)
			bucket[freq.second].push_front(freq.first);
		vector<int> result;
		for (auto i = bucket.rbegin(); i != bucket.rend(); i++) {
			result.insert(result.end(), i->begin(), i->end());
			if (result.size() >= k) {
				while (result.size() != k)
					result.pop_back();
				break;
			}
		}
		return result;
	}
};
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		for (auto number : nums)
			map[number]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> heap;//min heap
		for (auto i = map.begin(); i != map.end(); i++) {
			heap.push(*i);
			if (heap.size() > k)
				heap.pop();
		}
		list<int> result;
		while (heap.size() != 0) {
			result.push_front(heap.top().first);
			heap.pop();
		}
		return vector<int>(result.begin(), result.end());

	}
};
class BestSolution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequency;
		for (auto number : nums)
			frequency[number]++;
		vector<list<int>> bucket(nums.size() + 1);
		for (auto freq : frequency)
			bucket[freq.second].push_front(freq.first);
		vector<int> result;
		for (auto i = bucket.rbegin(); i != bucket.rend(); i++) {
			result.insert(result.end(), i->begin(), i->end());
			if (result.size() >= k) {
				while (result.size() != k)
					result.pop_back();
				break;
			}
		}
		return result;
	}
};