//Given a binary tree, return the postorder traversal of its nodes' values.
//
//Example:
//
//Input: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//	Output: [3, 2, 1]
//	Follow up : Recursive solution is trivial, could you do it iteratively ?
//

#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	vector<int> res;
	void postOrder(TreeNode* root) {
		if (root) {
			postOrder(root->left);
			postOrder(root->right);
			res.push_back(root->val);
		}
	}
public:
	vector<int> postorderTraversal(TreeNode* root) {
		postOrder(root);
		return res;
	}
};


#include<stack>
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		stack<int> st2;
		vector<int> ans;
		if (!root)return ans;
		st.push(root);
		while (!st.empty())
		{
			TreeNode * tp = st.top();
			st.pop();
			st2.push(tp->val);
			if (tp->left)st.push(tp->left);
			if (tp->right)st.push(tp->right);
		}
		while (!st2.empty())
		{
			ans.push_back(st2.top());
			st2.pop();
		}
		return ans;


	}
};

