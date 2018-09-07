#include<queue>
#include<vector>
using namespace std;
class MST {
	class compare {
	public:
		bool operator()(pair<int, pair<int, int>>& key1, pair<int, pair<int, int>>&key2) {
			return greater<int>()(key1.first, key2.first);
		}
	};
public:

	vector<int> generate(vector<vector<pair<int,int>>>& graph, int root) {//<vertex,weight>
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, compare>  heap;//pair<int,pair<int,int>> means pair<weight,edge>
		vector<int> parent(graph.size(), -1);
		heap.push({ 0, {root, root} });
		while (1) {
			pair<int, int> nextEdge = { -1,-1 };
			while (heap.size() != 0) {
				auto top = heap.top();
				heap.pop();
				if (parent[top.second.second]==-1) {
					nextEdge = { top.second.first,top.second.second };
					break;
				}
			}
			if (nextEdge == make_pair(-1, -1))
				break;
			else {
				int nextV= nextEdge.second;
				parent[nextV] = nextEdge.first;
				for (int i = 0; i < graph[nextV].size(); i++) {
					if (parent[graph[nextV][i].first] == -1) {
						heap.push({ graph[nextV][i].second,{nextV,graph[nextV][i].first} });
					}
				}
			}
		}
		return parent;
	}
};
class UnionFind {
	vector<int> parent;
	vector<int> rank;
public:
	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int e) {
		while (e != parent[e]) {
			parent[e] = parent[parent[e]];
			e = parent[e];
		}
		return e;
	}
	void combine(int e1, int e2) {
		int parent1 = find(e1);
		int parent2 = find(e2);
		if (parent1 != parent2) {
			if (rank[parent1] < rank[parent2])
				parent[parent1] = parent2;
			else if (rank[parent1] > rank[parent2])
				parent[parent2] = parent1;
			else {
				parent[parent2] = parent[parent1];
				rank[parent1]++;
			}
		}
	}
	bool isConnected(int e1, int e2) {
		return find(e1) == find(e2);
	}
};
#include<list>
class MST_Krusal{
	class compare {
	public:
		bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
			if (a.first == b.first)
				return less<pair<int, int>>()(a.second, b.second);
			else
				return less<int>()(a.first, b.first);
		}
	};
public:
	vector<pair<int, int>> generateMST(vector<vector<pair<int, int>>> graph) {
		vector<pair<int, int>> mst;
		list<pair<int, pair<int, int>>> weightedEdges;
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				weightedEdges.push_back({graph[i][j].second,{ min(i,graph[i][j].first),max(i,graph[i][j].first) } });
			}
		}
		weightedEdges.sort(compare());
		UnionFind set(graph.size());
		for (auto i = weightedEdges.begin(); i != weightedEdges.end(); ++i,++i) {
			if (!set.isConnected(i->second.first, i->second.second)) {
				set.combine(i->second.first, i->second.second);
				mst.push_back({ i->second.first,i->second.second });
				
				if (mst.size() == graph.size() - 1)
					break;
			}
		}
		return mst;
	}
};
int main() {
	vector<vector<pair<int,int>>> weightedGraph{
	{{1,4},{7,8}},
	{{0,4},{7,11},{2,8}},
	{{1,8},{8,2},{5,4},{3,7}},
	{{2,7},{5,14},{4,9}},
	{{3,9},{5,10}},
	{{2,4},{3,14},{4,10},{6,2}},
	{{7,1},{8,6},{5,2}},
	{{0,8},{1,11},{8,7},{6,1}},
	{{2,2},{7,7},{6,6}}
	};
	vector<int> parent = MST().generate(weightedGraph, 0);
	vector<pair<int,int>> parent2 = MST_Krusal().generateMST(weightedGraph);
	return 0;
}
