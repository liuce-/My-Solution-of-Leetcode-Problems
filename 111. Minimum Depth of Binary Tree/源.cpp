//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//	return its minimum depth = 2.
//
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//ÏÝÚå£ºroot->left==nullptr, root->right!=nullptrÄÇÃ´depth(root)=depth(root->right)
class Solution {
public:
	int minDepth(TreeNode* root) {
		return root == nullptr ? 0 : root->left == nullptr ? 1 + minDepth(root->right) : root->right == nullptr ? 1 + minDepth(root->left) : 1 + min(minDepth(root->left), minDepth(root->right));
	}
};