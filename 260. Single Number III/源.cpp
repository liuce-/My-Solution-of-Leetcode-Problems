//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.
//
//Example:
//
//Input:  [1, 2, 1, 3, 2, 5]
//	Output : [3, 5]
//	Note :
//
//	The order of the result is not important.So in the above example, [5, 3] is also correct.
//	Your algorithm should run in linear runtime complexity.Could you implement it using only constant space complexity ?
#include<vector>
#include<unordered_map>
using namespace std;

//o(n) time, O(n) space
class Solution2 {
public:
	vector<int> singleNumber(vector<int>& nums) {
		unordered_map<int, int> map;
		for (auto i : nums)
			map[i]++;
		vector<int> ans;
		for (auto i : map) {
			if (i.second == 1)
				ans.push_back(i.first);
		}
		return ans;
	}
};

//���˵�һ��Ļ�����˼·�����ǿ��Խ�����ֳ��������֣�ÿ��������ֻ��һ��Ԫ�س���һ�Σ�����Ԫ�ض��������Ρ�
//��ôʹ�����ַ����Ϳ����ҳ�������Ԫ���ˡ������������һ��������Ԫ����x��y����ô�������е�Ԫ�����Ľ������res = x^y��
//����res��=0����ô���ǿ����ҳ�res�����Ʊ�ʾ�е�ĳһλ��1������ԭ�������飬���ǿ��Ը������λ���ǲ���1�Ϳ��Խ�����ֳ��������֡�
//x��y�ڲ�ͬ�������������С����Ҷ��������ɶԳ��ֵ�Ԫ�أ�Ҫô��x���ڵ��Ǹ����飬Ҫô��y���ڵ��Ǹ����顣
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto i : nums)
			res = res ^ i;

		int mask = 1;
		int s = res & 1;
		while ((res & 1) == 0) {
			mask = mask << 1;
			res = res >> 1;
		}

		int withOne = 0;
		int withoutOne = 0;

		for (auto i : nums) {
			if ((i&mask) == 0)
				withoutOne = withoutOne ^ i;
			else
				withOne = withOne ^ i;
		}
		return { withOne,withoutOne };
	}
};

