//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	5
//	/ \
//	4   8
//	/   / \
//	11  13  4
//	/ \ / \
//	7    2  5   1
//	Return:
//
//[
//	[5, 4, 11, 2],
//	[5, 8, 4, 5]
//]

#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	vector<vector<int>> result;
	bool isLeaf(TreeNode* root) {
		return root->left == nullptr && root->right == nullptr;
	}
	void path(vector<int>& prev, TreeNode* root, int sum) {
		if (root == nullptr)
			return;
		if (isLeaf(root)) {
			if (root->val == sum) {
				prev.push_back(sum);
				result.push_back(prev);
				prev.pop_back();
			}
			return;
		}
		prev.push_back(root->val);
		path(prev, root->left, sum - root->val);
		path(prev, root->right, sum - root->val);
		prev.pop_back;
		return;
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> prev;
		path(prev, root, sum);
		return result;
	}
};