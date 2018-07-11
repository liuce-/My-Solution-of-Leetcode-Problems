//Design a data structure that supports the following two operations :
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a - z or ..A.means it can represent any one letter.
//
//Example :
//
//	addWord("bad")
//	addWord("dad")
//	addWord("mad")
//	search("pad") -> false
//	search("bad") -> true
//	search(".ad") -> true
//	search("b..") -> true
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class WordDictionary {
public:
	unordered_map<size_t, unordered_set<string>>  sizeString;
	unordered_set<string> stringSet;
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		sizeString[word.size()].insert(word);
		stringSet.insert(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		bool containDot = false;
		for (auto c : word)
			if (c == '.') {
				containDot = true;
				break;
			}
		if (containDot) {
			unordered_set<string>& set = sizeString[word.size()];
			bool isMatch = false;
			for (const string& str : set) {
				bool currentStatus = true;
				for (int i = 0; i < str.size(); i++) {
					if (word[i] != '.'&& word[i] != str[i]) {
						currentStatus = false;
						break;
					}
				}
				if (currentStatus) {
					isMatch = true;
					break;
				}
			}
			return isMatch;
		}
		else
			return stringSet.find(word) != stringSet.end();
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/