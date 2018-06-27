//Given a binary tree
//
//struct TreeLinkNode {
//	TreeLinkNode *left;
//	TreeLinkNode *right;
//	TreeLinkNode *next;
//}
//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//Example :
//
//	Given the following perfect binary tree,
//
//	1
//	/ \
//	2    3
//	/ \ / \
//	4  5  6  7
//	After calling your function, the tree should look like :
//
//			1->NULL
//			/ \
//			2 -> 3->NULL
//			/ \ / \
//			4->5->6->7->NULL


 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
 };
 //o(1) space
class Solution {
	void convert(TreeLinkNode* root, TreeLinkNode* brother) {
		if (root == nullptr)
			return;
		root->next = brother;
		convert(root->left, root->right);
		if (brother == nullptr)
			convert(root->right, nullptr);
		else 
			convert(root->right, brother->left);
		
	}
public:
	void connect(TreeLinkNode *root) {
		convert(root, nullptr);
	}
};

//o(1) space
//
class Solution2 {
public:
	void connect(TreeLinkNode *root) {
		if (root ==nullptr ||root->left == nullptr)
			return;
		TreeLinkNode* brother = root->next;
		if (brother)
			root->right->next = brother->left;
		root->left->next = root->right;
		connect(root->right);
		connect(root->left);
		
	}
};