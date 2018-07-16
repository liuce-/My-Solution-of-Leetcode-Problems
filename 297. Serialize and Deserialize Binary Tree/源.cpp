//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree.There is no restriction on how your serialization / deserialization algorithm should work.You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//Example:
//
//You may serialize the following tree :
//
//1
/// \
//2   3
/// \
//4   5
//
//as "[1,2,3,null,null,4,5]"
//Clarification: The above format is the same as how LeetCode serializes a binary tree.You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//
//	Note : Do not use class member / global / static variables to store states.Your serialize and deserialize algorithms should be stateless.
//


#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Codec {
	 pair<unsigned long, TreeNode*> constructNode(string str) {
		 pair<unsigned long, TreeNode*> ans;
		 stringstream ss(str);
		 string tmp;
		 getline(ss, tmp, ' ');
		 ans.first = stoul(tmp);
		 
		 TreeNode* node = new TreeNode(0);
		 getline(ss, tmp, ' ');
		 node->val = stoi(tmp);
		 getline(ss, tmp, ' ');
		 node->left = (TreeNode*)stoul(tmp);
		 getline(ss, tmp, ' ');
		 node->right = (TreeNode*)stoul(tmp);
		 ans.second = node;
		 return ans;
	 }
	 void makeTree(TreeNode* root, unordered_map<unsigned long, TreeNode*>& nodeMap) {
		 if (root == nullptr)
			 return;
		 if (root->left != nullptr) {
			 root->left = nodeMap[reinterpret_cast<unsigned long>(root->left)];
			 makeTree(root->left, nodeMap);
		 }
		 if (root->right != nullptr) {
			 root->right = nodeMap[reinterpret_cast<unsigned long>(root->right)];
			 makeTree(root->right, nodeMap);
		 }
		 
	 }
 public:

	 // Encodes a tree to a single string.
	 string serialize(TreeNode* root) {
		 string res;
		 if (root != nullptr) {
			 res = to_string(reinterpret_cast<unsigned long>(root)) + " "
				 + to_string(root->val) + " " 
				 + to_string(reinterpret_cast<unsigned long>(root->left))+" "
				 + to_string(reinterpret_cast<unsigned long>(root->right))+";";
			 res += serialize(root->left) + serialize(root->right);
		 }
		 return res;
	 }

	 // Decodes your encoded data to tree.
	 TreeNode* deserialize(string data) {
		 unordered_map<unsigned long, TreeNode*> nodeMap;
		 stringstream stream(data);
		 string nodeStr;
		 TreeNode* root=nullptr;
		 while (getline(stream, nodeStr, ';')) {
			 nodeMap.insert(constructNode(nodeStr));
			 if (nodeMap.size() == 1)
				 root = nodeMap.begin()->second;
		 }
		 makeTree(root, nodeMap);
		 return root;
	 }
 };

 // Your Codec object will be instantiated and called as such:
 // Codec codec;
 // codec.deserialize(codec.serialize(root));

















 //Wrong attempt, There might be dupliates in the nodes' value. So the tree can not be recovered by the inorder&preorder
//class Codec {
//	string res;
//	void preorder(TreeNode* root) {
//		if (root != nullptr) {
//			res += to_string(root->val);
//			res += ";";
//			preorder(root->left);
//			preorder(root->right);
//		}
//	}
//	void inorder(TreeNode* root) {
//		if (root != nullptr) {
//			inorder(root->left);
//			res += to_string(root->val);
//			res += ";";
//			inorder(root->right);
//		}
//	}
//
//	TreeNode* construct(vector<int>& preOrder, vector<int>& inOrder) {
//		unordered_map<int, int> index;
//		for (int i = 0; i < inOrder.size(); i++) {
//			index[inOrder[i]] = i;
//		}
//	}
//public:
//
//	// Encodes a tree to a single string.
//	string serialize(TreeNode* root) {
//		res = "";
//		preorder(root);
//		inorder(root);
//		return res;
//	}
//
//	// Decodes your encoded data to tree.
//	TreeNode* deserialize(string data) {
//		vector<int> preOrder;
//		vector<int> inOrder;
//		stringstream s(data);
//		string value;
//		while (getline(s, value, ';')) 
//			preOrder.push_back(stoi(value));
//		if (preOrder.size() % 2 != 0)//data is corrupted
//			return nullptr;
//		inOrder = vector<int>(preOrder.begin() + preOrder.size() / 2, preOrder.end());
//		preOrder.resize(preOrder.size() / 2);
//		return construct(preOrder, inOrder);
//	}
//};

