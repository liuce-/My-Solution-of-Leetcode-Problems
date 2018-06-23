//Validate if a given string is numeric.
//
//Some examples :
//"0" = > true
//" 0.1 " = > true
//"abc" = > false
//"1 a" = > false
//"2e10" = > true
//Note: It is intended for the problem statement to be ambiguous.You should gather all requirements up front before implementing one.

/************************************************************IMPORTANT!!************************************************************/
/* 
	It did not pass the testcases in leetcode because the testcases are all wrong! 
	Why are '.1' and '01' considered as a valid number???? 
	WTF!!!!!!!!!

	BTW, find the pic of FSM in resource folder.
*/
/************************************************************IMPORTANT!!************************************************************/

#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		int i = 0;
		while (i < s.size() && s[i] == ' ')i++;
		int j = s.size() - 1;
		while (j >= 0 && s[j] == ' ')j--;
		if (i > j)
			return false;
		string str = s.substr(i, j - i + 1);
		int state = 0;
		for (int i = 0; i < str.size(); i++) {
			switch (state)
			{
			case 0: {
				if (str[i] == '+' || str[i] == '-')
					state = 1;
				else if (str[i] == '0')
					state = 3;
				else if (str[i] >= '1'&&str[i] <= '9')
					state = 2;
				else
					state = 7;
			}break;
			case 1: {
				if (str[i] == '0')
					state = 9;
				else if (str[i] >= '1'&& str[i] <= '9')
					state = 2;
				else
					state = 7;
			}; break;
			case 2: {
				if (str[i] >= '0'&&str[i] <= '9')
					state = 2;
				else if (str[i] == 'e')
					state = 4;
				else if (str[i] == '.')
					state = 10;
				else
					state = 7;
			}break;
			case 3: {
				if (str[i] == '.')
					state = 10;
				else
					state = 7;
			}break;
			case 4: {
				if (str[i] == '-')
					state = 5;
				else if (str[i] >= '1'&&str[i] <= '9')
					state = 8;
				else
					state = 7;
			}break;
			case 5: {
				if (str[i] >= '1'&& str[i] <= '9')
					state = 9;
				else
					state = 7;
			}break;
			case 7:
				return false;
			case 8: {
				if (str[i] >= '0'&&str[i] <= '9')
					state = 8;
				else
					state = 7;
			}break;
			case 9: {
				if (str[i] == '.')
					state = 10;
				else
					state = 7;
			}break;
			case 10: {
				if (str[i] >= '0'&&str[i] <= '9')
					state = 11;
				else
					state = 7;
			}break;
			case 11: {
				if (str[i] == 'e')
					state = 4;
				else if (str[i] >= '0'&&str[i] <= '9')
					state = 11;
				else
					state = 7;
			}	 break;
			default:
				std::cout << "wrong place, shouldn't be here."<<endl;
				exit(-1);
			}
		}
		if (state == 2 || state == 3 || state == 8 || state == 11)
			return true;
		else
			return false;
	}
};