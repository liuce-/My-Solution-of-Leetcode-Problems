#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include<unordered_set>

using namespace std;


vector<bool> visited;

void DFS(vector<vector<size_t>>& graph, size_t person,unordered_set<size_t>& ancestor) {
	for (size_t i = 0; i < graph[person].size(); i++) {
		if (!visited[graph[person][i]]) {
			visited[graph[person][i]] = true;
			ancestor.insert(graph[person][i]);
			DFS(graph, graph[person][i],ancestor);
		}
	}
}

bool shareAncestor(const vector<string> idPair, const vector<vector<string>>& parentChildPairs) {

	unordered_map<string, size_t> key;
	size_t count = 0;

	for (size_t i = 1; i < parentChildPairs.size(); i++) {//o(n)
		if (key.find(parentChildPairs[i][0]) == key.end())
			key.insert(make_pair(parentChildPairs[i][0], count++));
		if (key.find(parentChildPairs[i][1]) == key.end())
			key.insert(make_pair(parentChildPairs[i][1], count++));
	}

	//empty
	if (count == 0)
		return false;

	visited.resize(count, false);

	//Build the directed graph. The direction is from children to parents.
	vector<vector<size_t>> graph(count, vector<size_t>());
	for (size_t i = 1; i < parentChildPairs.size(); i++) {
		size_t parent = key.find(parentChildPairs[i][0])->second;
		size_t child = key.find(parentChildPairs[i][1])->second;
		graph[child].push_back(parent);
	}

	size_t person1 = key.find(idPair[0])->second;
	size_t person2 = key.find(idPair[1])->second;

	//If one of the two inputs is a root node, the result should always be false
	if (graph[person1].size() == 0 || graph[person2].size() == 0)
		return false;
	
	visited[person1] = true;
	unordered_set<size_t> ans1;
	unordered_set<size_t> ans2;

	DFS(graph, person1,ans1);
	for (size_t i = 0; i < visited.size(); i++)
		visited[i] = false;
	DFS(graph, person1, ans2);

	for (auto i=ans1.begin();i!=ans1.end();i++){
		if (ans2.find(*i) != ans2.end())
			return true;
	}
	return false;
};

int main() {
	string line;
	bool firstArg = true;
	vector<vector<string>> pairs;
	vector<string> firstPair;

	while (getline(cin, line)) {
		istringstream iss(line);
		vector<string> parts(istream_iterator<string>{iss}, istream_iterator<string>());
		if (firstArg) {
			firstArg = false;
			firstPair = parts;
		}
		else {
			pairs.push_back(parts);
		}
	}

	cout << (shareAncestor(firstPair, pairs) ? "true" : "false");
}



#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include<unordered_set>

using namespace std;


vector<bool> visited;

void DFS( vector<vector<size_t>>& graph, size_t person, unordered_set<size_t>& ancestor) {
	for (size_t i = 0; i < graph[person].size(); i++) {
		if (!visited[graph[person][i]]) {
			visited[graph[person][i]] = true;
			ancestor.insert(graph[person][i]);
			DFS(graph, graph[person][i], ancestor);
		}
	}
}
bool checkSharedAncestor(vector<vector<size_t>>& graph, size_t person, unordered_set<size_t>& ancestor) {
	for (size_t i = 0; i < graph[person].size(); i++) {
		if (!visited[graph[person][i]]) {
			visited[graph[person][i]] = true;
			if (ancestor.find(graph[person][i]) != ancestor.end())
				return true;
			bool res = checkSharedAncestor(graph, graph[person][i], ancestor);
			if (res)
				return true;
		}
	}
	return false;
}
bool shareAncestor(const vector<string> idPair, const vector<vector<string>>& parentChildPairs) {

	unordered_map<string, size_t> key;
	size_t count = 0;

	for (size_t i = 1; i < parentChildPairs.size(); i++) {//o(n)
		if (key.find(parentChildPairs[i][0]) == key.end())
			key.insert(make_pair(parentChildPairs[i][0], count++));
		if (key.find(parentChildPairs[i][1]) == key.end())
			key.insert(make_pair(parentChildPairs[i][1], count++));
	}

	//empty
	if (count == 0)
		return false;

	visited.resize(count, false);

	//Build the directed graph. The direction is from children to parents.
	vector<vector<size_t>> graph(count, vector<size_t>());
	for (size_t i = 1; i < parentChildPairs.size(); i++) {
		size_t parent = key.find(parentChildPairs[i][0])->second;
		size_t child = key.find(parentChildPairs[i][1])->second;
		graph[child].push_back(parent);
	}

	size_t person1 = key.find(idPair[0])->second;
	size_t person2 = key.find(idPair[1])->second;

	//If one of the two inputs is a root node, the result should always be false
	if (graph[person1].size() == 0 || graph[person2].size() == 0)
		return false;

	visited[person1] = true;
	unordered_set<size_t> ancestor;

	DFS(graph, person1, ancestor);
	for (size_t i = 0; i < visited.size(); i++)
		visited[i] = false;
	return checkSharedAncestor(graph, person2, ancestor);
};

int main() {
	string line;
	bool firstArg = true;
	vector<vector<string>> pairs;
	vector<string> firstPair;

	while (getline(cin, line)) {
		istringstream iss(line);
		vector<string> parts(istream_iterator<string>{iss}, istream_iterator<string>());
		if (firstArg) {
			firstArg = false;
			firstPair = parts;
		}
		else {
			pairs.push_back(parts);
		}
	}

	cout << (shareAncestor(firstPair, pairs) ? "true" : "false");
	system("pause");
}
