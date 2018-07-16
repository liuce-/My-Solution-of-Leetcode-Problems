//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.The integer division should truncate toward zero.
//
//Example 1:
//
//Input: "3+2*2"
//	Output : 7
//	Example 2 :
//
//	Input : " 3/2 "
//	Output : 1
//	Example 3 :
//
//	Input : " 3+5 / 2 "
//	Output : 5
//	Note :
//
//	You may assume that the given expression is always valid.
//	Do not use the eval built - in library function.
#include<string>
#include<list>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		list<int> nums;
		list<char> operation;
		int pos = 0;
		int currentNumber = 0;
		
		while (pos < s.size()) {
			if (s[pos] >= '0' && s[pos] <= '9')
				currentNumber = currentNumber * 10 + s[pos] - '0';
			else {
				if (s[pos] != ' ') {
					nums.push_back(currentNumber);
					currentNumber = 0;
					operation.push_back(s[pos]);
				}
			}
			pos++;
		}
		nums.push_back(currentNumber);
		auto i = operation.begin();
		auto j = nums.begin();
		while ( i != operation.end() && j != nums.end()) {
			if (*i == '*' || *i =='/') {
				auto j2 = j++;
				int ans = *i == '*' ? (*j2)*(*j) : (*j2) / (*j);
				operation.erase(i++);
				nums.erase(j2);
				*j = ans;
			}
			else {
				j++;
				i++;
			}
		}
		while (operation.size() != 0) {
			auto op = operation.begin();
			auto num1 = nums.begin();
			auto num2 = ++nums.begin();
			int ans = *op == '+' ? *num1 + *num2 : *num1 - *num2;
			nums.pop_front();
			*nums.begin() = ans;
			operation.pop_front();
			
		}
		return *nums.begin();
	
	}
};
class Solution {
public:
	int calculate(string s) {
		list<int> nums;
		list<char> operation;
		int pos = 0;
		int currentNumber = 0;
		
		while (pos < s.size()) {
			if (s[pos] >= '0' && s[pos] <= '9')
				currentNumber = currentNumber * 10 + s[pos] - '0';
			else {
				if (s[pos] != ' ') {
					nums.push_back(currentNumber);
					currentNumber = 0;
					operation.push_back(s[pos]);
				}
			}
			pos++;
		}
		nums.push_back(currentNumber);
		auto i = operation.begin();
		auto j = nums.begin();
		while ( i != operation.end() && j != nums.end()) {
			if (*i == '*' || *i =='/') {
				auto j2 = j++;
				int ans = *i == '*' ? (*j2)*(*j) : (*j2) / (*j);
				operation.erase(i++);
				nums.erase(j2);
				*j = ans;
			}
			else {
				j++;
				i++;
			}
		}
		while (operation.size() != 0) {
			auto op = operation.begin();
			auto num1 = nums.begin();
			auto num2 = ++nums.begin();
			int ans = *op == '+' ? *num1 + *num2 : *num1 - *num2;
			nums.pop_front();
			*nums.begin() = ans;
			operation.pop_front();
			
		}
		return *nums.begin();
	
	}
};