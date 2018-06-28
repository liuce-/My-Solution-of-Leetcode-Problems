//Morris Inorder Traversal
//https://www.youtube.com/watch?v=wGXB9OWhPTg
struct TreeNode
{
	TreeNode* left, *right;
	int val;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {};
};
#include<iostream>
using namespace std;
class solution {
public :
	void inorder(TreeNode * root) {
		TreeNode* current = root;

		while (current != nullptr) {
			if (current->left) {
				TreeNode* predecessor = current->left;
				while (predecessor->right != nullptr && predecessor->right != current)predecessor = predecessor->right;
				if (predecessor->right == nullptr) {
					predecessor->right = current;
					current = current->left;
				}
				else {
					predecessor->right = nullptr;
					cout << current->val << endl;
					current = current->left;
				}
			}
			else {
				cout << current->val<<endl;
				current = current->right;
			}
		}
	}
	void preorder(TreeNode* root) {
		TreeNode* current = root;

		while (current != nullptr) {
			if (current->left) {
				TreeNode* predecessor = current->left;
				while (predecessor->right != nullptr && predecessor->right != current) predecessor = predecessor->right;
				
				if (predecessor->right == nullptr) {
					predecessor->right = current;
					cout << current->val << endl;
					current = current->left;
				}
				else {
					current = current->right;
					predecessor->right = nullptr;
				}
			}
			else {
				cout << current->val << endl;
				current = current->right;
			}
		}
	}

};

