//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.
//
//Example 1 :
//
//	Input : root = [3, 1, 4, null, 2], k = 1
//	Output : 1
//	Example 2 :
//
//	Input : root = [5, 3, 6, 2, 4, null, null, 1], k = 3
//	Output : 3
//	Follow up :
//What if the BST is modified(insert / delete operations) often and you need to find the kth smallest frequently ? How would you optimize the kthSmallest routine ?
//


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
#include<list>
using namespace std;

class BestSolution {
	int result = 0;
	int current = 0;
	void find(TreeNode* root, int k) {
		if (root != nullptr) {
			find(root->left, k);
			current++;
			if (current > k)
				return;
			if (current == k) {
				result = root->val;
			}
			else {//current < k
				find(root->right, k);
			}
		}
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		find(root, k);
		return result;
	}
};

class Solution {
	list<int> l;
	void convert(TreeNode* root, list<int>::iterator base) {
		if (root != nullptr) {
			if (root->left != nullptr) {
				auto temp = base;
				l.insert(base, root->left->val);
				convert(root->left, --base);
				base = temp;
			}
			if (root->right != nullptr) {
				auto temp = base;
				l.insert(++base, root->right->val);
				convert(root->right, --base);
				base = temp;
			}
		}
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		if (root != nullptr) {
			l.push_back(root->val);
			convert(root, l.begin());
			auto i = l.begin();
			int j = 0;
			while (j<k - 1) {
				i++;
				j++;
			}
			return *i;

		}
		else {
			return -1;
		}
	}
};
class Solution2 {
	int result = 0;
	int current = 0;
	void find(TreeNode* root, int k) {
		if (root != nullptr) {
			kthSmallest(root->left, k);
			current++;
			if (current == k) {
				result = root->val;
			}
			else {
				kthSmallest(root->right, k);
			}
		}
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		find(root, k);
		return result;
	}
};

