//Given two words(beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
//Note:
//
//Return 0 if there is no such transformation sequence.
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
//Output : 5
//
//	Explanation : As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//	return its length 5.
//	Example 2 :
//
//	Input :
//	beginWord = "hit"
//	endWord = "cog"
//	wordList = ["hot", "dot", "dog", "lot", "log"]
//
//	Output : 0
//
//	Explanation : The endWord "cog" is not in wordList, therefore no possible transformation.
#include<vector>
#include<queue>
#include<string>	
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
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		int size = wordList.size();
		//check if endWord in wordList
		bool exist = false;
		for (int i = 0; i < size; i++) {
			if (endWord == wordList[i])
				exist = true;
		}
		if (!exist)
			return 0;
		//init graph vector
		vector<vector<int>> graph(size);
		for (int i = 0; i < size-1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (diff(wordList[i], wordList[j]) == 1) {
					graph[j].push_back(i);
					if (j != size - 1) {
						graph[i].push_back(j);}}}}

		//level order traversal
		queue<pair<int, int>> q;
		vector<bool> visited(size,false);
		
		q.push(make_pair(size - 1, 1));
		while (q.size() != 0) {
			int index = q.front().first;
			int step = q.front().second;
			q.pop();
			if (wordList[index] == endWord)
				return step;

			for (int i = 0; i < graph[index].size(); i++) {
				int next = graph[index][i];				
				if (!visited[next]) {
					q.push(make_pair(next, step + 1));
					visited[next] = true;
				}
			}

		}
		return 0;

	}
};


