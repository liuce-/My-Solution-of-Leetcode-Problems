//The count - and-say sequence is the sequence of integers with the first five terms as following :
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth term of the count - and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//	Example 1 :
//
//	Input : 1
//	Output : "1"
//	Example 2 :
//
//	Input : 4
//	Output : "1211"
#include<string>
#include<vector>
using namespace std;
class Solution {
	static vector<string> res;
public:
	string countAndSay(int n) {
		if (res.size() >= n + 1)
			return res[n];
		else {
			int i = res.size();
			res.resize(n + 1);
			for (; i < res.size(); i++) {
				string& tmp = res[i - 1];
				string ans;
				char c = tmp[0];
				int count = 1;
				for (int j = 1; j < tmp.size(); j++) {
					if (tmp[j] == tmp[j - 1])
						count++;
					else {
						ans.append(1, '0' + count);
						ans.append(1, c);
						count = 1;
						c = tmp[j];
					}
				}
				ans.append(1, '0' + count);
				ans.append(1, c);
				res[i] = ans;
			}
			return res[res.size() - 1];

		}

	}
};
vector<string> Solution::res = { "","1" };