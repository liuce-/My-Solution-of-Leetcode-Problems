//Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
//You have the following 3 operations permitted on a word :
//
//Insert a character
//Delete a character
//Replace a character
//Example 1 :
//
//	Input : word1 = "horse", word2 = "ros"
//	Output : 3
//	Explanation :
//	horse->rorse(replace 'h' with 'r')
//	rorse->rose(remove 'r')
//	rose->ros(remove 'e')
//	Example 2 :
//
//	Input : word1 = "intention", word2 = "execution"
//	Output : 5
//	Explanation :
//	intention->inention(remove 't')
//	inention->enention(replace 'i' with 'e')
//	enention->exention(replace 'n' with 'x')
//	exention->exection(replace 'n' with 'c')
//	exection->execution(insert 'u')
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
//brutal force 
class HashFuc {
public:
	size_t operator()(const vector<int>& k) const {
		return hash<int>()(k[0])^hash<int>()(k[1])^hash<int>()(k[2])^hash<int>()(k[3]);
	}
};
class isEqual {
public:
	bool operator()(const vector<int>&a, const vector<int>&b) const {
		return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
	}
};
class Solution {
	unordered_map<vector<int>, int,HashFuc,isEqual> data;
	//vector<vector<vector<vector<int>>>> data;
	unordered_map<char, vector<int>> map;
	int distance(string word1, int left1,int right1,string word2,int left2,int right2) {//[left,right)
		if (data.find({left1, right1, left2,right2}) != data.end())
			return data[{left1, right1, left2, right2}];
		while (left1 < right1 && left2 < right2 && word1[left1] == word2[left2]) {
			left1++;
			left2++;
		}
		while (right1-1 >= left1 && right2-1 >= left2 && word1[right1-1] == word2[right2-1]) {
			right1--;
			right2--;
		}
		if (right1-left1==right2-left2 && left1 >= right1 && left2>=right2)//word1 == word2
			return data[{left1, right1, left2, right2}] =0;
		else if (left2 >= right2 || left1>=right1)//"abacccaba" "aba"
			return data[{left1, right1, left2, right2}] =max(right1 - left1,right2-left2);
	
		int minDistance = INT_MAX;
		for (int i = left1; i < right1; i++) {
			int tmpMin = INT_MAX;
			if (map.find(word1[i]) != map.end()) {
				auto v = map[word1[i]];
				for (int pos : v) {
					if (pos >= left2 && pos < right2) {
						int tmp = distance(word1, left1, i, word2, left2, pos)+distance(word1,i+1,right1,word2,pos+1,right2);
						tmpMin = min(tmpMin, tmp);			
					}
				}
			}
			minDistance = min(minDistance, tmpMin);
		}
		return data[{left1, right1, left2, right2}] =min(minDistance, max(right1 - left1 , right2 - left2 ));
		
	}
public:
	int minDistance(string word1, string word2) {
		if (word2.size() > word1.size())//make sure word2 is the shorter one.
			swap(word1, word2);
		int left = 0;
		while (left < word1.size() && left < word2.size() && word1[left] == word2[left])left++;
		int right2 = word2.size() - 1;
		int right1 = word1.size() - 1;
		while (right1 >= left && right2 >= left && word1[right1] == word2[right2]) {
			right1--;
			right2--;
		}
		if (word1.size() == word2.size() && left > right1)//word1 == word2
			return 0;
		else if (left > right2)//"abacccaba" "aba"
			return right1 - left + 1;
		for (int i = left; i <= right2; i++) {
			map[word2[i]].push_back(i);
		}
		return distance(word1, left, right1+1, word2, left, right2+1);
	}
};


class Solution2 {
	vector<vector<int>> data;
public:
	int minDistance(string word1, string word2) {
		data.resize(word2.size() + 1, vector<int>(word1.size() + 1));
		data[0][0] = 0;
		for (int i = 1; i < data[0].size(); i++)
			data[0][i] = data[0][i - 1]+1;
		for (int j = 1; j < data.size(); j++)
			data[j][0] = data[j - 1][0]+1;
		for (int i = 0; i < word2.size(); i++) {
			for (int j = 0; j < word1.size(); j++) {
				if (word2[i] == word1[j]) {
					data[i + 1][j + 1] = data[i][j];
				}
				else
					data[i + 1][j + 1] = min( data[i][j]+1,min(1+max(i,j),min(data[i][j + 1]+1, data[i + 1][j]+1)));
			}
		}
		return data.back().back();
	}
};

int main() {
	Solution2 s;
	auto res = s.minDistance("mart",
		"karma");
	return 0;
}