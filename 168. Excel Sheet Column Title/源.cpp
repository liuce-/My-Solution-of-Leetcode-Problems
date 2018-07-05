//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
//Example 1:
//
//Input: 1
//	Output : "A"
//	Example 2 :
//
//	Input : 28
//	Output : "AB"
//	Example 3 :
//
//	Input : 701
//	Output : "ZY"
#include<string>

using namespace std;
class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		while (n > 0) {
			n--;
			ans.push_back(n % 26  + 'A');
			n = n / 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};