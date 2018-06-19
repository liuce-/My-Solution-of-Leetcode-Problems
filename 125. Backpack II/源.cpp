//Given n items with size Ai and value Vi, and a backpack with size m.What's the maximum value can you put into the backpack?
//
//Example
//Given 4 items with size[2, 3, 5, 7] and value[1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
//
//Challenge
//O(n x m) memory is acceptable, can you do it in O(m) memory ?


#include<algorithm>
#include<vector>
using namespace std;
class Solution {
	 vector<vector<int>> maxValue;
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int findMax(int start, int capacity, vector<int>&weight, vector<int>&value) {
		int size = weight.size();
		if (start >= size) {
			return 0;
		}
		if (maxValue[start][capacity] != -1)
			return maxValue[start][capacity];
		if (start == size - 1) {
			if (weight[start] > capacity)
				return 0;
			return value[start];
		}
		
		
		if (weight[start] > capacity)
			return maxValue[start][capacity] = findMax(start + 1, capacity, weight, value);
		else
			return maxValue[start][capacity] = max(findMax(start + 1, capacity, weight, value), value[start] + findMax(start + 1, capacity - weight[start], weight, value));
	}
	int backPackII(int capacity, vector<int> &weight, vector<int> &value) {
		// write your code here
		int size = weight.size();
		
		maxValue.resize(size,vector<int>(capacity+1,-1));

		return findMax(0, capacity, weight, value);

	}
};


class Solution2 {
 vector<vector<int>> maxValue;
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int findMax(int start, int capacity, vector<int>&weight, vector<int>&value) {
		int size = weight.size();
		if (start >= size) {
			return 0;
		}
		if (maxValue[start][capacity] != -1)
			return maxValue[start][capacity];
		
		if (start == size - 1) {
			if (weight[start] > capacity)
				return 0;
			return value[start];
		}
		int result = 0;
		for (int i = start; i < size; i++) {
			int temp = 0;
			if (weight[i] <= capacity) {
				
				temp = value[i] + findMax(i + 1, capacity - weight[i], weight, value);
			}
			result = temp > result ? temp : result;				
		}
		return maxValue[start][capacity] = result;
	}
	int backPackII(int capacity, vector<int> &weight, vector<int> &value) {
		// write your code here
		int size = weight.size();

		maxValue.resize(size, vector<int>(capacity + 1, -1));

		return findMax(0, capacity, weight, value);

	}
};

//只用两行就行，因为每行只需要前一行的数据
//实际上只用一行就行，但是遍历的顺序需要从后往前遍历。这样更新的结果不会覆盖掉还没读取过的结果
class Solution3 {
	vector<vector<int>> maxValue;
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int capacity, vector<int> &weight, vector<int> &value) {
		int size = weight.size();
		if (size <= 0)
			return 0;
		maxValue.resize(2, vector<int>(capacity+1, -1));
		for (int row = 0; row < size; row++) {			
			for (int column = 0; column < capacity + 1; column++) {
				if (row == 0) {
					maxValue[0][column] = weight[row] > column ? 0 : value[row];
				}
				else if (column < weight[row]) {
					maxValue[row%2][column] = maxValue[(row - 1)%2][column];
				}
				else {
					maxValue[row%2][column] = max(maxValue[(row - 1)%2][column], value[row] + maxValue[(row - 1)%2][column - weight[row]]);
				}
			}
		}
		return maxValue[(size - 1)%2][capacity];

	}
};


int main() {
	vector<int>weight = { 77, 22, 29, 50, 99 };
	vector<int>value = { 92, 22, 87, 46, 90 };

	Solution s;
	s.backPackII(100, weight, value);

	return 0;
}