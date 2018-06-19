
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//Example:
//
//Input: "25525511135"
//	Output : ["255.255.11.135", "255.255.111.35"]
#include<iostream>
#include<string>	
#include<vector>
using namespace std;
class Solution {
	vector<string> result;
	void helper(string&s, int index,const string& prev,int part) {
		if (part == 3) {
			int left = s.size() - index;
			if (left <= 3 && left >= 1){
				string tmp = s.substr(index, string::npos);
				int value = stoi(tmp);
				if (s[index] != '0' && value > 0 && value <= 255) {
					result.push_back(prev + "." + tmp);
				}
				else if (s[index] == '0' && left == 1)
					result.push_back(prev + "." + tmp);
				
			}			
		}
		else {
			for (int i = 0; i < 4 && i+index<s.size(); i++) {
				string tmp = s.substr(index, i+1);
				int value = stoi(tmp);
				if (value > 0 && value <= 255) {
					if(part==0)
						helper(s, index + i + 1, tmp, part + 1);
					else
					helper(s, index + i+ 1, prev + "." + tmp, part + 1);
				}
				else if (value == 0 && tmp.size() == 1) {
					if (part == 0)
						helper(s, index + i + 1, tmp, part + 1);
					else
						helper(s, index + i + 1, prev + "." + tmp, part + 1);
					break;
				}
			}
		}
		return;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		int size = s.size();
		if (size >= 4 && size <= 12) {
			helper(s, 0,"",0);
		}
		return result;	
			
	}
};
int main() {
	Solution s;
	s.restoreIpAddresses("25525511135");
	return 0;
}