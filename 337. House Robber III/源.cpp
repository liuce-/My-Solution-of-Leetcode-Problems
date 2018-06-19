//
//The thief has found himself a new place for his thievery again.There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house.After a tour, the smart thief realized that "all houses in this place forms a binary tree".It will automatically contact the police if two directly - linked houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//Example 1:
//3
/// \
//2   3
//\   \
//3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//Example 2:
//3
/// \
//4   5
/// \   \
//1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.

#include<vector>
#include<array>
#include<algorithm>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };



class Solution {
	array<int,2> findmax(TreeNode* root) {

		if (root == nullptr)
			return array<int, 2>{0, 0};

		array<int, 2> leftresult = findmax(root->left);
		array<int, 2> rightResult = findmax(root->right);

		int leavesResult = leftresult[0] + rightResult[0];
		int rootResult = max(root->val + leftresult[1] + rightResult[1], leavesResult);
		
		return array<int, 2>{rootResult, leavesResult};

	}
public:
	int rob(TreeNode* root) {
		return findmax(root)[0];

	}
};