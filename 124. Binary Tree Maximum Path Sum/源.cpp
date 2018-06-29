//Given a non - empty binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent - child connections.The path must contain at least one node and does not need to go through the root.
//
//Example 1:
//
//Input: [1, 2, 3]
//
//	1
//	/ \
//	2   3
//
//	Output: 6
//	Example 2 :
//
//	Input : [-10, 9, 20, null, null, 15, 7]
//
//	- 10
//	/ \
//	9  20
//	/ \
//	15   7
//
//	Output: 42
#include<vector>
#include<algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	int ans = INT_MIN;
	int maxPath(TreeNode* root) {
		if (root == nullptr)
			return INT_MIN;
		int leftMax = maxPath(root->left);
		int rightMax = maxPath(root->right);
		int leftMaxWithRoot = leftMax==INT_MIN? root->val:leftMax+ root->val;
		int rightMaxWithRoot = rightMax==INT_MIN? root->val :rightMax + root->val;
		int maxWithRoot = (leftMax == INT_MIN ? 0 : leftMax) + (rightMax == INT_MIN ? 0 : rightMax) + root->val;
		
		int a[6] = { leftMax,rightMax,leftMaxWithRoot,rightMaxWithRoot,maxWithRoot,root->val };
		for (int i = 0; i < 6; i++)
			ans = max(ans, a[i]);
		return max(leftMaxWithRoot, max(rightMaxWithRoot, root->val));
	}
public:
	int maxPathSum(TreeNode* root) {
		maxPath(root);
		return ans;
	}
};


class Solution {
	int ans = INT_MIN;
	int maxPath(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int leftMax = max(0,maxPath(root->left));
		int rightMax = max(0, maxPath(root->right));
		ans =max(ans, leftMax + rightMax + root->val);
		return max(leftMax,rightMax)+root->val;
	}
public:
	int maxPathSum(TreeNode* root) {
		maxPath(root);
		return ans;
	}
};