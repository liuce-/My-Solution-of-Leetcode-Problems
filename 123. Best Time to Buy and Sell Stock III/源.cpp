//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note: You may not engage in multiple transactions at the same time(i.e., you must sell the stock before you buy again).
//
//	Example 1 :
//
//	Input : [3, 3, 5, 0, 0, 3, 1, 4]
//	Output : 6
//	Explanation : Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3 - 0 = 3.
//	Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4 - 1 = 3.
//	Example 2 :
//
//	Input : [1, 2, 3, 4, 5]
//	Output : 4
//	Explanation : Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5 - 1 = 4.
//	Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//	engaging multiple transactions at the same time.You must sell before buying again.
//	Example 3 :
//
//	Input : [7, 6, 4, 3, 1]
//	Output : 0
//	Explanation : In this case, no transaction is done, i.e.max profit = 0.
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		vector<int> firstTrans(prices.size());//firstTrans[i] means sell on or before day i 
		vector<int> secondTrans(prices.size());//secondTrans[i] means buy on or after day i

		int minPrice = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			firstTrans[i] = max(prices[i] - minPrice,firstTrans[i-1]);
			minPrice = min(minPrice, prices[i]);			
		}
		int maxPrice = prices.back();
		for (int i = prices.size() - 2; i >= 0; i--) {
			secondTrans[i] = max(maxPrice - prices[i], secondTrans[i-1]);
			maxPrice = max(maxPrice, prices[i]);
		}
		int totalMaxProfit = 0;
		for (int i = 0; i < prices.size()-1; i++) {
			totalMaxProfit = max(firstTrans[i] + secondTrans[i + 1],totalMaxProfit);
		}
		return max(totalMaxProfit, firstTrans.back());
	}
};

//Best Solution. Explanation:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
//WTF! How did this guy think out of this brilliant idea. 
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int hold1 = INT_MAX, hold2 = INT_MAX;
		int release1 = 0, release2 = 0;
		for (int i : prices) {                              // Assume we only have 0 money at first
			release2 = max(release2, hold2 + i);     // The maximum if we've just sold 2nd stock so far.
			hold2 = max(hold2, release1 - i);  // The maximum if we've just buy  2nd stock so far.
			release1 = max(release1, hold1 + i);     // The maximum if we've just sold 1nd stock so far.
			hold1 = max(hold1, -i);          // The maximum if we've just buy  1st stock so far. 
		}
		return release2; //Since release1 is initiated as 0, so release2 will always higher than release1.
	}
};

