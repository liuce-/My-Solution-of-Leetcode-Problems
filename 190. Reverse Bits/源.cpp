//Reverse bits of a given 32 bits unsigned integer.
//
//Example:
//
//Input: 43261596
//	Output : 964176192
//	Explanation : 43261596 represented in binary as 00000010100101000001111010011100,
//	return 964176192 ¡¤¡¤ in binary as 00111001011110000010100101000000.
#include<iostream>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		uint32_t mask = 1;
		for (int i = 0; i < 32; i++) {
			res = res << 1;
			res = res | (mask & n);
			n = n >> 1;
		}
		return res;
	}
};