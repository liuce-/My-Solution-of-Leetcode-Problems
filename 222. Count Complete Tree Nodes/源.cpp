#include<list>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

 //TIme limit exceeded
class Solution {
public:

	void generateTestcase(TreeNode* testcase, int x, int target) {
		static int i = 1;
		if (x >= target)
			return;
		else {
			testcase->left = new TreeNode(i++);
			testcase->right = new TreeNode(i++);
			generateTestcase(testcase->left, x + 1, target);
			generateTestcase(testcase->right, x + 1, target);
		}
	}

	int countNodes(TreeNode* root) {
		list<TreeNode*> q;
		q.push_back(root);
		auto i = q.begin();
		int result = 0;
		while ((*i) != nullptr) {
			q.push_back((*i)->left);
			q.push_back((*i)->right);
			result++;
			i++;
		}
		return result;
	}
};

class Solution2 {
	static vector<int> data ;
public:
	int static getPow(int exp);

	int countNodes(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int leftHeight = 1;
		TreeNode* i = root->left;
		while (i != nullptr) {
			leftHeight++;
			i = i->left;
		}
		int rightHeight = 1;
		i = root->right;
		while (i != nullptr) {
			rightHeight++;
			i = i->right;
		}

		if (leftHeight == rightHeight) {
			//return (1 << leftHeight) - 1;¸ü¿ì
			return Solution2::getPow(leftHeight)-1;
		}
		else {
			return countNodes(root->left) + countNodes(root->right) + 1;
		}

	}
};
vector<int> Solution2::data = { 1 };

int Solution2::getPow(int exp) {
	int size = data.size();
	if (exp >= size) {
		data.resize(exp + 1);
		for (int i = size; i<exp + 1; i++) {
			data[i] = data[i - 1] * 2;
		}
	}
	return data[exp];
}
int main() {
	Solution s;
	TreeNode * testcase = new TreeNode(0);
	s.generateTestcase(testcase, 0, 10);
	cout<<s.countNodes(testcase);
	return 0;
}

