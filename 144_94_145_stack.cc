#include <iostream>
#include <algorithm>
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
		stack<TreeNode *> st;
		st.push(root);

		while(!st.empty()) {
			root = st.top();
			ret.push_back(root->val);
			st.pop();	//用完了之后就弹出

			//先入右边的，再入左边的，因为要后进先出
			if(root->right != NULL) st.push(root->right);
			if(root->left != NULL) st.push(root->left);
		}
	}

	//中
	void inOrder(TreeNode *root, vector<int> &ret) {
		TreeNode * cur = root;
		stack<TreeNode *> st;

		while(cur != NULL || !st.empty()) {
			//说明cur还没有走到叶子节点
			//继续向左走
			if(cur != NULL) {
				st.push(cur);
				cur = cur->left;
			}else {
				//走到头了,先把最后一个左元素的val(中)打出来，再向右走
				//能到这里的说明左边已经走过了
				cur = st.top();
				st.pop();
				ret.push_back(cur->val);
				cur = cur->right;
			}
		}
	}

	//后
	void postOrder(TreeNode *root, vector<int> &ret) {
		stack<TreeNode *> st;
		if(root == NULL) return;
		st.push(root);

		while(!st.empty()) {
			root = st.top();
			ret.push_back(root->val);
			st.pop();

			if(root->left != NULL)  st.push(root->left);
			if(root->right != NULL) st.push(root->right);
		}

		reverse(ret.begin(), ret.end());
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
