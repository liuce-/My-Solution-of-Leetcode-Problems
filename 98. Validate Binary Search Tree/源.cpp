#include<array>
#include<utility>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
	pair<array<int, 2>, bool> isBST(TreeNode* root) {
		array<int, 2> leftRange;
		array<int, 2> rightRange;
		bool isLeft;
		bool isRight;
		int min = root->val;
		int max = root -> val;
		if (root->right != nullptr) {
			auto p = isBST(root->right);
			rightRange = p.first;
			isRight = p.second;
			if (!isRight || root->val >= rightRange[0])
				return make_pair(array<int,2>(), false);
			max = rightRange[1];
		}
		if (root->left != nullptr) {
			auto p = isBST(root->left);
			leftRange = p.first;
			isLeft = p.second;
			if (!isLeft || root->val <= leftRange[1])
				return make_pair(array<int, 2>(), false);
			min = leftRange[0];
		}
		if (root->left == nullptr&&root->right == nullptr)
			return make_pair(array<int,2>{ root->val, root->val }, true);
		return make_pair(array<int, 2>{ min,max }, true);

	}


public:
	bool isValidBST(TreeNode* root) {
		return root != nullptr ? isBST(root).second : true;
	}
};