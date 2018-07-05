//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//

#include<vector>
#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	vector<int> sortedList;
	int currentPos = 0;
public:
	void construct(TreeNode* root) {//can not use recursion on constructor
		if (root == nullptr)
			return;
		construct(root->left);
		sortedList.push_back(root->val);
		construct(root->right);

	}
	BSTIterator(TreeNode *root) {
		construct(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return currentPos < sortedList.size();
	}

	/** @return the next smallest number */
	int next() {
		return sortedList[currentPos++];
	}
};

int main() {
	TreeNode root(1);
	root.right = new TreeNode(2);
	BSTIterator i = BSTIterator(&root);
	while (i.hasNext()) cout << i.next();

}
/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/