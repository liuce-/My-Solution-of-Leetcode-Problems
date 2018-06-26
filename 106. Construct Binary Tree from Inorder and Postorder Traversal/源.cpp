//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9, 3, 15, 20, 7]
//postorder = [9, 15, 7, 20, 3]
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7

#include<vector>
#include<unordered_map>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	unordered_map<int, int> map;
	TreeNode* build(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int right) {//[inLeft,inRight];
		if (inLeft > inRight)
			return nullptr;
		TreeNode* root = new TreeNode(postorder[right]);
		int location = map[postorder[right]];
		root->left = build(inorder, inLeft, location - 1, postorder, right - (inRight - location) - 1);
		root->right = build(inorder, location + 1, inRight, postorder, right - 1);
		return root;
	}
public:
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		for (int i = 0; i < inorder.size(); i++)
			map[inorder[i]] = i;
		if (map.size() == 0)
			return nullptr;
		return build(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
	}
};