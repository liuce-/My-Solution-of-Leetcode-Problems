//Invert a binary tree.
//
//Example:
//
//Input:
//
//4
/// \
//2     7
/// \ / \
//1   3 6   9
//Output:
//
//4
/// \
//7     2
/// \ / \
//9   6 3   1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
	TreeNode * invertTree(TreeNode* root) {
		if (root != nullptr) {
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
			invertTree(root->left);
			invertTree(root->right);
		}
			
		return root;
	}
};