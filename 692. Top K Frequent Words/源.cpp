#include<string>
#include<queue>
#include<unordered_map>;
using namespace std;
class MyCompare {
public:
	bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
		if (a.first == b.first)
			return less<string>()(a.second, b.second);
		return a.first > b.first;
	}
};
class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> frequency;
		for (int i = 0; i < words.size(); i++)
			frequency[words[i]]++;

		priority_queue<pair<int, string>, vector<pair<int, string>>, MyCompare> heap;
		for (auto i = frequency.begin(); i != frequency.end(); i++) {
			heap.push(make_pair(i->second, i->first));
			if(heap.size()>k)	
			    heap.pop();
		}
		vector<string> result;
		while (!heap.empty()) {
			result.push_back(heap.top().second);
			heap.pop();
		}
		//sort(result.begin(),result.end());
		reverse(result.begin(),result.end());
		return result;

	}
};
int main() {
	Solution s;
	vector<string> testcase = { "i", "love", "leetcode", "i", "love", "coding" };
	s.topKFrequent(testcase, 2);
	return 0;
}