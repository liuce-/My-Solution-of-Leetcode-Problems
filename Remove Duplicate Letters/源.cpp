#include<vector>
using namespace std;

string removeDuplicate(string& array) {
	if (array.size() < 1)
		return array;
	int index = -1; //[0,index]
	int next = 0;
	while (next < array.size()) {
		if (index == -1 || array[next] != array[index])
			array[++index] = array[next++];
		else if (array[next] == array[index]) {
			while (array[index] == array[next]) next++;
			index--;
		}
	}
	
	return array.substr(0, index + 1);
}

int main() {
	string testcase = "assssssadssssadf";
	auto res = removeDuplicate(testcase);
	return 0;

}