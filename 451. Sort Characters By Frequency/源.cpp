//Given a string, sort it in decreasing order based on the frequency of characters.
//
//Example 1:
//
//Input:
//"tree"
//
//Output :
//	"eert"
//
//	Explanation :
//	'e' appears twice while 'r' and 't' both appear once.
//	So 'e' must appear before both 'r' and 't'.Therefore "eetr" is also a valid answer.
//	Example 2 :
//
//	Input :
//	"cccaaa"
//
//	Output :
//	"cccaaa"
//
//	Explanation :
//	Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
//	Note that "cacaca" is incorrect, as the same characters must be together.
//	Example 3 :
//
//	Input :
//	"Aabb"
//
//	Output :
//	"bbAa"
//
//	Explanation :
//	"bbaA" is also a valid answer, but "Aabb" is incorrect.
//	Note that 'A' and 'a' are treated as two different characters.
#include<unordered_map>
#include<string>	
#include<algorithm>
using namespace std;
class compare {
public:
	bool operator()(pair<char, int> &a, pair<char,int> &b) {
		return a.second > b.second;
	}
};
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> map;
		for (auto c : s) {
			map[c]++;
		}
		vector<pair<char, int>> v(map.begin(), map.end());
		sort(v.begin(), v.end(), compare());
		string result(s.size(), ' ');
		int index = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].second; j++) {
				result[index] = v[i].first;
				index++;
			}
		}
		return result;
	}
};