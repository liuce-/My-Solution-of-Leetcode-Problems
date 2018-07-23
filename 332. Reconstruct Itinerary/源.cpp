//Given a list of airline tickets represented by pairs of departure and arrival airports[from, to], reconstruct the itinerary in order.All of the tickets belong to a man who departs from JFK.Thus, the itinerary must begin with JFK.
//
//Note:
//
//If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.For example, the itinerary["JFK", "LGA"] has a smaller lexical order than["JFK", "LGB"].
//All airports are represented by three capital letters(IATA code).
//You may assume all tickets form at least one valid itinerary.
//Example 1 :
//
//	Input : tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//	Output : ["JFK", "MUC", "LHR", "SFO", "SJC"]
//	Example 2 :
//
//	Input : tickets = [["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
//	Output : ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
//	Explanation : Another possible reconstruction is["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"].But it is larger in lexical order.
#pragma comment(linker, "/STACK:1024000000,1024000000")


#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;
class Solution {
	list<string> itineray;
	unordered_map<string, list<string>> map;
	bool buildItinerary(string& airport) {
		if (map.size() == 0)
			return true;
		auto route = map.find(airport);
		if (route == map.end())
			return false;
		int index = 0;
		list<string>& nextAirportList = route->second;
		for (auto i = nextAirportList.begin(); i != nextAirportList.end(); ) {
			string nextStop = *i;
			itineray.push_back(nextStop);
			//erase i
			list<string>::iterator tmp = i++;
			nextAirportList.erase(tmp);
			if (nextAirportList.size() == 0)
				map.erase(route);

			if (buildItinerary(nextStop)) {
				return true;
			}
			else {
				if (map.find(airport) == map.end())
					map[airport].push_back(nextStop);
				else
					nextAirportList.insert(i, nextStop);
				itineray.pop_back();
			}

		}
		return false;
	}
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		for (int i = 0; i < tickets.size(); i++) 
			map[tickets[i].first].push_back(tickets[i].second);
		for (auto i = map.begin(); i != map.end(); i++)
			i->second.sort(less<string>());

		string airport = "JFK";
		itineray.push_back(airport);
		buildItinerary(airport);
		return vector<string>(itineray.begin(),itineray.end());
	}
};
int main() {
	Solution s;
	vector<pair<string, string>> testcase = { {"JFK","BIM"},{"BIM","JFK"} };
	auto res = s.findItinerary(testcase);
	return 0;
}
class Solution {
	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
	vector<string> result;
	void dfs(string vtex)
	{
		auto & edges = graph[vtex];
		while (!edges.empty())
		{
			string to_vtex = edges.top();
			edges.pop();
			dfs(to_vtex);
		}
		result.push_back(vtex);
	}
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		for (auto e : tickets)
			graph[e.first].push(e.second);
		dfs("JFK");
		reverse(result.begin(), result.end());
		return result;
	}
};

