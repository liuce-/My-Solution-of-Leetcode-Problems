//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3, 9, 20, 15, 7]
//inorder = [9, 3, 15, 20, 7]
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7

#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	TreeNode* build(vector<int>& preorder, int  preLeft, vector<int>& inorder, int inLeft, int inRight) {//[inleft, inRight]
		TreeNode* root = new TreeNode(preorder[preLeft]);
		if (inLeft==inRight)
			return root;
		if (inLeft > inRight)
			return nullptr;
		for (int i = inLeft; i <= inRight; i++) {
			if (inorder[i] == preorder[preLeft]) {
				root->left = build(preorder, preLeft + 1, inorder, inLeft, i - 1);
				root->right = build(preorder, preLeft + i - inLeft+1, inorder, i + 1, inRight);
				break;
			}
		}
		return root;
		
	}
public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return nullptr;
		return build(preorder, 0, inorder, 0, inorder.size() - 1);
	}
};