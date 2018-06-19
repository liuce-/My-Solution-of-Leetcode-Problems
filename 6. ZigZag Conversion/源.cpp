//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int gc = 2 * numRows - 2;
		string res(s.size(), ' ');
		int index = 0;
		for (int i = 0; i < numRows; i++) {
			if (i == 0 || i == numRows - 1) {
				int x = i;
				while (x < s.size()) {
					res[index] = s[x];
					index++;
					x = x + gc;
				}
			}
			else {
				int x = 0;
				int t = 0;
				while (1) {
					x = t * gc + i;
					if (x < s.size()) {
						res[index] = s[x];
						index++;
					}
					else
						break;

					x = t * gc + gc - i;
					if (x < s.size()) {
						res[index] = s[x];
						index++;
					}
					else
						break;
					t++;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	string result = s.convert("PAYPALISHIRING", 3);
	cout << result;
	system("pause");
	return 0;
}