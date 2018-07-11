//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.The valid operators are + , -and *.
//
//Example 1:
//
//Input: "2-1-1"
//	Output : [0, 2]
//	Explanation :
//	((2 - 1) - 1) = 0
//	(2 - (1 - 1)) = 2
//	Example 2 :
//
//	Input : "2*3-4*5"
//	Output : [-34, -14, -10, -10, 10]
//	Explanation :
//	(2 * (3 - (4 * 5))) = -34
//	((2 * 3) - (4 * 5)) = -14
//	((2 * (3 - 4)) * 5) = -10
//	(2 * ((3 - 4) * 5)) = -10
//	(((2 * 3) - 4) * 5) = 10
#include<vector>
#include<string>	
using namespace std;

class Solution {
	vector<int> res;
	void compute(vector<int>& nums, vector<char>& operations,int startIndex) {
		if (operations.size() == 0)
			res.push_back(nums[0]);
		else {
			startIndex = startIndex<0 ? 0 : startIndex;//remove redundance such as (3*4)-(4*5). Without the startIndex, it will be caculated twitce
			for (int i = startIndex; i < operations.size(); i++) {
				int ans = 0;
				switch (operations[i])
				{
				case'+':
					ans = nums[i] + nums[i + 1];
					break;
				case '-':
					ans = nums[i] - nums[i + 1];
					break;
				case '*':
					ans = nums[i] * nums[i + 1];
					break;
				default:
					exit(-1);
					break;
				}
				vector<int> newNums = nums;
				vector<char> newOperations = operations;
				newNums[i] = ans;
				newNums.erase(newNums.begin()+ i + 1);
				newOperations.erase(newOperations.begin()+i);
				compute(newNums, newOperations,i-1);
			}


		}
	}
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<char> operations;
		while (1) {
			size_t processed = 0;
			nums.push_back(stoi(input, &processed));
			if (processed < input.size()) {
				operations.push_back(input[processed]);
				input = input.substr(processed + 1);
			}
			else 
				break;			
		}
		compute(nums, operations,0);
		return res;
	}
};
