#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		vector<int> tmp;
		queue<TreeNode *> q;

		if(root == NULL) return ret;

		//我们这里还是直接把NULL作为标记
		//表示这一层的最后一个
		q.push(root);
		q.push(NULL);

		while(!q.empty()) {
			root = q.front();

			if(root == NULL) {
				//push这一层结果，清除tmp
				ret.push_back(tmp);
				tmp.erase(tmp.begin(), tmp.end());

				//把自己的标记弹出
				q.pop();
				if(q.empty()) break;
				//给下一层打结束标记
				q.push(NULL);	
			} 
			else {
				q.pop();
				tmp.push_back(root->val);
				if(root->left != NULL) q.push(root->left);
				if(root->right != NULL) q.push(root->right);
			}
		}
		return ret;
    }
};

int main(void) {
	return 0;
}
