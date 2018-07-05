//Compare two version numbers version1 and version2.
//If version1 > version2 return 1; if version1 < version2 return -1; otherwise return 0.
//
//	You may assume that the version strings are non - empty and contain only digits and the.character.
//	The.character does not represent a decimal point and is used to separate number sequences.
//	For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second - level revision of the second first - level revision.
//
//	Example 1:
//
//Input: version1 = "0.1", version2 = "1.1"
//	Output : -1
//	Example 2 :
//
//	Input : version1 = "1.0.1", version2 = "1"
//	Output : 1
//	Example 3 :
//
//	Input : version1 = "7.5.2.4", version2 = "7.5.3"
//	Output : -1
#include<string>
#include<queue>
#include<sstream>
using namespace std;
class Solution {
public:
	int compareVersion(string version1, string version2) {
		stringstream s1(version1);
		stringstream s2(version2);
		queue<int> v1;
		queue<int> v2;
		string tmp;
		while (getline(s1, tmp, '.')) 
			v1.push(stoi(tmp));
		
		while (getline(s2, tmp, '.'))
			v2.push(stoi(tmp));
		if (v1.size() != v2.size()) {
			int diff = abs((int)v1.size() - (int)v2.size());
			queue<int>& q = v1.size() > v2.size() ? v2 : v1;
			while (diff-- > 0) q.push(0);
		}
		
		while (v1.size() != 0 || v2.size() != 0) {
			if (v1.size() == 0)
				return -1;
			if (v2.size() == 0)
				return 1;
			if (v1.front() != v2.front())
				return v1.front() > v2.front()?1:-1;			
			v1.pop();
			v2.pop();
		}
		return 0;
	}
};
