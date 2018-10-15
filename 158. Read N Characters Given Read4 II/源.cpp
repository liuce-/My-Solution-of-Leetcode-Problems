// Forward declaration of the read4 API.
#include<iostream>
#include<algorithm>
using namespace std;
int read4(char *buf) {
	return 1;
}

class Solution {
	char cache[4] = {'a'};
	int current = 4;
	

	int copy(char* target, char* source, int count) {
		int j = current;
		for (int i = 0; i < count; i++, j++) {
			target[i] = cache[j];
		}
		return count;

	}
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Maximum number of characters to read
	 * @return    The number of characters read
	 */
	int read(char *buf, int n) {
		if (buf == nullptr)
			return 0;

		int totalCount = 0;
		while (n > 0) {
			int count = copy(buf, cache, min(n, 4 - current));
			cout << count << endl;
			n -= count;
			current += count;
			totalCount += count;
			if (current == 4) {
				current = 4 - read4(cache);
				if (current == 4)//EOF
					break;
			}
		}
		return totalCount;



	}
};
int main() {
	Solution s;
	char buffer[256] = { 0 };
	s.read(buffer,1);
	return 0;
}