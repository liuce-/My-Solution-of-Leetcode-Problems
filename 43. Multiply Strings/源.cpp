//Given two non - negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
//Example 1:
//
//Input: num1 = "2", num2 = "3"
//	Output : "6"
//	Example 2 :
//
//	Input : num1 = "123", num2 = "456"
//	Output : "56088"
//	Note :
//
//	The length of both num1 and num2 is < 110.
//	Both num1 and num2 contain only digits 0 - 9.
//	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//	You must not use any built - in BigInteger library or convert the inputs to integer directly.

#include<string>
#include<vector>
#include<iostream>
#define BASE (long long int)1000000000
#define L 9
using namespace std;
class Solution {
	void convert(vector<unsigned int>& v, string num) {
		int index = num.size() - 1;
		int count = 0;
		int cur = 0;
		int time = 1;
		while (index >= 0) {
			cur = cur + (num[index] - '0')*time;
			count++;
			time = time * 10;
			if (count == L) {
				v.push_back(cur);
				count = 0;
				cur = 0;
				time = 1;
			}
			index--;
		}
		if (count != 0) {
			v.push_back(cur);
		}
	}
	string unconvert(vector<unsigned int> & v) {
		string s(v.size() * L, ' ');
		for (int i = 0; i < v.size(); i++) {
			auto num = v[i];
			for (int j = 0; j < L; j++) {
				s[i * L + j] = num % 10 + '0';
				num /= 10;
			}
		}
		int count = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '0' || s[i] == ' ') {
				count++;
			}
			else
				break;
		}
		s.resize(s.size() - count);
		if (s.size() == 0)
			s.push_back('0');
		reverse(s.begin(), s.end());
		return s;
	}
public:
	string multiply(string num1, string num2) {
		vector<unsigned int> v1;
		vector<unsigned int> v2;
		vector<unsigned int> ans;
		convert(v1, num1);
		convert(v2, num2);
		ans.resize(v1.size()*v2.size() + 1);

		for (int i = 0; i < v2.size(); i++) {
			long long int contribute = 0;
			for (int j = 0; j < v1.size(); j++) {
				long long int res = (long long int)v1[j] * (long long int)v2[i] + contribute + (long long int)ans[i + j];
				contribute = 0;
				if (res > BASE) {
					contribute = res / BASE;
					res = res % BASE;
				}
				ans[i + j] = res;
			}
			if (contribute != 0) {
				ans[i + v1.size()] += contribute;
			}
		}
		int i = v2.size() - 1 + v1.size() - 1;
		if (ans[i] > BASE) {
			ans[i + 1] = ans[i] / BASE;
			ans[i] = ans[i] % BASE;
		}
		return unconvert(ans);
	}
};

int main() {
	Solution s;
	cout<<s.multiply("896686",
		"8261335908")<< endl;
	cout << "7407824250000888" << endl;

	return 0;
}