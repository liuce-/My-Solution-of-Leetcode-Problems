//Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
//
//Example 1:
//
//Input: n = 12
//	Output : 3
//	Explanation : 12 = 4 + 4 + 4.
//	Example 2 :
//
//	Input : n = 13
//	Output : 2
//	Explanation : 13 = 4 + 9.
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
class Solution {
	static vector<int> result;
public:
	int numSquares(int n) {
		if (result.size() < n + 1) {
			result.resize(n + 1, 0);
		}

		if (result[n] != 0) {
			return result[n];
		}

		for (int i = 1; i <= n; i++)
			if (result[i] == 0) {
				int root = sqrt(i);
				if (root*root == i)
					result[i] = 1;
				else {
					int min = INT_MAX;
					for (int j = 1; j <= i / 2; j++) {
						int temp = result[j] + result[i - j];
						if (temp < min)
							min = temp;
					}
					result[i] = min;
				}
			}
		return result[n];


	}
};
vector<int> Solution::result(100, 0);

#include<queue>;
#include<utility>
//广度优先搜索。考虑一个有向图，每个节点为一个完全平方数。开始节点为n,结束节点为0，找到从n到0的最短路径
class Solution2 {
public:
	int numSquares(int n) {
		queue<pair<int, int>> q;
		vector<bool> visited(n + 1, false);

		q.push(make_pair(n, 0));
		visited[n] = true;

		while (q.size() != 0) {
			int number = q.front().first;
			int step = q.front().second;
			q.pop();
			if (number == 0)
				return step;

			for (int i = 1; i*i <= number; i++) {
				if (!visited[number - i * i]) {
					q.push(make_pair(number - i * i, step + 1));
					visited[number - i * i] = true;
				}
			}
		}
	}
};
