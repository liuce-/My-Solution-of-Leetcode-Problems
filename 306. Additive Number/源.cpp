//Additive number is a string whose digits can form additive sequence.
//
//A valid additive sequence should contain at least three numbers.Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//Given a string containing only digits '0' - '9', write a function to determine if it's an additive number.
//
//Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
//
//	Example 1 :
//
//	Input : "112358"
//	Output : true
//	Explanation : The digits can form an additive sequence : 1, 1, 2, 3, 5, 8.
//	1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
//	Example 2 :
//
//	Input : "199100199"
//	Output : true
//	Explanation : The additive sequence is : 1, 99, 100, 199.
//	1 + 99 = 100, 99 + 100 = 199
//	Follow up :
//How would you handle overflow for very large input integers ?
//

#include<string>	
#include<algorithm>
using namespace std;
class Solution {
	bool isAdditive(int start1, int end1, int start2, int end2, string& s) {
		if (end2 == s.size() - 1)
			return true;

		if (s[start1] == '0'&&end1!=start1 || s[start2] == '0' && end2!=start2)
			return false;

		string sum;
		int carry = 0;
		int i = end1;
		int j = end2;
		while (i >= start1 || j >= start2) {
			int a = i >= start1 ? s[i] - '0' : 0;
			int b = j >= start2 ? s[j] - '0' : 0;
			int sumofab = a + b + carry;
			carry = sumofab / 10;
			sum.push_back(sumofab % 10 + '0');
			i--;
			j--;

		}
		if (carry != 0)
			sum.push_back(carry + '0');
		reverse(sum.begin(), sum.end());
		//cout<<sum<<endl;
		if (s.size() - end2 - 1 < sum.size())
			return false;
		else {
			for (int i = 0; i < sum.size(); i++) {
				if (sum[i] != s[i + end2 + 1])
					return false;
			}
			return isAdditive(start2, end2, end2 + 1, end2 + sum.size(), s);
		}

	}
public:
	bool isAdditiveNumber(string num) {

		for (int i = 0; i < num.size(); i++) {
			for (int j = i + 1; j < num.size(); j++) {
				int start1 = 0;
				int end1 = i;
				int start2 = i + 1;
				int end2 = j;
				if (num.size() - end2 - 1 >= max(end1 - start1 + 1, end2 - start2 + 1) && isAdditive(start1, end1, start2, end2, num))
					return true;
			}
		}
		return false;
	}
};