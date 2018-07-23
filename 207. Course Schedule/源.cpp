//
//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//Example 1 :
//
//	Input : 2, [[1, 0]]
//	Output : true
//	Explanation : There are a total of 2 courses to take.
//	To take course 1 you should have finished course 0. So it is possible.
//	Example 2 :
//
//	Input : 2, [[1, 0], [0, 1]]
//	Output : false
//	Explanation : There are a total of 2 courses to take.
//	To take course 1 you should have finished course 0, and to take course 0 you should
//	also have finished course 1. So it is impossible.
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Solution {
	enum color{ white,grey,black};
	vector<color> visited;
	vector<list<int>> graph;
	bool dfs(int source) {
		visited[source] = grey;
		for (auto i = graph[source].begin(); i != graph[source].end(); i++) {
			if (visited[*i] == grey)
				return false;
			if (visited[*i] == white) {
				if (!dfs(*i))
					return false;
			}
		}
		visited[source] = black;
		return true;
	}
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		graph.resize(numCourses);
		for (int i = 0; i < prerequisites.size(); i++)
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		visited.resize(numCourses,white);
		for (int i = 0; i < graph.size(); i++) {
			if (visited[i]==white) {
				if (!dfs(i))
					return false;
			}
		}
		return true;
	}
};