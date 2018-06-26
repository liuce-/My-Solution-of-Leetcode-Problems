//
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]
#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<pair<TreeNode*, int>> cache;
		vector<vector<int>> ans;

		if (root != nullptr)
			cache.push(make_pair(root, 1));
		while (cache.size() != 0) {
			TreeNode* node = cache.front().first;
			int level = cache.front().second;
			cache.pop();
			if (level>ans.size())
				ans.push_back(vector<int>());

			ans[level-1].push_back(node->val);

			if (node->left != nullptr)
				cache.push(make_pair(node->left,level+1));
			if (node->right != nullptr)
				cache.push(make_pair(node->right,level+1));
		}
		return ans;
	}
};