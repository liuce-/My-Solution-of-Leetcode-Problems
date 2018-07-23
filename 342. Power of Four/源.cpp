//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.
//
//Example:
//Given num = 16, return true.Given num = 5, return false.
//
//Follow up : Could you solve it without loops / recursion ?
//
class Solution {
public:
	bool isPowerOfFour(int num) {
		int mask = 0b01010101010101010101010101010101;
		return num>0 && (num&(num - 1)) == 0 && (num | mask) == mask;
	}
};
class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && (num&(num - 1)) == 0 && (num - 1) % 3 == 0;
	}
};