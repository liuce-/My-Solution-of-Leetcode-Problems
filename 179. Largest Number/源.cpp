//Given a list of non negative integers, arrange them such that they form the largest number.
//
//Example 1:
//
//Input: [10, 2]
//	Output : "210"
//	Example 2 :
//
//	Input : [3, 30, 34, 5, 9]
//	Output : "9534330"
#include<string>	
#include<algorithm>
#include<vector>
using namespace std;
class sortFunc {
public:
	bool operator()(const vector<int>& a, const vector<int>&b)const {
		vector<int> tmpa = a;
		tmpa.insert(tmpa.end(), b.begin(), b.end());
		vector<int> tmpb = b;
		tmpb.insert(tmpb.end(), a.begin(), a.end());

		for (int i = 0; i < tmpa.size(); i++) {
			if (tmpa[i] != tmpb[i])
				return tmpa[i] > tmpb[i];
		}
		return false;
	}
};
class Solution {
	vector<vector<int>> sortedList;
	void convert(int num) {
		vector<int> v;
		do {
			v.push_back(num % 10+'0');
			num = num / 10;
		} while (num != 0);
		reverse(v.begin(), v.end());
		sortedList.push_back(v);

	}
public:
	string largestNumber(vector<int>& nums) {
		for (auto i : nums)
			convert(i);
		sort(sortedList.begin(), sortedList.end(), sortFunc());
		string ans;
		for (int i = 0; i < sortedList.size(); i++) 
			ans.append(sortedList[i].begin(), sortedList[i].end());
		if (ans.size() >= 1 && ans[0] == '0')
			return "0";
		else 
			return ans;
	}
};



class sortFunc2 {
public:
	bool operator()(const int& a, const int&b)const {
		string stra = to_string(a);
		string strb = to_string(b);
		return stra + strb > strb + stra;
	}
};
class Solution2 {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), sortFunc2());
		string ans;
		for (int i = 0; i < nums.size(); i++)
			ans.append(to_string(nums[i]));
		if (ans.size() >= 1 && ans[0] == '0')
			return "0";
		else
			return ans;
	}
};