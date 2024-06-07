#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	//前
	void preOrder(TreeNode *root, vector<int> &ret) {
		if(root == NULL)  return ; 
		ret.push_back(root->val);
		preOrder(root->left, ret);
		preOrder(root->right, ret);
	}

	//中
	void inOrder(TreeNode *root, vector<int> &ret) {
		if(root == NULL)  return ; 
		inOrder(root->left, ret);
		ret.push_back(root->val);
		inOrder(root->right, ret);
	}

	//后
	void postOrder(TreeNode *root, vector<int> &ret) {
		if(root == NULL)  return ; 
		postOrder(root->left, ret);
		postOrder(root->right, ret);
		ret.push_back(root->val);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		preOrder(root, ret);
		return ret;
    }
};

int main(void) {
	//Solution s;
	return 0; 
}
