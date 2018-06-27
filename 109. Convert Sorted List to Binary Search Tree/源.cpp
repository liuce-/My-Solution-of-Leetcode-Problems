//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted linked list : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//		 0
//		/ \
//	  - 3   9
//	  /   /
//   -10  5

#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	vector<int> list;
	TreeNode* convert(int left, int right) {//[left,right)
		if (left >= right)
			return nullptr;
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(list[mid]);
		root->left = convert(left, mid);
		root->right = convert(mid + 1, right);
		return root;
	}
public:
	TreeNode * sortedListToBST(ListNode* head) {
		while (head != nullptr) {
			list.push_back(head->val);
			head = head->next;
		}
		return convert(0, list.size());		
	}
};