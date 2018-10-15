//Given two binary strings, return their sum(also a binary string).
//
//The input strings are both non - empty and contains only characters 1 or 0.
//
//Example 1:
//
//Input: a = "11", b = "1"
//	Output : "100"
//	Example 2 :
//
//	Input : a = "1010", b = "1011"
//	Output : "10101"
#include<string>
#include<algorithm>
#include<list>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int i = a.size() - 1;
		int j = b.size() - 1;
		int contribute = 0;
		while (i >= 0 || j >= 0) {
			int sum = 0;
			if (i >= 0 && j < 0) {
				sum = a[i] - '0' + contribute;
				i--;
			}
			else if (i < 0 && j >= 0) {
				sum = b[j] - '0' + contribute;
				j--;
			}
			else {
				sum = a[i] - '0' + b[j] - '0' + contribute;
				i--;
				j--;
			}
			contribute = sum / 2;
			sum = sum % 2;
			res.push_back(sum + '0');
		}
		if (contribute != 0)
			res.push_back(contribute + '0');
		reverse(res.begin(), res.end());
		return res;
	}
};
class Solution2 {
public:
	string addBinary(string a, string b) {
		list<char> res;
		int index1 = a.size() - 1;
		int index2 = b.size() - 1;
		char carry = 0;
		while (index1 >= 0 || index2 >= 0) {
			char tmp;
			if (index1 < 0)
				tmp = b[index2--] + carry - '0';
			else if (index2 < 0)
				tmp = a[index1--] + carry - '0';
			else
				tmp = a[index1--] + b[index2--] + carry - '0' - '0';
			carry = tmp / 2;
			tmp = tmp % 2;
			res.push_front(tmp + '0');
		}
		if (carry != 0)
			res.push_front(carry + '0');
		return string(res.begin(), res.end());
	}
};
int main() {
	Solution2 s;
	string a = "1010", b = "1011";
	auto res = s.addBinary(a, b);
	return 0;
}