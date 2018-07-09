//Given a non - negative integer num, repeatedly add all its digits until the result has only one digit.
//
//Example:
//
//Input: 38
//	Output : 2
//	Explanation : The process is like : 3 + 8 = 11, 1 + 1 = 2.
//	Since 2 has only one digit, return it.
//	Follow up :
//	   Could you do it without any loop / recursion in O(1) runtime ?
//
#include<stack>
using namespace std;
//My explanation:https://leetcode.com/problems/add-digits/description/
//O(1) time
class Solution {
public:
	int addDigits(int num) {
		while (num >= 10) {
			int newSum = 0;
			while(num>0){
				newSum += num % 10;
				num = num / 10;
			}
			num = newSum;
		}
		return num;
	}
};

//O(1) time
class Solution {
public:
	int addDigits(int num) {
		for (int i = 0; i < 3; i++) {
			int newSum = 0;
			for(int j=0;j<10;j++){
				newSum += num % 10;
				num = num / 10;
			}
			num = newSum;
		}

		return num;
	}
};
//O(1) time without any loop / recursion in O(1) runtime
class Solution {
public:
	int addDigits(int num) {
		/************A******************/
		int newSum = 0;
		//1
		newSum += num % 10;
		num = num / 10;
		//2
		newSum += num % 10;
		num = num / 10;
		//3
		newSum += num % 10;
		num = num / 10;
		//4
		newSum += num % 10;
		num = num / 10;
		//5
		newSum += num % 10;
		num = num / 10;
		//6
		newSum += num % 10;
		num = num / 10;
		//7
		newSum += num % 10;
		num = num / 10;
		//8
		newSum += num % 10;
		num = num / 10;
		//9
		newSum += num % 10;
		num = num / 10;
		//10
		newSum += num % 10;
		num = num / 10;

		num = newSum;
		/*****************************B**********/
		newSum = 0;
		//1
		newSum += num % 10;
		num = num / 10;
		//2
		newSum += num % 10;
		num = num / 10;
		//3
		newSum += num % 10;
		num = num / 10;
		//4
		newSum += num % 10;
		num = num / 10;
		//5
		newSum += num % 10;
		num = num / 10;
		//6
		newSum += num % 10;
		num = num / 10;
		//7
		newSum += num % 10;
		num = num / 10;
		//8
		newSum += num % 10;
		num = num / 10;
		//9
		newSum += num % 10;
		num = num / 10;
		//10
		newSum += num % 10;
		num = num / 10;

		num = newSum;
		/*************************C************/
		newSum = 0;
		//1
		newSum += num % 10;
		num = num / 10;
		//2
		newSum += num % 10;
		num = num / 10;
		//3
		newSum += num % 10;
		num = num / 10;
		//4
		newSum += num % 10;
		num = num / 10;
		//5
		newSum += num % 10;
		num = num / 10;
		//6
		newSum += num % 10;
		num = num / 10;
		//7
		newSum += num % 10;
		num = num / 10;
		//8
		newSum += num % 10;
		num = num / 10;
		//9
		newSum += num % 10;
		num = num / 10;
		//10
		newSum += num % 10;
		num = num / 10;

		num = newSum;

		return num;
	}
};