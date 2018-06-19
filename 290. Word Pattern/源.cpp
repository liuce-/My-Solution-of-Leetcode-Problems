//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.
//
//Example 1:
//
//Input: pattern = "abba", str = "dog cat cat dog"
//	Output : true
//	Example 2 :
//
//	Input : pattern = "abba", str = "dog cat cat fish"
//	Output : false
//	Example 3 :
//
//	Input : pattern = "aaaa", str = "dog cat cat dog"
//	Output : false
//	Example 4 :
//
//	Input : pattern = "abba", str = "dog dog dog dog"
//	Output : false
//	Notes :
//	You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//

#include<sstream>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		stringstream s(str);
		string value;
		unordered_map<char, string> map;
		unordered_map<string, char> map2;
		int i = 0;
		while (getline(s, value,' ')) {
			cout << value << endl;
			if (i >= pattern.size())
				return false;
			if (map.find(pattern[i]) == map.end() && map2.find(value) == map2.end()) {
				map.insert(make_pair(pattern[i], value));
				map2.insert(make_pair(value, pattern[i]));
			}
			else if (map[pattern[i]] != value || map2[value] != pattern[i])
				return false;
			i++;
		}
		return i==pattern.size();
	}
};
int main() {
	Solution s;
	cout<<s.wordPattern("abba", "dog dog dog dog");
	return 0;
}