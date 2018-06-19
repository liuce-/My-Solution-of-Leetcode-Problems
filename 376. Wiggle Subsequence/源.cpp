//A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative.The first difference(if one exists) may be either positive or negative.A sequence with fewer than two elements is trivially a wiggle sequence.
//
//For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences(6, -3, 5, -7, 3) are alternately positive and negative.In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
//
//Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence.A subsequence is obtained by deleting some number of elements(eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
//
//Examples:
//Input: [1, 7, 4, 9, 2, 5]
//	Output : 6
//	The entire sequence is a wiggle sequence.
//
//	Input : [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
//	Output : 7
//	There are several subsequences that achieve this length.One is[1, 17, 10, 13, 10, 16, 8].
//
//	Input : [1, 2, 3, 4, 5, 6, 7, 8, 9]
//	Output : 2
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int size = nums.size();
		vector<int> nextIsLess(size, 1);
		vector<int> nextIsMore(size, 1);
		for (int i = 1; i < size; i++) {
			int max_nextIsLess = 0;
			int max_nextIsMore = 0;

			for (int j = 0; j < i; j++) {
				if (nums[j] > nums[i]) {
					max_nextIsMore = max(max_nextIsMore, 1+nextIsLess[j]);
				}
				else if (nums[j] < nums[i]) {
					max_nextIsLess = max(max_nextIsLess, 1 + nextIsMore[j]);
				}
			}
			nextIsLess[i] = max_nextIsLess;
			nextIsMore[i] = max_nextIsMore;
		}
		int result = 0;
		for (int i = 0; i < size; i++) {
			result = max(result, nextIsLess[i]);
			result = max(result, nextIsMore[i]);
		}
		return result;

	}
};