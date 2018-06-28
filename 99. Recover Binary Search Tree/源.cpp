//Two elements of a binary search tree(BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Example 1:
//
//Input: [1, 3, null, null, 2]
//
//	1
//	/
//	3
//	\
//	2
//
//	Output: [3, 1, null, null, 2]
//
//	3
//	/
//	1
//	\
//	2
//	Example 2:
//
//   Input: [3, 1, 4, null, null, 2]
//
//	   3
//	   / \
//	   1   4
//	   /
//	   2
//
//	   Output: [2, 1, 4, null, null, 3]
//
//	   2
//	   / \
//	   1   4
//	   /
//	   3
//	   Follow up :
//
//		  A solution using O(n) space is pretty straight forward.
//			  Could you devise a constant space solution ?

#include<utility>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 //������������������Ľ��һ����һ���ź�������顣
 //����ĵط�һ����ǰһ�����ֱȺ�һ�����ִ��ʱ��
 //����һ�������δ���ĵط�:��һ�������ʱ��ǰ���Ԫ��ΪҪ��õ�ֵ���ڶ��������ʱ�򣬺����Ԫ��ΪҪ��õ�ֵ
 //https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
 class Solution {
	 TreeNode* firstElement;
	 TreeNode* secondElement;
	 TreeNode* prevElement = new TreeNode(INT_MIN);
	 void inorder(TreeNode* root) {
		 if (root == nullptr)
			 return;
		 inorder(root->left);
		 if (firstElement == nullptr && prevElement->val > root->val)
			 firstElement = prevElement;
		 if (firstElement != nullptr && prevElement->val > root->val)
			 secondElement = root;

		 prevElement = root;
		 inorder(root->right);
	 }
 public:
	 void recoverTree(TreeNode* root) {
		 inorder(root);
		 swap(firstElement->val, secondElement->val);
	 }
 };

 //Morris Traversal 
 //https://www.youtube.com/watch?v=wGXB9OWhPTg
 class Solution {
	 TreeNode* firstElement = nullptr;
	 TreeNode* secondElement = nullptr;
	 TreeNode* prevElement = new TreeNode(INT_MIN);
 public:
	 void recoverTree(TreeNode* root) {
		 TreeNode* current = root;
		 while (current != nullptr) {
			 if (current->left) {
				 TreeNode* predecessor = current->left;
				 while (predecessor->right != nullptr && predecessor->right != current) predecessor = predecessor->right;

				 if (predecessor->right == nullptr) {
					 predecessor->right = current;
					 current = current->left;
				 }
				 else {
					 predecessor->right = nullptr;
					 if (firstElement == nullptr && prevElement->val > current->val)
						 firstElement = prevElement;
					 if (firstElement != nullptr && prevElement->val > current->val)
						 secondElement = current;

					 prevElement = current;
					 current = current->right;			 
				 }
			 }
			 else {
				 if (firstElement == nullptr && prevElement->val > current->val)
					 firstElement = prevElement;
				 if (firstElement != nullptr && prevElement->val > current->val)
					 secondElement = current;

				 prevElement = current;
				 current = current->right;
			 }
		 }
		 swap(firstElement->val, secondElement->val);
	 }
 };