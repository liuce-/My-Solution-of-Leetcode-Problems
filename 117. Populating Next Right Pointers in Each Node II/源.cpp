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
//Example :
//
//	Given the following binary tree,
//
//	1
//	/ \
//	2    3
//	/ \    \
//	4   5    7
//	After calling your function, the tree should look like :
//
//1->NULL
/// \
//2 -> 3->NULL
/// \    \
//4-> 5 -> 7->NULL




 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
 };

class Solution {
	
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		TreeLinkNode* next = root->next;
		while (next != nullptr && next->left == nullptr && next->right == nullptr)next = next->next;
		TreeLinkNode* sonNext = next == nullptr ? nullptr : next->left != nullptr ? next->left : next->right;
		if (root->right != nullptr) {
			root->right->next = sonNext;
			connect(root->right);
			if (root->left != nullptr) {
				root->left->next = root->right;
				connect(root->left);
			}

		}
		else if(root->left!=nullptr){
			root->left->next = sonNext;
			connect(root->left);
		}
	}
};