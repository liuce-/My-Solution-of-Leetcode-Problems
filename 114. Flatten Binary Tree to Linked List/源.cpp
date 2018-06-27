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
 //o(n) n=total nodes
 class Solution {
	 TreeNode* f(TreeNode* root) {
		 if (root == nullptr)
			 return nullptr;
		 TreeNode* leftEnd = f(root->left);
		 TreeNode* rightEnd = f(root->right);
		 if (leftEnd == nullptr&&rightEnd == nullptr)
			 return root;
		 else if (leftEnd != nullptr&&rightEnd == nullptr) {
			 root->right = root->left;
			 root->left = nullptr;
			 return leftEnd;
		 }
		 else if (leftEnd == nullptr&&rightEnd != nullptr)
			 return rightEnd;
		 else {//leftEnd!=nullptr && rightEnd!=nullptr
			 leftEnd->right = root->right;
			 root->right = root->left;
			 root->left = nullptr;
			 return rightEnd;
		 }

	 }
 public:
	 void flatten(TreeNode* root) {
		 f(root);
	 }
 };
 //source :https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
 //o(n) n=total nodes
 class Solution {
 public:
	 void flatten(TreeNode *root) {
		 TreeNode*now = root;
		 while (now)
		 {
			 if (now->left)
			 {
				 //Find current node's prenode that links to current node's right subtree
				 TreeNode* pre = now->left;
				 while (pre->right)
				 {
					 pre = pre->right;
				 }
				 pre->right = now->right;
				 //Use current node's left subtree to replace its right subtree(original right 
				 //subtree is already linked by current node's prenode
				 now->right = now->left;
				 now->left = nullptr;
			 }
			 now = now->right;
		 }
	 }
 };

