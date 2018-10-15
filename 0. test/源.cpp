//This project is for test purpose only.

#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
	unordered_map<char, int> map;
	map['a']++;
	map['a'] = 0;
	cout << map.empty();
	map['b']++;
	map['b']--;
	cout << map.empty();
	
	for (int i = 0; i < -1; i++) {
		cout << "asdf" << endl;
	}
	unsigned int max = UINT_MAX;
	unsigned long long int test = (unsigned long long int)max * (unsigned long long int)max;
	unsigned long long int llmax = ULLONG_MAX;
	cout << "max \t" << max << endl;
	cout << "test\t" << test << endl;
	cout << "llmax\t" << llmax << endl;
	return 0;

}