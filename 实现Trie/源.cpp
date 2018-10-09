//Implement a trie with insert, search, and startsWith methods.
//
//Example:
//
//Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // returns true
//trie.search("app");     // returns false
//trie.startsWith("app"); // returns true
//trie.insert("app");
//trie.search("app");     // returns true
//Note:
//
//You may assume that all inputs are consist of lowercase letters a - z.
//All inputs are guaranteed to be non - empty strings.
#include<vector>
#include<string>	
using namespace std;
class Trie {
public:
	bool isWord;
	vector<Trie*> next;

	/** Initialize your data structure here. */
	Trie() {
		next.resize(26, nullptr);
		isWord = false;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* current = this;
		for (int i = 0; i < word.size(); i++) {
			if (current->next[word[i] - 'a'] == nullptr)
				current->next[word[i] - 'a'] = new Trie();
			current = current->next[word[i] - 'a'];
		}
		current->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* current = this;
		for (int i = 0; i < word.size(); i++) {
			if (current->next[word[i] - 'a'] == nullptr)
				return false;
			current = current->next[word[i] - 'a'];
		}
		return current->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* current = this;
		for (int i = 0; i < prefix.size(); i++) {
			if (current->next[prefix[i] - 'a'] == nullptr)
				return false;
			current = current->next[prefix[i] - 'a'];
		}
		return true;

	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */