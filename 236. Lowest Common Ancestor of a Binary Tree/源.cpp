//Given a binary tree, find the lowest common ancestor(LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia : ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).¡±
//
//Given the following binary search tree : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//
//_______3______
/// \
//___5__          ___1__
/// \ / \
//6      _2       0       8
/// \
//7   4
//Example 1:
//
//Input: root, p = 5, q = 1
//	Output : 3
//	Explanation : The LCA of of nodes 5 and 1 is 3.
//	Example 2 :
//
//	Input : root, p = 5, q = 4
//	Output : 5
//	Explanation : The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
//	according to the LCA definition.

#include<utility>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
	TreeNode* result = nullptr;
	pair<bool,bool> LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
			return make_pair(false, false);
		auto a = LCA(root->left, p, q);
		auto b = LCA(root->right, p, q);
		bool isPfound = a.first||b.first;
		bool iSQfound = a.second||b.second;
		if (root == p)
			isPfound = true;
		if (root == q)
			iSQfound = true;
		if (isPfound&&iSQfound&&result == nullptr) {
			result = root;
		}
		return make_pair(isPfound, iSQfound);
	}
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		LCA(root, p, q);
		return result;
	}
};