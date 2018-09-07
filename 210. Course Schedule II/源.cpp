//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
//
//There may be multiple correct orders, you just need to return one of them.If it is impossible to finish all courses, return an empty array.
//
//Example 1:
//
//Input: 2, [[1, 0]]
//	Output : [0, 1]
//	Explanation : There are a total of 2 courses to take.To take course 1 you should have finished
//	course 0. So the correct course order is[0, 1] .
//	Example 2 :
//
//	Input : 4, [[1, 0], [2, 0], [3, 1], [3, 2]]
//	Output : [0, 1, 2, 3] or [0, 2, 1, 3]
//	Explanation : There are a total of 4 courses to take.To take course 3 you should have finished both
//	courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
//	So one correct course order is[0, 1, 2, 3].Another correct ordering is[0, 2, 1, 3] .
//	Note :
//
//	The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.
//	You may assume that there are no duplicate edges in the input prerequisites.
#include<vector>
#include<list>
#include<utility>
using namespace std;
class Solution {
	enum color{white,gray,black};
	list<int> result;
	vector<list<int>> graph;
	vector<int> visited;
	bool topologicalSort(int source) {// topological sort and circle detected
		visited[source] = gray;
		for (auto i = graph[source].begin(); i != graph[source].end();i++) {
			if (visited[*i] == gray) {//cicle detected, clear all data and return false
				result.clear();
				return false;
			}
			if (visited[*i] == white) {
				if (!topologicalSort(*i))
					return false;
			}
		}
		visited[source] = black;
		result.push_front(source);
		return true;
	}
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		graph.resize(numCourses);
		visited.resize(numCourses, false);
		for (int i = 0; i < prerequisites.size(); i++)
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		for (int i = 0; i < graph.size(); i++) {
			if (!visited[i]) {
				if (!topologicalSort(i)) 
					break;
			}
		}
		return vector<int>(result.begin(),result.end());
	}
};