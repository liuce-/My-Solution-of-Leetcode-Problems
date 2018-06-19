/*

70. Climbing Stairs
You are climbing a stair case.It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?

Note : Given n will be a positive integer.

*/

//equation: f(n)=f(n-1)+f(n-2), f(0)=f(1)=1;


//solution 1: time limit exceeded µÝ¹é
#include<iostream>
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 0)
			return 1;
		else
			return climbStairs(n - 1) + climbStairs(n - 2);
	}
};

//solution 2: µÝ¹é
#include<vector>
using namespace std;
class Solution2 {
	static vector<int> data;

public:
	int climbStairs(int n) {
		if (n >= data.size())
			data.resize(n+1,-1);

		if (n == 0 || n == 1)
			return 1;

		if (data[n] != -1) {
			return data[n];
		}
		else {
			return data[n]=climbStairs(n - 1) + climbStairs(n - 2);
		}
		
	}
};
vector<int> Solution2::data(100, -1);


//solution 3 ¶¯Ì¬¹æ»®
class Solution3 {
public:
	int climbStairs(int n) {
		int result[3];
		
		result[0] = result[1] = 1;

		for (int i = 2; i < n + 1; i++) {
			result[i % 3] = result[(i - 1) % 3] + result[(i - 2) % 3];

		}
		return result[n % 3];
	}
};
int main() {
	Solution s;
	std::cout<<s.climbStairs(10);
	system("pause");
	return 0;

}