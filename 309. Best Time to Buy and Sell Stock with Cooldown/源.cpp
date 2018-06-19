//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times) with the following restrictions :
//
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//Example :
//
//	prices = [1, 2, 3, 0, 2]
//	maxProfit = 3
//	transactions = [buy, sell, cooldown, buy, sell]
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;

		int* sell = new int[prices.size()];
		int* buy = new int[prices.size()];
		sell[0] = 0;
		buy[0] = -prices[0];

		for (int i = 1; i < prices.size(); ++i) {
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
			cout << "sell[" << i << "]=" << sell[i]<<endl;
			buy[i] = max(buy[i - 1], (i > 1 ? sell[i - 2] : 0) - prices[i]);
			cout << "buy[" << i << "]=" << buy[i] << endl;
		}
		
		return sell[prices.size() - 1];

	}
};

int main() {
	Solution s;
	vector<int> prices = { 1, 2, 3, 0, 2 };
	cout<<s.maxProfit(prices);
	return 0;

}