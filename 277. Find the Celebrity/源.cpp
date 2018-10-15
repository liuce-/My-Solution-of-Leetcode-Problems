// Forward declaration of the knows API.
bool knows(int a, int b);

#include<vector>
using namespace std;
class bestSolution {
public:
	int findCelebrity(int n) {
		int candidate = 0;
		for (int i = 1; i < n; ++i) {
			if (knows(candidate, i)) candidate = i;
		}
		for (int i = 0; i < n; ++i) {
			if (i != candidate && (!knows(i, candidate) || knows(candidate, i))) return -1;
		}
		return candidate;
	}
};

class Solution {
	vector<vector<int>> matrix;
public:
	int findCelebrity(int n) {
		matrix.resize(n, vector<int>(n, -1));
		int x = 0;
		int y = 0;
		while (x < n && y < n) {
			if (x == y) {
				y++;
				continue;
			}
			matrix[x][y] = knows(x, y);
			if (matrix[x][y] == 0)
				y++;
			else
				x=y;
		}
		if (x == n)
			return -1;
		else {
			int candidate = x;
			for (int i = 0; i < n; i++) {
				if (i == candidate)
					continue;
				int column = matrix[i][candidate] == -1 ? knows(i, candidate) : matrix[i][candidate];
				int row = matrix[candidate][i] == -1 ? knows(candidate, i) : matrix[candidate][i];
				if (row != 0 || column != 1)
					return -1;
			}
			return candidate;
		}


	}
};