//Convert a non - negative integer to its english words representation.Given input is guaranteed to be less than 231 - 1.
//
//Example 1:
//
//Input: 123
//	Output : "One Hundred Twenty Three"
//	Example 2 :
//
//	Input : 12345
//	Output : "Twelve Thousand Three Hundred Forty Five"
//	Example 3 :
//
//	Input : 1234567
//	Output : "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//	Example 4 :
//
//	Input : 1234567891
//	Output : "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
#include<string>	
#include<stack>
#include<vector>
using namespace std;
class Solution {
	vector<string> r1{ "","Thousand","Million","Billion" };
	vector<string> r2{ "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
	vector<string> r3{ "","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
	vector<string> r4{ "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
public:
	string numberToWords(int num) {
		if (num == 0)
			return "Zero";
		stack<string> stack;
		while (num > 0) {
			int remain = num % 1000;
			vector<string> current;
			//hundred
			if (remain / 100 > 0) {
				if (remain / 100 > 0) {
					current.push_back(r2[remain / 100]);
					current.push_back("Hundred");
				}
			}
			//ten
			remain = remain % 100;
			if (remain / 10 == 1) {//10,11,12,...19
				remain = remain % 10;
				current.push_back(r4[remain]);
			}
			else {
				if(remain/10>0)
				current.push_back(r3[remain / 10]);
				if(remain%10>0)
				current.push_back(r2[remain % 10]);
			}
			string tmp = "";
			for (auto i : current) {
					tmp += i;
					tmp += " ";
				
			}
			if (tmp.size() > 1 ) {
				if (stack.size() == 0)
					tmp.resize(tmp.size() - 1);
				else
					tmp += r1[stack.size()];
			}
			stack.push(tmp);
			num = num / 1000;
		}
		string ans = "";
		while (stack.size() != 0) {
			if (stack.top() != "") {
				ans += stack.top();
				ans += " ";
			}
			stack.pop();
		}
		if (ans.size() > 1)
			ans.resize(ans.size() - 1);
		return ans;
	}
};
int main() {
	Solution s;
	auto res = s.numberToWords(1000);
	return 0;
}