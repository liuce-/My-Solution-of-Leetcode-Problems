//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
//
//Example :
//
//	Input : s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//
//	Output : ["AAAAACCCCC", "CCCCCAAAAA"]
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		unordered_map<unsigned int, int> frequency;
		unordered_map<char, unsigned int> dict = { {'A',0},{'T',1},{'C',2},{'G',3} };
		vector<char> revDict = { 'A','T','C','G' };

		unsigned int mask = 0xfffff;
		unsigned int current = 0;
		for (int i = 0; i < s.size();i++) {
			current = current << 2;
			current = current | dict[s[i]];
			if (i >= 9) {
				current = current & mask;
				frequency[current]++;
				//cout << s.substr(i - 9, 10) << " " << current << endl;
			}
		}
		for (auto i = frequency.begin(); i != frequency.end(); i++) {
			if (i->second >= 2) {
				string tmp;
				unsigned int mask2 = 3;
				unsigned int DNA = i->first;
				for(int j=0;j<10;j++) {
					tmp.push_back(revDict[DNA&mask2]);
					DNA = DNA >> 2;
				}
				reverse(tmp.begin(), tmp.end());
				ans.push_back(tmp);
			}
		}
		return ans;
	}
};