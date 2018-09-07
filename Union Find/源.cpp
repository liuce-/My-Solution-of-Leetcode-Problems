#include<vector>
using namespace std;

//Union by rank, path compression
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
				parent[parent2] = parent1;
				rank[parent1]++;
			}
		}
	}
	bool isConnected(int e1, int e2) {
		return find(e1) == find(e2);
	}
};

//Union by size, no path compression
class UnionFind2 {
	vector<int> parent;
	vector<int> size;
public:
	UnionFind2(int n) {
		parent.resize(n);
		size.resize(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int e) {
		while (e != parent[e])
			e = parent[e];
		return e;
	}
	void combine(int e1, int e2) {
		int parent1 = find(e1);
		int parent2 = find(e2);
		if (parent1 != parent2) {
			if (size[parent1] < size[parent2]) {
				parent[parent1] = parent2;
				size[parent2] += size[parent1];
			}
			else if (size[parent1] > size[parent2]) {
				parent[parent2] = parent1;
				size[parent1] += size[parent2];
			}
			else {
				if (parent1 < parent2) {
					parent[parent2] = parent1;
					size[parent1] += size[parent2];
				}
				else {
					parent[parent1] = parent2;
					size[parent2] += size[parent1];
				}
			}
		}
	}
	bool isConnected(int e1, int e2) {
		return find(e1) == find(e2);
	}
};

//Union by height, no path compression
class UnionFind3 {
	vector<int> parent;
	vector<int> height;
public:
	UnionFind3(int n) {
		parent.resize(n);
		height.resize(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int e) {
		while (e != parent[e])
			e = parent[e];
		return e;
	}
	void combine(int e1, int e2) {
		int parent1 = find(e1);
		int parent2 = find(e2);
		if (parent1 != parent2) {
			if (height[parent1] < height[parent2]) {
				parent[parent1] = parent2;
			}
			else if (height[parent1] > height[parent2]) {
				parent[parent2] = parent1;
			}
			else {
				if (parent1 < parent2) {
					parent[parent2] = parent1;
					height[parent1] += 1;
				}
				else {
					parent[parent1] = parent2;
					height[parent2] += 1;
				}
			}
		}
	}
	bool isConnected(int e1, int e2) {
		return find(e1) == find(e2);
	}
};
//by size, with path compression
class UnionFind4 {
	vector<int> parent;
	vector<int> size;
public:
	UnionFind4(int n) {
		parent.resize(n);
		size.resize(n, 1);
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
			if (size[parent1] < size[parent2]) {
				parent[parent1] = parent2;
				size[parent2] += size[parent1];
			}
			else if (size[parent1] > size[parent2]) {
				parent[parent2] = parent1;
				size[parent1] += size[parent2];
			}
			else {
				if (parent1 < parent2) {
					parent[parent2] = parent1;
					size[parent1] += size[parent2];
				}
				else {
					parent[parent1] = parent2;
					size[parent2] += size[parent1];
				}
			}
		}
	}
	bool isConnected(int e1, int e2) {
		return find(e1) == find(e2);
	}
};
int main() {
	UnionFind2 uf2(13);
	uf2.combine(1, 2);
	uf2.combine(3, 4);
	uf2.combine(3, 5);
	uf2.combine(1, 7);
	uf2.combine(3, 12);
	uf2.combine(0, 9);
	uf2.combine(8, 10);
	uf2.combine(8, 9);
	uf2.combine(7, 4);
	uf2.combine(2, 9);
	UnionFind uf(13);
	uf.combine(1, 2);
	uf.combine(3, 4);
	uf.combine(3, 5);
	uf.combine(1, 7);
	uf.combine(3, 12);
	uf.combine(0, 9);
	uf.combine(8, 10);
	uf.combine(8, 9);
	uf.combine(7, 4);
	uf.combine(2, 9);
	UnionFind3 uf3(13);
	uf3.combine(1, 2);
	uf3.combine(3, 4);
	uf3.combine(3, 5);
	uf3.combine(1, 7);
	uf3.combine(3, 12);
	uf3.combine(0, 9);
	uf3.combine(8, 10);
	uf3.combine(8, 9);
	uf3.combine(7, 4);
	uf3.combine(2, 9);
	UnionFind4 uf4(13);
	uf4.combine(1, 2);
	uf4.combine(3, 4);
	uf4.combine(3, 5);
	uf4.combine(1, 7);
	uf4.combine(3, 12);
	uf4.combine(0, 9);
	uf4.combine(8, 10);
	uf4.combine(8, 9);
	uf4.combine(7, 4);
	uf4.combine(2, 9);

	return 0;

}