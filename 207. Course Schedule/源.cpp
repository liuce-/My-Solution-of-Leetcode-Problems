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
using namespace std;
class Solution {
	vector<bool> visited;
	vector<vector<int>> graph;
	bool bfs(int source) {
		queue<int> q;
		q.push(source);
		while (q.size() != 0) {
			int course = q.front();
			visited[course] = true;
			q.pop();
			for (int i = 0; i < graph[course].size(); i++) {
				if (!visited[graph[course][i]])
					q.push(graph[course][i]);
				else
					return true;
			}
		}
		return false;
	}
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		graph.resize(numCourses);
		for (int i = 0; i < prerequisites.size(); i++)
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		visited.resize(numCourses,false);
		for (int i = 0; i < graph.size(); i++) {
			if (!visited[i]) {
				for (int j = 0; j < visited.size(); j++)
					visited[j] = false;
				bool hasCircle = bfs(i);
				if (hasCircle)
					return false;
			}
		}
		return true;
	}
};