//You are given coins of different denominations and a total amount of money amount.Write a function to compute the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//coins = [1, 2, 5], amount = 11
//return 3 (11 = 5 + 5 + 1)
//
//Example 2 :
//	coins = [2], amount = 3
//	return -1.
//
//	Note :
//	You may assume that you have an infinite number of each kind of coin.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution2 {
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		int count = -1;
		vector<int> result(amount+1, -1);
		for (int i = 0; i < amount + 1; i++)
			if (i%coins[0] == 0)
				result[i] = i / coins[0];
		if (result[amount] != -1)
			count = result[amount];

		for (int i = 1; i < size; i++) {
			for (int j = amount; j >=0; j--) {
				int minForj = -1;
				for (int k = 0; k <= j / coins[i]; k++) {
					int temp = result[j - coins[i] * k];
					if (temp != -1) {
						minForj = minForj == -1 ? k+temp : min(k+temp, minForj);
					}	
				}
				result[j] = minForj;
			}
			if (result[amount] != -1) {
				count = count == -1 ? result[amount] : min(result[amount], count);
			}
		}
		return count;
	}
};
class Solution {
	vector<vector<int>> result;
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		result=vector<vector<int>>(size, vector<int>(amount + 1, -2));		
		sort(coins.begin(), coins.end(), greater<int>());
		return helper(0,coins, amount);
	}
	int helper(int n, vector<int>&coins, int amount) {
		if (n >= coins.size())
			return -1;
		int coin = coins[n];
		if (result[n][amount] != -2)
			return result[n][amount];
		int count = -1;
		for (int i = amount / coin; i >= 0; i--) {
			if (coin*i == amount)
				count = count==-1? i:min(i,count);
			else {
				int temp = helper(n + 1, coins, amount - coin * i);
				if (temp != -1)
					count = count == -1 ? temp + i: min(count, temp + i);
			}
		}
		return result[n][amount] = count;
	}
};


class Solution3 {
	vector<vector<int>> result;
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		vector<int> totalCoins;
		if (amount == 0)
			return 0;
		for (int i = 0; i < size; i++) {
			totalCoins.insert(totalCoins.end(), amount / coins[i], coins[i] );
		}
		if (totalCoins.size() == 0)
			return -1;

		vector<int> result(amount+1,amount+1);
		for (int i = 0; i < amount + 1; i++) {
			if (i%totalCoins[0] == 0)
				result[i] = i / totalCoins[0];
		}
		int minCount = amount+1;

		for (int i = 0; i < totalCoins.size(); i++) {
			for (int j = amount; j >= 0; j--) {
				if (j - totalCoins[i] >= 0)
					result[j] = min(result[j], 1 + result[j - totalCoins[i]]);
				
			}
			if (result[amount] < minCount)
				minCount = result[amount];
		}

		return minCount > amount ? -1 : minCount;
		

	}
};

class Solution4 {
	vector<vector<int>> result;
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		result = vector<vector<int>>(size, vector<int>(amount + 1, -2));
		int temp = helper(coins.size()-1, coins, amount);
		return temp;
	}
	int helper(int n, vector<int>&coins, int amount) {
		if (amount < 0)
			return -1;

		if (result[n][amount] != -2)
			return result[n][amount];
		if (n == 0) {
			if (amount%coins[0] == 0)
				return result[0][amount] = amount / coins[0];
			return result[0][amount] = -1;
		}
		int temp1 = helper(n - 1, coins, amount);
		int temp2 = helper(n, coins, amount - coins[n]);

		if (temp1 == -1 && temp2 == -1)
			result[n][amount] = -1;
		else if (temp1 != -1 && temp2 != -1)
			result[n][amount] = min(temp1, temp2 + 1);
		else if (temp1 == -1)
			result[n][amount] = temp2 + 1;
		else
			result[n][amount] = temp1;
		return result[n][amount] ;
	}
};
class Solution5 {
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		vector<int> result(amount+1,amount+1);
		result[0] = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < amount + 1; j++) {
				if (j - coins[i] >= 0) {
					result[j] = min(result[j], 1 + result[j - coins[i]]);
				}
			}
		}

		return result[amount] > amount ? -1 : result[amount];
	}

};
int main() {
	Solution4 s;
	vector<int> test = { 186,419,83,408

		 };
	cout<<s.coinChange(test, 6249);
	return 0;

}