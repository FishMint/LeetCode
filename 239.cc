#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> ret;
		int i;

		/* dq里面是降序的 */
		//第一个K
		for(i = 0; i < k; i++) {
			//不是空的，就看看插入是不是降序
			//不是就从后面弹出
			while(!dq.empty() && dq.back() < nums[i]) {
				dq.pop_back();
			}
			dq.push_back(nums[i]);
		}
		ret.push_back(dq.front());

		//后续滑动
		for(; i < nums.size(); i++) {
			//这里主要是这个判断，
			//判断是不是要划出去的那个元素
			if(!dq.empty() && dq.front() == nums[i - k]) {
				dq.pop_front();
			}

			while(!dq.empty() && dq.back() < nums[i]) {
				dq.pop_back();
			}
			dq.push_back(nums[i]);
			ret.push_back(dq.front());
		}

		return ret;
    }
};

int main(void) {

	return 0;
}
