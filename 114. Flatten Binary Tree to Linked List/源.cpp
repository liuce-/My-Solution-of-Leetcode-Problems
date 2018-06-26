//Given a binary tree, flatten it to a linked list in - place.
//
//For example, given the following tree :
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like :
//
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

 class Solution {
	 TreeNode* f(TreeNode* root) {
		 TreeNode* end=nullptr;
		 if (root->left==nullptr && root->right!=nullptr) {
			 end = f(root->right);
		 }
		 else if (root->left != nullptr&&root->right == nullptr) {
			 end = f(root->left);
			 root->right = root->left;
			 root->left = nullptr;
		 }
		 else {
			 end = f(root->left);

		 }

	 }
 public:
	 void flatten(TreeNode* root) {
		 if (root != nullptr)
			 f(root);
	 }
 };