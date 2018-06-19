//Given two words(beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//Note:
//
//Return an empty list if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non - empty and are not the same.
//Example 1:
//
//Input:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//
//Output :
//	[
//		["hit", "hot", "dot", "dog", "cog"],
//		["hit", "hot", "lot", "log", "cog"]
//	]
//Example 2 :
//
//	Input :
//	beginWord = "hit"
//	endWord = "cog"
//	wordList = ["hot", "dot", "dog", "lot", "log"]
//
//	Output : []
//
//	Explanation : The endWord "cog" is not in wordList, therefore no possible transformation.
#include<vector>
#include<queue>
#include<string>	
#include<array>
#include<iostream>
using namespace std;
class Solution {
	int diff(string& str1, string& str2) {
		int difference = 0;
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] != str2[i])
				difference++;
		}
		return difference;
	}
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> result;
		wordList.push_back(beginWord);
		int size = wordList.size();
		//check if endWord in wordList
		bool exist = false;
		for (int i = 0; i < size; i++) {
			if (endWord == wordList[i])
				exist = true;
		}
		if (!exist)
			return result;
		//init graph vector
		vector<vector<int>> graph(size);
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (diff(wordList[i], wordList[j]) == 1) {
					graph[j].push_back(i);
					if (j != size - 1) {
						graph[i].push_back(j);}}}}

		int targetLevel = -1;
		//level order traversal
		queue<array<int,3>> q;//first:index, second:father,third: level
		vector<int> visited(size, INT_MAX);
		vector<vector<pair<int,int>>> levelOrder;//first:index, second:father
		q.push(array<int, 3>{ size - 1, 0, 0 });
		while (q.size() != 0) {
			int index = q.front()[0];
			int father = q.front()[1];
			int level = q.front()[2];
			q.pop();
			if (wordList[index] == endWord && targetLevel==-1)
				targetLevel = level;
			
			if (targetLevel != -1 && level > targetLevel)
				break;
			else {
				if (levelOrder.size() - 1 != level)
					levelOrder.push_back(vector<pair<int, int>>());
				levelOrder[level].push_back(make_pair(index, father));
			}
			for (int i = 0; i < graph[index].size(); i++) {
				int next = graph[index][i];
				if (level + 1 <= visited[next]) {
					q.push(array<int, 3>{next, levelOrder[level].size() - 1, level + 1});
					visited[next] = level+1;
				}
				
			}

		}
		int lvlSize = levelOrder.size();

		for (int i = 0; i < levelOrder[lvlSize - 1].size();i++) {
			if (wordList[levelOrder[lvlSize - 1][i].first] == endWord) {
				result.push_back(vector<string>(1, endWord));
				int currentIndexofResult = result.size() - 1;
				int father = levelOrder[lvlSize - 1][i].second;
				for (int j = lvlSize - 2; j > 0; j--) {
					auto temp = levelOrder[j][father];
					result[currentIndexofResult].push_back(wordList[temp.first]);
					father = temp.second;
				}
				result[currentIndexofResult].push_back(beginWord);
			}
		}
		for (int i = 0; i < result.size(); i++) {
			reverse(result[i].begin(), result[i].end());
		}
		return result;
	}
};
int main() {

}