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
		if(root == NULL) return;
		st.push(root);

		while(!st.empty()) {
			root = st.top();

			if(root != NULL) {
				st.pop();
				if(root->right != NULL) st.push(root->right);
				if(root->left != NULL)  st.push(root->left);
				st.push(root);
				st.push(NULL);	//标记
			}else{
				//弹出来的是NULL,标记，说明是中间节点
				//直接打印就好了
				st.pop();
				root = st.top();
				st.pop();
				ret.push_back(root->val);
			}

		}
	}

	//中，统一标记法
	void inOrder(TreeNode *root, vector<int> &ret) {
		stack<TreeNode *> st;
		if(root == NULL) return;
		st.push(root);

		while(!st.empty()) {
			root = st.top();
			
			if(root != NULL) {
				st.pop();		//提前弹出来，防止重复使用

				/*这里因为是一口气放进去
				  包括中间节点，而且还是栈,
				  在打印的时候要反着打印，所以直接反着放
				 */
				if(root->right != NULL) st.push(root->right);
				st.push(root);
				st.push(NULL);	//标记
				if(root->left != NULL)  st.push(root->left);
			}
			else{
				//弹出来的是NULL,标记，说明是中间节点
				//直接打印就好了
				st.pop();
				root = st.top();
				st.pop();
				ret.push_back(root->val);
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

			if(root != NULL) {
				st.pop();		//提前弹出来，防止重复使用

				/*这里因为是一口气放进去
				  包括中间节点，而且还是栈,
				  在打印的时候要反着打印，所以直接反着放
				  */
				st.push(root);
				st.push(NULL);	//标记
				if(root->right != NULL) st.push(root->right);
				if(root->left != NULL)  st.push(root->left);
			}
			else{
				//弹出来的是NULL,标记，说明是中间节点
				//直接打印就好了
				st.pop();
				root = st.top();
				st.pop();
				ret.push_back(root->val);
			}
		}
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
