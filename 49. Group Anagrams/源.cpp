//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//	Output :
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
//	   Note :
//
//		   All inputs will be in lowercase.
//		   The order of your output does not matter.
#include<forward_list>
#include<vector>
#include<string>
#include<unordered_map>
#include<list>
#include<algorithm>
using namespace std;

class Solution {
	bool isAnagram(string& str1, string& str2) {
		if (str1.length() != str2.length())
			return false;

		unordered_map<char,int> set;
		for (auto c : str1)
			set[c]++;
		for (auto c : str2) {
			auto i = set.find(c);
			if (i == set.end())
				return false;
			else if (i->second < 1)
				return false;
			i->second--;
		}

		return true;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		
		list<forward_list<int>*> sets;
		for (int i = 0; i < strs.size(); i++) {
			sets.push_front(new forward_list<int>(1,i));
		}
		for (auto i = sets.begin(); i != sets.end(); i++) {			
			auto j = i;
			j++;
			while (j != sets.end()) {
				int index_i = (*i)->front();
				int index_j = (*j)->front();
				if (isAnagram(strs[index_i], strs[index_j])) {
					(*i)->splice_after((*i)->begin(), **j);
					auto temp = j;
					j++;
					sets.erase(temp);
				}
				else
					j++;
			}
		}
		
		vector<vector<string>> result(sets.size());
		auto j = sets.begin();
		for (int i = 0; i < result.size()&&j!=sets.end(); i++,j++) {
			for (auto k = (*j)->begin(); k != (*j)->end(); k++) {
				result[i].push_back(strs[*k]);
			}
		}
		return result;

	}
};
class comp {
public:
	bool operator()(string& str1, string& str2) {
		return str1.length() < str2.length();
	}
};
class hashFunc {
public:
	std::size_t operator()(const string &key) const
	{
		string str = key;
		sort(str.begin(), str.end());
		size_t k = 0;
		for (char c : str) {
			k = k * 26;
			k += c - 'a';
		}
		return k;
	}

};
class isEqual {
public:
	bool operator () (const string &str1, const string  &str2) const
	{
		if (str1.length() != str2.length())
			return false;

		unordered_map<char, int> set;
		for (auto c : str1)
			set[c]++;
		for (auto c : str2) {
			auto i = set.find(c);
			if (i == set.end())
				return false;
			else if (i->second < 1)
				return false;
			i->second--;
		}

		return true;
	}
};
//95%
class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		sort(strs.begin(), strs.end(), comp());
		vector<vector<string>> result;
		unordered_map<string, vector<int>,hashFunc,isEqual> map;

		int curLength = strs[0].length();
		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].length() != curLength) {
				for (auto i : map) {
					vector<int>& res = i.second;
					vector<string> tmp(res.size());
					for (int i = 0; i < res.size(); i++) {
						tmp[i] = strs[res[i]];
					}
					result.push_back(tmp);
				}
				map.clear();
				curLength = strs[i].length();
			}
			map[strs[i]].push_back(i);
		}
		if (!map.empty()) {
			for (auto i : map) {
				vector<int>& res = i.second;
				vector<string> tmp(res.size());
				for (int i = 0; i < res.size(); i++) {
					tmp[i] = strs[res[i]];
				}
				result.push_back(tmp);
			}
		}
		return result;


	}
};
//
class Solution3 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		sort(strs.begin(), strs.end(), comp());
		vector<vector<string>> result;
		unordered_map<string, vector<string>> map;

		int curLength = strs[0].length();
		for (int i = 0; i < strs.size(); i++) {
			if (strs[i].length() != curLength) {
				for (auto itr : map)
					result.push_back(itr.second);
				map.clear();
				curLength = strs[i].length();
			}
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			map[tmp].push_back(strs[i]);
		}
		if (!map.empty()) {
			for (auto i : map) {
				result.push_back(i.second);
			}
		}
		return result;
	}
};
int main() {
	Solution3 s;
	vector<string> testCase = { "","b"};
	auto result = s.groupAnagrams(testCase);
	return 0;
}