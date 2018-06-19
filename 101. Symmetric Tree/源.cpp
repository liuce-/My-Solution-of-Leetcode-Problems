//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following[1, 2, 2, null, 3, null, 3] is not:
//1
/// \
//2   2
//\   \
//3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.


#include<deque>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		deque<TreeNode*> q;
		if (root == nullptr)
			return true;
		q.push_back(root->left);
		q.push_back(root->right);
		while (q.size() != 0) {
			auto i = q.begin();
			auto j = q.end() - 1;
			if (q.size() % 2 != 0)
				return false;
			while (i != j + 1) {
				if ((*i) == nullptr || (*j) == nullptr) {
					if ((*i) != (*j))
						return false;
				}
				else if ((*i)->val != (*j)->val) {
					return false;
				}
				i++;
				j--;
			}
			i = q.begin();
			j = q.end() - 1;
			while (i != j + 1) {
				if ((*i) != nullptr) {
					q.push_back((*i)->left);
					q.push_back((*i)->right);
				}
				q.erase(i++);
			}
		}
		return true;
	}
};