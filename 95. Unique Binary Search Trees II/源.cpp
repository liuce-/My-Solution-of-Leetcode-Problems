//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
//Example:
//
//Input: 3
//	Output :
//	[
//		[1, null, 3, 2],
//		[3, 2, null, 1],
//		[3, 1, null, null, 2],
//		[2, 1, 3],
//		[1, null, 2, null, 3]
//	]
//	   Explanation:
//				  The above output corresponds to the 5 unique BST's shown below:
//
//					  1         3     3      2      1
//					  \       /     /      / \      \
//					  3     2     1      1   3      2
//					  /     /       \                 \
//					  2     1         2                 3

#include<vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	vector<TreeNode*> bst(int min, int max) {
		vector<TreeNode*> ans;
		if (min > max)
			ans.push_back(nullptr);
		else
			for (int i = min; i <= max; i++) {
				auto leftSubTree = bst(min, i-1);
				auto rightSubTree = bst(i + 1, max);
				for(auto lptr:leftSubTree)
					for (auto rptr : rightSubTree) {
						TreeNode* root = new TreeNode(i);
						root->left = lptr;
						root->right = rptr;
						ans.push_back(root);
					}

			}
		return ans;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return vector<TreeNode*>();
		return bst(1, n);
	}
};