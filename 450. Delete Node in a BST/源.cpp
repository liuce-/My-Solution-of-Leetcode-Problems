//Given a root node reference of a BST and a key, delete the node with the given key in the BST.Return the root node reference(possibly updated) of the BST.
//
//Basically, the deletion can be divided into two stages :
//
//Search for a node to remove.
//If the node is found, delete the node.
//Note : Time complexity should be O(height of tree).
//
//	Example :
//
//	root = [5, 3, 6, 2, 4, null, 7]
//	key = 3
//
//	5
//	/ \
//	3   6
//	/ \   \
//	2   4   7
//
//	Given key to delete is 3. So we find the node with value 3 and delete it.
//
//	One valid answer is[5, 4, 6, 2, null, null, 7], shown in the following BST.
//
//	5
//	/ \
//	4   6
//	/ \
//	2       7
//
//	Another valid answer is[5, 2, 6, null, 4, null, 7].
//
//	5
//	/ \
//	2   6
//	\   \
//	4   7

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
	TreeNode* fatherOfNodeToDelete=nullptr;
	bool isLeftSon = true;
	TreeNode* find(TreeNode* root, int key) {
		if (root != nullptr) {
			if (root->val == key)
				return root;
			else {
				TreeNode* i = nullptr;
				if (root->val < key) {
					i = find(root->right, key);
				}
				else {
					i = find(root->left, key);
				}
				if (i != nullptr) {
					fatherOfNodeToDelete = fatherOfNodeToDelete == nullptr ? root : fatherOfNodeToDelete;
					return i;
				}
				else
					return nullptr;
			}
				
		}
		return nullptr;		
	}
public:
	TreeNode * deleteNode(TreeNode* root, int key) {
		TreeNode* nodeToDelete = find(root, key);
		if (nodeToDelete != nullptr ) {
			if (fatherOfNodeToDelete != nullptr) {//Ҫɾ���Ľڵ㲻�Ǹ��ڵ�
				if (fatherOfNodeToDelete->left == nodeToDelete)
					isLeftSon = true;
				else
					isLeftSon = false;
			}
			if (nodeToDelete->left == nullptr && nodeToDelete->right != nullptr) {//���ҽڵ�û����ڵ�
				if (fatherOfNodeToDelete != nullptr) {
					if (isLeftSon)
						fatherOfNodeToDelete->left = nodeToDelete->right;
					else
						fatherOfNodeToDelete->right = nodeToDelete->right;
				}
				else {
					root = nodeToDelete->right;
				}
				delete nodeToDelete;
				return root;
			}
			else if (nodeToDelete->right == nullptr&&nodeToDelete->left != nullptr) {//����ڵ�û���ҽڵ�
				if (fatherOfNodeToDelete != nullptr) {
					if (isLeftSon)
						fatherOfNodeToDelete->left = nodeToDelete->left;
					else
						fatherOfNodeToDelete->right = nodeToDelete->left;
				}
				else {
					root = nodeToDelete->left;
				}
				delete nodeToDelete;
				return root;
			}
			else if (nodeToDelete->left == nullptr&&nodeToDelete->right == nullptr) {//û����ڵ���ҽڵ�
				if (fatherOfNodeToDelete != nullptr) {
					if (isLeftSon)
						fatherOfNodeToDelete->left = nullptr;
					else
						fatherOfNodeToDelete->right = nullptr;
				}
				if (nodeToDelete == root)
					root = nullptr;
				delete nodeToDelete;
				return root;
			}
			else {//�����ӽڵ�
				TreeNode* replace = nullptr;
				TreeNode* fatherOfReplace = nodeToDelete;
				replace = nodeToDelete->left;
				while (replace->right != nullptr) { fatherOfReplace = replace; replace = replace->right; }//�������������ֵ���������		

				//ȡ��Ҫ�滻�Ľڵ�
				TreeNode* sonOfReplace = nullptr;
				sonOfReplace= replace->left == nullptr ? (replace->right == nullptr ? nullptr : replace->right) : replace->left;
				if (fatherOfReplace->left == replace)
					fatherOfReplace->left = sonOfReplace;
				else
					fatherOfReplace->right = sonOfReplace;
				//
				replace->left = nodeToDelete->left;
				replace->right = nodeToDelete->right;

				if (fatherOfNodeToDelete != nullptr) {
					if (isLeftSon)
						fatherOfNodeToDelete->left = replace;
					else
						fatherOfNodeToDelete->right = replace;
				}
				else {
					root = replace;
				}
				delete nodeToDelete;
			
			}
		}
			return root;
		
	}
};

class Solution2 {
public:
	TreeNode * deleteNode(TreeNode* root, int key) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->val > key) {
			root->left = deleteNode(root->left, key);
			return root;
		}
		if (root->val < key) {
			root->right = deleteNode(root->right, key);
			return root;
		}
		if (root->val == key) {//�ҵ�
			if (root->left == nullptr && root->right == nullptr) {//û���ӽڵ�
				delete root;
				root = nullptr;
			}
			else if (root->left == nullptr && root->right != nullptr) {//���ҽڵ�
				TreeNode* newRoot = root->right;
				delete root;
				root = newRoot;
			}
			else if (root->left != nullptr&&root->right == nullptr) {
				TreeNode* newRoot = root->left;
				delete root;
				root = newRoot;
			}
			else {
				TreeNode* replace = root->left;
				TreeNode* fatherOfReplace = root;
				while (replace->right != nullptr) {
					fatherOfReplace = replace;
					replace = replace->right;
				}
				root->val = replace->val;
				if(fatherOfReplace->right==replace)
					fatherOfReplace->right = replace->left;
				else
					fatherOfReplace->left= replace->left;
				

				delete replace;

			}
			return root;
		}
	}
};
int main() {
	Solution2 s;
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(7);
	TreeNode* temp = s.deleteNode(root,3);
	return 0;
}
