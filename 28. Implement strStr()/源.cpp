//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//	Output : 2
//	Example 2 :
//
//	Input : haystack = "aaaaa", needle = "bba"
//	Output : -1
//	Clarification :
//
//	What should we return when needle is an empty string ? This is a great question to ask during an interview.
//
//	For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().
//
#include<string>
#include<vector>
using namespace std;
//o(n*m)
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;
		if (haystack.size() < needle.size())
			return -1;

		for (int i = 0; i<haystack.size(); i++) {
			if (haystack[i] == needle[0]) {
				int j = 0;
				for (; j<needle.size(); j++)
					if (i + j >= haystack.size() || haystack[i + j] != needle[j])
						break;
				if (j == needle.size()) return i;
			}
		}
		return -1;

	}
};


//kmp solution o(m+n)
class Solution2 {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;
		if (haystack.size() < needle.size())
			return -1;
		vector<int> array(needle.size(), 0);
		int i = 0;
		int j = 1;
		while (j < needle.size()) {
			if (needle[i] == needle[j]) {
				array[j] = i + 1;
				i++; j++;
			}
			else if (i != 0)
				i = array[i - 1];
			else 
				j++;
		}

		j = i = 0;
		while (j < needle.size() && i < haystack.size()) {
			if (haystack[i] == needle[j]) {
				j++;
				i++;
			}
			else if (j != 0) 
					j = array[j - 1];				
			else 
				i++;
		}

		return j == needle.size() ? i - needle.size() : -1;
	}
};
int main() {
	Solution2 s;
	s.strStr("aabaaabaaac",
		"aabaaac");
	return 0;
}