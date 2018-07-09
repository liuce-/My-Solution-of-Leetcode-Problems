//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//Example 1:
//
//Input: numerator = 1, denominator = 2
//	Output : "0.5"
//	Example 2 :
//
//	Input : numerator = 2, denominator = 1
//	Output : "2"
//	Example 3 :
//
//	Input : numerator = 2, denominator = 3
//	Output : "0.(6)"

#include<string>
#include<unordered_map>
using namespace std;

class isEqual {
public:
	bool operator()(pair<int, int>& key1, pair<int, int>& key2) {
		return key1.first == key2.first && key1.second == key2.second;
	}
};
class hashFunc {
public:
	size_t operator()(pair<int, int>& key) {
		return hash<int>()(key.first)&hash<int>()(key.second);
	}
};
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string ans = to_string( numerator / denominator);
		//pair<int,int> first int: remain/denominator second int: remain%denominator. int: index of the first remain apperance
		unordered_map<pair<int,int>,int> map;
		int remain = numerator % denominator;
		if (remain != 0) {
			ans.push_back('.');
			while (remain != 0) {
				remain = remain * 10;	


			}
		}
		return ans;
	}
};